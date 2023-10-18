# College Packages

## Official

### install libreoffice

libreoffice-fresh coin-or-mp

### install fortran

gcc-fortran arpack
gnuplot mpdecimal

### install python computing

python-tabulate
python-matplotlib
python-bottleneck
python-statsmodels
python-scikit-learn
python-h5py-openmpi
python-pandas-datareader
python-numpy python-rpy2
python-sphinx python-dask
python-sympy python-scipy
python-gnuplot python-yaml
python-seaborn python-patsy
python-pytables python-tqdm
python-pandas python-numexpr

### install python interface

jupyter-notebook spyder

### install python additional

python-flit python-invoke python-cffi
python-pillow python-beautifulsoup4
python-pyaudio python-sounddevice

### install cpu machine learning

tensorflow python-tensorflow tensorboard

### install image processing

opencv python-opencv
hdf5-openmpi vtk
python-pytesseract
tesseract-data-eng
tesseract-data-ind

### install texlive

texlive texlive-langenglish
texstudio minted biber pdftk
dblatex latex2html latex2rtf

### install programming additionals

fftw liquid-dsp libsndfile

--------------------------------------------------------------------------------

## AUR

### install ms fonts

- https://aur.archlinux.org/packages/ttf-tahoma/
- https://aur.archlinux.org/packages/ttf-ms-fonts/
- https://aur.archlinux.org/packages/ttf-vista-fonts/

### install academic tools

- https://aur.archlinux.org/packages/mendeleydesktop-bundled/
- https://aur.archlinux.org/packages/drawio-desktop-bin/
- https://aur.archlinux.org/packages/scidavis-qt5/

### install wps office

- https://aur.archlinux.org/packages/libtiff5/
- https://aur.archlinux.org/packages/wps-office/
- https://aur.archlinux.org/packages/ttf-wps-fonts/

### install python additionals

- https://aur.archlinux.org/packages/python-soundfile/
- https://aur.archlinux.org/packages/python-imutils/
- https://aur.archlinux.org/packages/python-pyfftw/

### install python librosa

```sh
sed -i "s#llvm11#llvm14#g" PKGBUILD
sed -i "s#'llvm-config'#'llvm-config-14'#g" src/llvmlite/ffi/build.py
```

- https://aur.archlinux.org/packages/python-llvmlite-git/
- https://aur.archlinux.org/packages/python-numba-git/
- https://aur.archlinux.org/packages/python-lazy-loader/
- https://aur.archlinux.org/packages/python-audioread/
- https://aur.archlinux.org/packages/python-resampy/

```text
depends += 'python-lazy-loader' 'python-msgpack'
```

- https://aur.archlinux.org/packages/python-librosa/

### install audio tools

- https://aur.archlinux.org/packages/snack/
- https://aur.archlinux.org/packages/wavesurfer/

```sh
echo "add this on package()"
echo "unset _JAVA_OPTIONS"
```

- https://aur.archlinux.org/packages/roomeqwizard/

--------------------------------------------------------------------------------

## External

### install python photonic tools

- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/python-modules/instrumental/
- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/python-modules/pyotdr/
- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/python-modules/pm100/

### install python acoustics tools

- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/python-modules/acoustics/
- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/python-modules/soxr/
- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/pychoacoustics/

--------------------------------------------------------------------------------

## Configurations

### configure wps office

```sh
sudo rm -f /usr/share/applications/wps-office-pdf.desktop
sudo rm -f /usr/share/applications/wps-office-prometheus.desktop
sudo sed -i '/^$/d' /usr/share/desktop-directories/wps-office.directory
echo 'NoDisplay=true' | sudo tee -a /usr/share/desktop-directories/wps-office.directory
```

### configure mendeley desktop

```sh
sudo sed -i 's#mendeleydesktop %f#mendeleydesktop -style gtk %f#g' /usr/share/applications/mendeleydesktop.desktop
sed -i 's#mendeleydesktop %f#mendeleydesktop -style gtk %f#g' ~/.local/share/applications/mendeleydesktop.desktop
```

### configure texstudio

```sh
"latex -shell-escape -src -interaction=nonstopmode %.tex"
"pdflatex -shell-escape -synctex=1 -interaction=nonstopmode %.tex"
```

```sh
FancyVerb error \end{minted}
Just delete \t (Tab) after \end{minted}
```

```sh
Uncheck 'Adv. Editor'->'Structure Panel'->'Mark structure elements beyond \end{document}'
```

### configure roomeqwizard

```sh
sudo sed -i 's#Categories=Application;#Categories=AudioVideo;Audio;Player;#g' \
/usr/share/applications/roomeqwizard/roomeqwizard.desktop
echo "Terminal=false" | sudo tee -a /usr/share/applications/roomeqwizard/roomeqwizard.desktop
echo "Comment=Room Equalizer Wizard"  | sudo tee -a /usr/share/applications/roomeqwizard/roomeqwizard.desktop
```
