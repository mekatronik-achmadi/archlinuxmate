# CAD Packages

## Official

### install cad tools

freecad openscad qcad
povray netcdf-openmpi

### install kicad

kicad kicad-library
kicad-library-3d ngspice

--------------------------------------------------------------------------------

## AUR

### install cad tools

- https://aur.archlinux.org/packages/cura-bin/
- https://aur.archlinux.org/packages/openssl-1.0/ (--skippgpcheck)

### install kicad library

- https://aur.archlinux.org/packages/kicad-library-digikey-git/
- https://aur.archlinux.org/packages/kicad-library-sparkfun-git/
- https://aur.archlinux.org/packages/kicad-library-espressif-git/

--------------------------------------------------------------------------------

## External

### install kicad library

- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/kicad-seeed/
- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/kicad-user/

### install cadsoft eagle

- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/eaglecad/

--------------------------------------------------------------------------------

## Configurations

### configure freecad

#### freecad plugins

```sh
echo "FreeCAD Plugins"
echo "FreeCAD -> Tools -> Addon Manager"
```

FreeCAD recommended plugins:

- https://github.com/kbwbe/A2plus/
- https://github.com/easyw/kicadStepUpMod/
- https://github.com/looooo/freecad.gears/
- https://github.com/jmwright/cadquery-freecad-module/

### configure kicad

#### kicad shortcuts

```sh
for i in `pacman -Qlq kicad | grep desktop`;do sudo sed -i "s#Categories=Science;Electronics;#Categories=Development;#g" $i;done
```

#### kicad plugins

```sh
echo "KiCAD Plugins"
echo "KiCAD -> Tools -> Plugin and Content Manager"
```

KiCAD recommended plugins:

- https://github.com/openscopeproject/InteractiveHtmlBom/
- https://github.com/bennymeg/JLC-Plugin-for-KiCad/
- https://github.com/Bouni/kicad-jlcpcb-tools/

#### kicad custom symbol/footprint

- https://techexplorations.com/blog/kicad/blog-kicad-5-recipe-how-to-create-a-new-component-symbol/
- https://techexplorations.com/kicad-4-book/index-p=111.html

#### check board size

```sh
jq -r '.[].Size' *.gbrjob 2> /dev/null
```

#### online gerber viewer

- http://pcbviewer.geraicerdas.com
- http://pcbviewer.cloudcerdas.com
- https://www.pcbway.com/project/OnlineGerberViewer.html
- https://www.pcbgogo.com/GerberViewer.html
- https://www.elecrow.com/gerberviewer.html
- https://gerber.ucamco.com/
- https://jlcpcb.com/RGE
- https://gerblook.org/

#### local web gerber viewer

```sh
git clone -b main https://github.com/tracespace/tracespace.git
cd tracespace/
sed -i 's#--hot"#--hot --host 0.0.0.0"#g' apps/view/package.json

yarn install
export NODE_OPTIONS=--openssl-legacy-provider
yarn start

# if compiled succesfully
# it doesn't support HTTPS
firefox http://localhost:8080/
firefox http://xxx.xxx.xxx.xxx:8080/
```
