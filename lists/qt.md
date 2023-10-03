# Qt

## Official

### install qt programming
qt5 qt6 qtcreator
x11-ssh-askpass

### install qt python
pyqt-builder
sip python-qtpy
python-pyqt5
pyside2 pyside2-tools
python-pyqt5-3d python-pyqt5-webengine
python-pyqt5-chart python-pyqt5-datavisualization
python-pyqt6
pyside6 pyside6-tools
python-pyqt6-3d python-pyqt6-webengine
python-pyqt6-charts python-pyqt6-datavisualization

### install qt graph additionals
qcustomplot qwt
python-pyqtgraph

--------------------------------------------------------------------------------

## AUR

### install qt5 qwt additionals
- https://aur.archlinux.org/packages/qwt5-qt5/
- https://aur.archlinux.org/packages/qwtplot3d-qt5/
- https://aur.archlinux.org/packages/python-pyqt-qwt/

--------------------------------------------------------------------------------

## Configurations

### configure qtcreator

```sh
echo "Help->About Plugins->C++"
echo "check: ClangCodeModel"

echo "Edit->Preferences->Text Editor->Font & Colors"
echo "Family: LiterationMono Nerd Font"
echo "Size: 8"

echo "Edit->Preferences->C++->Code Model"
echo "check: Interpret ambiguous headers as C headers"
echo "check: Ignore precompiled headers"

echo "Edit->Preferences->C++->Clangd"
echo "uncheck: Use clangd"

echo "Edit->Preferences->Analyzer"
echo "uncheck: Analyze open files"

echo "Edit->Preferences->FakeVim"
echo "uncheck: Use FakeVim"
```

