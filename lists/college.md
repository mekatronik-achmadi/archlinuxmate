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

```
depends += 'python-lazy-loader' 'python-msgpack'
```
- https://aur.archlinux.org/packages/python-librosa/

### install audio tools
- https://aur.archlinux.org/packages/snack/
- https://aur.archlinux.org/packages/wavesurfer/

```sh
unset _JAVA_OPTIONS
```
- https://aur.archlinux.org/packages/roomeqwizard/
