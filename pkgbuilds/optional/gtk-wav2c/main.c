/**
 * Original Projects:
 * GTK-C: https://prognotes.net/2019/12/gtk-template-files-with-widget-structure/
 * WAV2C: https://github.com/folkien/wav2c/blob/master/main.c
 */

/**
 * @file main.c
 * @brief Main source.
 *
 * @addtogroup wav2c
 * @{
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

#include <gtk/gtk.h>

typedef struct {
    uint32_t ChunkID;
    uint32_t ChunkSize;
    uint32_t Format;

    /* fmt */
    uint32_t Subchunk1ID;
    uint32_t Subchunk1Size;
    uint16_t AudioFormat;
    uint16_t NumChannels;
    uint32_t SampleRate;
    uint32_t ByteRate;
    uint16_t BlockAlign;
    uint16_t BitsPerSample;

    /* data */
    uint32_t Subchunk2ID;
    uint32_t Subchunk2Size;
} sWavHeader;
//} __attribute__((packed)) sWavHeader;

static uint32_t numOfSamples = 0;
static int32_t lowLimit;
static int32_t highLimit;
static int16_t *leftChannel = NULL;
static int16_t *rightChannel = NULL;

static uint16_t DAC_max = 4096;
static uint16_t DAC_shift = 2048;

static uint16_t ConvertToDACValue(int16_t value){
    uint32_t tmp = ((value*DAC_max)/highLimit) + DAC_shift;
    return tmp;
}

static void swapEndiannes(uint32_t *value){
    uint32_t tmp = *value;
    *value =    (tmp >> 24) |
                (tmp << 24) |
                ((tmp >> 8) & 0x0000FF00) |
                ((tmp<<8) & 0x00FF0000);
}

void swapEndiannesS16(int16_t * value){
  uint32_t tmp = *value;
  *value =   ( tmp >> 8) | (tmp << 8);
}

static void printfU32String(uint32_t array){
    char text[5];
    text[0] = (array >> 24) & 0xFF;
    text[1] = (array >> 16) & 0xFF;
    text[2] = (array >> 8) & 0xFF;
    text[3] = array & 0xFF;
    text[4] = 0;
    printf(" %s.\n",text);
}

static void fprintfChannel(FILE *pFile , int16_t * array, uint32_t size){
  for (uint32_t i = 0; i<size; ++i){
    fprintf(pFile, "%d, // %d\n",ConvertToDACValue(array[i]), array[i]);
  }
}

void fprintfChannelMatlab(FILE *pFile , int16_t * array, uint32_t size){
  for (uint32_t i = 0; i<size; ++i){
    fprintf(pFile, "%d\n",array[i]);
  }
}

static void printfHeader(sWavHeader *header){
  printf("WAV HEADER.\n");
  printf("--------------------------------------.\n");
  printf("ChunkID : ");
  swapEndiannes(&header->ChunkID);
  printfU32String(header->ChunkID);
  printf("ChunkSize : %d.\n", header->ChunkSize);
  printf("Format : ");
  swapEndiannes(&header->Format);
  printfU32String(header->Format);
  
  /* fmt */
  printf("Subchunk1ID : ");
  swapEndiannes(&header->Subchunk1ID);
  printfU32String(header->Subchunk1ID);
  printf("Subchunk1Size : %d.\n", header->Subchunk1Size);
  if(header->AudioFormat == 1){
    printf("AudioFormat : PCM.\n");
  }
  else{
    printf("AudioFormat : Compression.\n");
  }

  printf("NumChannels : %d.\n", header->NumChannels);
  printf("SampleRate : %d.\n", header->SampleRate);
  printf("ByteRate : %d.\n", header->ByteRate);
  printf("BlockAlign : %d.\n", header->BlockAlign);
  printf("BitsPerSample : %d.\n", header->BitsPerSample);
  
  /* data */
  printf("Subchunk2ID : ");
  swapEndiannes(&header->Subchunk2ID);
  printfU32String(header->Subchunk2ID);
  printf("Subchunk2Size : %d.\n", header->Subchunk2Size);
  printf("--------------------------------------.\n");
}

static void readWavData(int fileId, sWavHeader * header){
  numOfSamples = header->Subchunk2Size / (header->NumChannels * header->BitsPerSample/8);
  
  switch (header->BitsPerSample) {
    case 8:
      lowLimit = -128;
      highLimit = 127;
      break;
    case 16:
      lowLimit = -32768;
      highLimit = 32767;
      break;
    case 32:
      lowLimit = -2147483648;
      highLimit = 2147483647;
      break;
  }

  leftChannel = malloc(sizeof(uint16_t) * numOfSamples);
  if (header->NumChannels > 1){
    rightChannel = malloc(sizeof(uint16_t) * numOfSamples);
  }

  /* read all music data */
  for (uint32_t i = 0; i<numOfSamples; ++i){
    read(fileId, &leftChannel[i], sizeof(uint16_t));
    // swapEndiannesS16(&leftChannel[i]);
    
    /* check if value was in range */
    if ((leftChannel[i] < lowLimit) || (leftChannel[i] > highLimit)){
      printf("**value out of range\n");
    }

    if(header->NumChannels > 1){
      read(fileId, &rightChannel[i], sizeof(uint16_t));
      // swapEndiannesS16(&rightChannel[i]);

      /* check if value was in range */
      if ((rightChannel[i] < lowLimit) || (rightChannel[i] > highLimit)){
        printf("**value out of range\n");
      }
    }
  }
}

static void writeAsC(char *dirname, int16_t *leftChannel, int16_t *rightChannel,  sWavHeader *header){
  FILE * pFile;
  char outname[512];
  char fname[] = "wavarray.c";

  sprintf(outname, "%s/%s",dirname,fname);
  pFile = fopen(outname,"w");

  /* header */
  fprintf(pFile, "#include <stdint.h>\n");
  fprintf(pFile, "#include <stdio.h>\n");
  fprintf(pFile, "const uint32_t audioSamplingFrequency = %d;\n",header->SampleRate);

  /* printf left Channel */
  fprintf(pFile, "const size_t leftChannelSize = %d;\n",numOfSamples);
  fprintf(pFile, "const uint16_t leftChannel[] = {\n");
  fprintfChannel(pFile, leftChannel, numOfSamples);
  fprintf(pFile, "};\n");

  if(header->NumChannels > 1){
    /* printf right Channel */
    fprintf(pFile, "uint16_t rightChannel[] = {\n");
    fprintfChannel(pFile, rightChannel, numOfSamples);
    fprintf(pFile, "};\n");
  }

  fclose(pFile);

  printf("C-outname: %s\n",outname);
}

void writeAsMatlab(char *dirname, int16_t *leftChannel, int16_t *rightChannel,  sWavHeader * header){
  FILE * pFile;
  char outname[512];
  char fname[] = "wavarray.m";

  sprintf(outname, "%s/%s",dirname,fname);
  pFile = fopen(outname,"w");

  /* printf left Channel */
  fprintf(pFile, "leftChannel = [");
  fprintfChannelMatlab(pFile, leftChannel, numOfSamples);
  fprintf(pFile, "];\n");

  if(header->NumChannels > 1)
  {
    /* printf right Channel */
    fprintf(pFile, "rightChannel = [");
    fprintfChannelMatlab(pFile, rightChannel, numOfSamples);
    fprintf(pFile, "];\n");
    fprintf(pFile, "plot(rightChannel);\n");
  }

  fprintf(pFile, "plot(leftChannel);\n");
  fprintf(pFile, "fs = %d;\n",header->SampleRate);
  fprintf(pFile, "scaleFactor = %d;\n",highLimit);

  fclose(pFile);

  printf("M-outname: %s\n",outname);
}

typedef struct {} app_widgets;

char wavName[512];
char outDir[512];
GtkWidget *btnFileChoose;

int main(int argc, char *argv[])
{
    GtkBuilder *builder;
    GtkWidget *window;
    app_widgets *widgets = g_slice_new(app_widgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("window_main.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder,NULL);

    btnFileChoose = GTK_WIDGET(gtk_builder_get_object(builder, "btnFileChoose"));

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    g_slice_free(app_widgets, widgets);

    return 0;
}

/*void dummy(GtkButton *button, app_widgets *app_wdgts){}*/

void on_btnConvert_clicked(){    
    sWavHeader wavHeader;

    if (strlen(wavName)==0){
        printf("Select a WAV File first\n");
        return;
    }
    
    printf("opening %s\n",wavName);
    int file = open(wavName, O_RDONLY);
    read(file, &wavHeader, sizeof(sWavHeader));
    printfHeader(&wavHeader);
    readWavData(file, &wavHeader);
    close(file);

    writeAsC(outDir,leftChannel, rightChannel, &wavHeader);
    writeAsMatlab(outDir,leftChannel, rightChannel, &wavHeader);
    printf("Completed\n");
}

void on_btnFileChoose_file_set(){
    sprintf(wavName,"%s",gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(btnFileChoose)));
    sprintf(outDir,"%s",gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(btnFileChoose)));
}

void on_window_main_destroy(){
    gtk_main_quit();
}

/** @} */
