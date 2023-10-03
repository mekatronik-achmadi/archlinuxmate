# Media Packages

## Official

### install graphic tools
inkscape imagemagick
mypaint gimp xsane-gimp

### install multimedia tools
steam openshot
frei0r-plugins
audacity faac sox

### install disk recovery tools
ddrescue ext4magic foremost testdisk

--------------------------------------------------------------------------------

## AUR

### install disk recovery tools
- https://aur.archlinux.org/packages/extundelete/

### install screencast tools
- https://aur.archlinux.org/packages/simplescreenrecorder/
- https://aur.archlinux.org/packages/key-mon/

### install youtube downloader
- https://aur.archlinux.org/packages/yt-dlp-git/

--------------------------------------------------------------------------------

## External

### install youtube programs
- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/youtube/
- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/youtubemusic/

--------------------------------------------------------------------------------

## Configurations

### configure steam

```sh
echo "Steam -> Settings -> Steam Play"
echo "Enable Steam Play for all"

echo "Choose Game -> Manage -> Properties"
echo "Compatibility -> Force use Steam Play"

echo "use Proton 4.11"
```

### configure audacity

```sh
echo "re-enabled headphone"
alsactl init
```

```
echo "
change 'sysdefault: Headphone Mic:0'
to 'sysdefault: Internal Mic:0'
"
```

### configure key-mon

```sh
key-mon --reset &
key-mon -s -m --decorated -t classic &
```

### configure youtube downloader

```sh
sudo ln -svf /usr/bin/yt-dlp /usr/bin/youtube-dl

echo "vid code -> https | avc1.4D401F 803k video only 720p"
echo "aud code -> https │ audio only opus 48k"
```

```sh
yt-dlp -F https://www.youtube.com/watch?v=xxxxxxxxxxx
yt-dlp -f <vid>+<aud> --merge-output-format mp4 https://www.youtube.com/watch?v=xxxxxxxxxxx
yt-dlp -f 136+251 --merge-output-format mp4 https://www.youtube.com/watch?v=xxxxxxxxxxx

yt-dlp -f 251 https://www.youtube.com/watch?v=xxxxxxxxxxx
ffmpeg -i videoname.webm -vn -ab 128k -ar 44100 -y videoname.mp3
rm -vf videoname.webm
```
