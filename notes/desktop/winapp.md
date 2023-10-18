# Windows Guidance

## Windows 10 Lite

- http://ghostspectre.the-ninja.jp/20H2.X64.htm
- https://tech-latest.com/ghost-spectre-windows-10-superlite-version/
- https://drive.google.com/file/d/1HX1jM0oqQ3v3WYWYfK6snkQejyOwbjOk/view
- https://drive.google.com/file/d/1qm7zoCl5zsrOdYEqg6r6pfiGss0BlcAp/view

## Wine Blocked Internet

### setup

```sh
sudo groupadd -fr winenoinet
sudo iptables -I OUTPUT 1 -m owner --gid-owner winenoinet -j DROP
sudo ip6tables -I OUTPUT 1 -m owner --gid-owner winenoinet -j DROP
sudo gpasswd -a username winenoinet
```

### usage

```sh
unset LD_PRELOAD
export WINEARCH=win32
sudo -g winenoinet LD_PRELOAD=  WINEPREFIX=~/WineDir/winefolder/ wine program.exe &> /dev/null
```

## Registry Files

### riched20.reg

```text
REGEDIT4

[HKEY_CURRENT_USER\Software\Wine\DllOverrides]
"riched20"="native,builtin"
```

### gaming.reg

```text
REGEDIT4

[HKEY_CURRENT_USER\Software\Wine\Direct3D]
"DirectDrawRenderer"="opengl"
"UseGLSL"="enabled"
"MaxVersionGL"=dword:00040005
```

### vdesktop.reg

```text
REGEDIT4

[HKEY_CURRENT_USER\Software\Wine\Explorer\Desktops]
@="1024x768"
```

### gtktheme.reg

```text
REGEDIT4

[HKEY_CURRENT_USER\Software\Wine]
"ThemeEngine"="GTK"

[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\ThemeManager]
"DllName"="C:\\windows\\Resources\\Themes\\light\\light.msstyles"
"ThemeActive"="1"
```

## Simulation Games

### Railworks-3

```sh
unset LD_PRELOAD
export WINEARCH=win32
export WINEPREFIX=~/WineDir/winerw
winetricks settings winxp
regedit gaming.reg
wine directx_*/DXSETUP.exe
```

```sh
cd Railworks/
sudo mount sr-r3ts12.iso /mnt
cd /mnt
wine Setup.exe

cd "$HOME/WineDir/winerw/drive_c/Program Files/RailSimulator.com/Railworks 3 Train Simulator 2012 Deluxe/"
cp -vf /mnt/SKIDROW/SKIDROW.ini ./
cp -vf /mnt/SKIDROW/RailWorks.exe ./
cp -vf /mnt/SKIDROW/Steamclient.dll ./
cp -vf /mnt/SKIDROW/LocalisedStrings.dll ./

wine RailWorks.exe
```

```sh
cd "$HOME/WineDir/winerw/drive_c/Program Files/RailSimulator.com/Railworks 3 Train Simulator 2012 Deluxe/"
LD_PRELOAD=  WINEPREFIX=~/WineDir/winezh/ wine RailWorks.exe &> /dev/null
```

## Real-Time Strategy Games

### Starcraft-BW

```sh
unset LD_PRELOAD
export WINEARCH=win32
export WINEPREFIX=~/WineDir/winebw
winetricks settings winxp
regedit gaming.reg
wine directx_*/DXSETUP.exe
```

```sh
cd StarCraft_BW/
mkdir -p StarcraftBroodwar/
bsdtar --strip-components=1 -xvf Starcraft_BroodWar.zip -C StarcraftBroodwar/
```

```sh
cd StarCraft_BW/StarcraftBroodwar/
LD_PRELOAD=  WINEPREFIX=~/WineDir/winebw/ wine StarCraft.exe &> /dev/null
```

### Starcraft-2

```sh
unset LD_PRELOAD
export WINEARCH=win32
export WINEPREFIX=~/WineDir/winesc
winetricks settings winxp
regedit gaming.reg
wine directx_*/DXSETUP.exe
```

```sh
cd StarCraft/
sudo mount rld-sciivoid.iso /mnt;cd /mnt
wine setup.exe

cp -rvf Crack/* "$HOME/.winesc/drive_c/Program Files/StarCraft_II/"
cd "~/WineDir/winesc/drive_c/Program Files/StarCraft_II/"
wine cmd /c "Run me first.bat"
chmod -Rvf u+w Battle.net/
```

```sh
cd "~/WineDir/winesc/drive_c/Program Files/StarCraft_II/"
LD_PRELOAD=  WINEPREFIX=~/WineDir/winesc/ wine "StarCraft II Offline.exe" &> /dev/null
```

```text
login: dlr@dr.com
```

### Warcraft-3

#### Patch 1.29

- https://piratebay.party/torrent/21842340/Warcraft_3_The_Frozen_Throne_v1.29_[Widescreen]

```sh
unset LD_PRELOAD
export WINEARCH=win32
export WINEPREFIX=~/WineDir/winewc
winetricks settings winxp
regedit gaming.reg
wine directx_*/DXSETUP.exe
```

```sh
cd Warcraft/
sudo mount WC3_v1.29.iso /mnt;cd /mnt
wine setup.exe
cd ~/WineDir/winewc/drive_c/Program\ Files/Warcraft\ 3/
LD_PRELOAD= wine "Warcraft III.exe" &> /dev/null
echo "RoC: N9UBI4-GRQS-TDV29O-QF8H-7SMKLM"
echo "TFT: WGMNX2-EGT7-8KD9EV-H6ZR-ZPH7PZ"
```

```sh
cd "$HOME/WineDir/winewc/drive_c/Program Files/Warcraft 3/"
LD_PRELOAD=  WINEPREFIX=~/WineDir/winewc/ wine "Warcraft III.exe" &> /dev/null
```

#### Patch 1.26 + Dota

- https://piratebay.party/torrent/11747394/Warcraft_III_RoC___TFT_v1.26_Complete_(__lots_of_LAN_maps)

```sh
unset LD_PRELOAD
export WINEARCH=win32
export WINEPREFIX=~/WineDir/winewc
winetricks settings winxp
regedit gaming.reg
wine directx_*/DXSETUP.exe
```

```sh
cd Warcraft/
yes | unrar x WC3_Dota.rar
cd ../
```

```sh
cd Warcraft/Warcraft*/
LD_PRELOAD=  WINEPREFIX=~/WineDir/winewc/ wine "Frozen Throne.exe" &> /dev/null
```

### Generals Zero Hour

- https://piratebay.party/torrent/6191936/Command_and_Conquer__Generals_1.8___Zero_Hour_1.04_Definitive_ed

```sh
unset LD_PRELOAD
export WINEARCH=win32
export WINEPREFIX=~/WineDir/winezh
winetricks settings winxp
regedit gaming.reg
wine directx_*/DXSETUP.exe
```

```text
# Zero Hour Keys
64UU-HJLH-PJCK-M7AK-KUE9
PDWW-HYA4-TPQD-T8KT-ZC3J
PBVM-6LAP-T942-ASVR-WZZ5
P57F-BDA8-TRC6-AAYF-NP55
P322-KQAF-TDUR-LHK4-X259
PCG8-ZPAK-TVH4-K4VM-NHZ6
P3HZ-VXA4-TFUQ-LX9N-PAJM
PHLU-C7AY-TABD-4FF6-46P2
PJRZ-T5AE-TC8J-M9EL-588L
PVGY-5JA7-TR8J-GEE8-KXRQ
PP6E-65AY-TTGU-RPQ3-VVGA (used in example below)
4EFF-YZNG-6AS4-3QJQ-44YG (Jimbus edition)
```

```sh
cd CnC_Generals/
#tar -xf setup.tar.gz
wine setup.exe

mkdir -p "$HOME/Documents/Command and Conquer Generals Data/"
mkdir -p "$HOME/Documents/Command And Conquer Generals Zero Hour Data/"

echo '
AntiAliasing = 1
BuildingOcclusion = no
DrawScrollAnchor =
DynamicLOD = yes
ExtraAnimations = no
GameSpyIPAddress = 127.0.0.2
Gamma = 50
HeatEffects = no
IPAddress = 127.0.0.2
IdealStaticGameLOD = High
LanguageFilter = false
MaxParticleCount = 100
MoveScrollAnchor = 0
MusicVolume = 79
Resolution = 1024 768
Retaliation = yes
SFX3DVolume = 79
SFXVolume = 71
ScrollFactor = 50
SendDelay = no
ShowSoftWaterEdge = no
ShowTrees = yes
StaticGameLOD = low
UseAlternateMouse = yes
UseCloudMap = no
UseDoubleClickAttackMove = yes
UseLightMap = no
UseShadowDecals = yes
UseShadowVolumes = no
VoiceVolume = 70
' | tee "$HOME/Documents/Command and Conquer Generals Data/Options.ini"

cp -vf "$HOME/Documents/Command and Conquer Generals Data/Options.ini" \
"$HOME/Documents/Command And Conquer Generals Zero Hour Data/"

regedit /D "HKEY_LOCAL_MACHINE\SOFTWARE\Electronic Arts\EA Games\Command and Conquer Generals Zero Hour\ergc"
echo 'REGEDIT4

[HKEY_LOCAL_MACHINE\SOFTWARE\Electronic Arts\EA Games\Command and Conquer Generals Zero Hour\ergc]
@="PP6E65AYTTGURPQ3VVGA"
' | tee generalkey.reg
regedit generalkey.reg

cd "$HOME/WineDir/winezh/drive_c/Program Files/CnCGenerals/"
wine ZeroHour/generals.exe
```

```sh
cd "$HOME/WineDir/winezh/drive_c/Program Files/CnCGenerals/ZeroHour/"
LD_PRELOAD=  WINEPREFIX=~/WineDir/winezh/ wine generals.exe &> /dev/null
```

### Red Alert 2

- https://piratebay.party/torrent/15966593/C_amp_C_Red_Alert_2___Yuri_s_Revenge_[Win10_Fixed]_-_V2

```sh
unset LD_PRELOAD
export WINEARCH=win32
export WINEPREFIX=~/WineDir/winera
winetricks settings winxp
regedit gaming.reg
wine directx_*/DXSETUP.exe
```

```sh
cd RedAlert/
unzip RA2_Yuri.zip

wget -c https://github.com/CnCNet/cnc-ddraw/releases/download/v4.4.7.0/cnc-ddraw.zip
cp -vf cnc-ddraw.zip RA2_Yuri/RA2/
cd RA2_Yuri/RA2/
yes | unzip cnc-ddraw.zip

echo '
REGEDIT4

[HKEY_CURRENT_USER\Software\Wine\DllOverrides]
"ddraw"="native,builtin"' | tee ddraw.reg
regedit ddraw.reg

cd ../
wineconsole run_me_first.bat
wineconsole launch_ra2.bat

# kill game if intro cant be stopped
killall game.exe
```

```sh
cd RA2_Yuri/
LD_PRELOAD=  WINEPREFIX=~/WineDir/winera/ wineconsole launch_ra2.bat &> /dev/null
```

- https://piratebay.party/torrent/9824606/Command_And_Conquer_Red_Alert_2

## Microsoft Office

### install MS-Office 2013

```sh
unset LD_PRELOAD
export WINEARCH=win32
export WINEPREFIX=~/WineDir/wine-office2013
winetricks msxml3 msxml4
winetricks msxml6 corefonts
winetricks settings winxp
wine DX_Display/directx/DXSETUP.exe
winetricks settings fontsmooth=bgr
regedit DX_Display/gaming.reg
regedit DX_Display/gtktheme.reg
regedit DX_Display/riched20.reg

LD_PRELOAD= wine setup.exe
```

---------------------------------------------------------

## Programming

### install Proteus 8.6

```sh
unset LD_PRELOAD
export WINEARCH=win32
export WINEPREFIX=~/WineDir/wineproteus
winetricks msxml3 msxml4
winetricks msxml6 corefonts
winetricks settings winxp
winetricks settings fontsmooth=bgr
regedit DX_Display/gaming.reg
regedit DX_Display/gtktheme.reg
wine DX_Display/directx/DXSETUP.exe
#winetricks vd=1366x720

LD_PRELOAD= wine Proteus_8.6_SP2_Pro.exe
```

### install Altium Designer 17.0

```sh
unset LD_PRELOAD
export WINEARCH=win32
export WINEPREFIX=~/WineDir/winealtium
winetricks mdac28 riched20 dotnet40 gdiplus
winetricks corefonts msxml3 msxml4 msxml6
winetricks settings win7
winetricks settings fontsmooth=bgr
regedit DX_Display/gaming.reg
regedit DX_Display/gtktheme.reg
regedit DX_Display/riched20.reg
wine DX_Display/directx/DXSETUP.exe
#winetricks vd=1366x720

sudo mount Altium_Designer_17_0_10.iso /mnt/;cd /mnt/
LD_PRELOAD= wine AltiumDesignerSetup_17_0_10.exe
```

#### Some useful Altium related URLs

- https://www.altium.com/documentation/altium-designer/exploring-altium-designer?version=17.0
- https://techdocs.altium.com/cn/display/ALEG/Altium+Designer+Summer+09+library+list
- https://github.com/ryankurte/altium-library
- https://github.com/counterwound/library-altium
- https://github.com/nimaltd/AltiumLibrary
- https://github.com/hilbertw/AltiumDesignerIntlib
- https://github.com/yashodhalakshana/altium-library
