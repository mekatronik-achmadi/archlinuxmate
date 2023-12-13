# Programming Packages

## Official

### install gitea server

gitea postgresql
memcached redis

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

### install c/c++ programming

codeblocks lldb
gdb clang boost
gdb-dashboard
lld valgrind
llvm llvm14

### install java programming

jre-openjdk jdk-openjdk
jre8-openjdk jdk8-openjdk

### install javacript programming

nodejs node-gyp yq
npm yarn asar jq

### install rust programming

rust rust-musl rust-src rust-analyzer
corrosion cargo-asm cargo-edit cargo-audit
cargo-outdated cargo-feature cargo-modules

### install golang programming

go gopls delve
go-tools yaegi

--------------------------------------------------------------------------------

## AUR

### install markdown editor

- https://aur.archlinux.org/packages/pandoc-bin/
- https://aur.archlinux.org/packages/marktext-bin/

### install qt5 qwt additionals

- https://aur.archlinux.org/packages/qwt5-qt5/
- https://aur.archlinux.org/packages/qwtplot3d-qt5/
- https://aur.archlinux.org/packages/python-pyqt-qwt/

### install programmming editor

- https://aur.archlinux.org/packages/eric/
- https://aur.archlinux.org/packages/wxhexeditor/
- https://aur.archlinux.org/packages/wxformbuilder/

### install compiledb

- https://aur.archlinux.org/packages/python-bashlex/
- https://aur.archlinux.org/packages/compiledb/

### install vscodium

- https://aur.archlinux.org/packages/vscodium-bin/
- https://aur.archlinux.org/packages/vscodium-bin-features/
- https://aur.archlinux.org/packages/vscodium-bin-marketplace/

### install system python bindings

- https://aur.archlinux.org/packages/python-wifiwrapper/
- https://aur.archlinux.org/packages/python-pyalsaaudio/

### install java launcher

- https://aur.archlinux.org/packages/archlinux-java-run/

### install shell additional

- https://aur.archlinux.org/packages/ttyplot-git/
- https://aur.archlinux.org/packages/ncurses5-compat-libs/ (--skippgpcheck)

--------------------------------------------------------------------------------

## External

### install doxygen tools

- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/custom-doxygen/
- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/vim-doxygen/

### install codeblocks additionals

- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/cbp2make/
- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/cbcc-stm32/

### install gtk additionals

- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/gtk-wav2c/
- https://github.com/mekatronik-achmadi/archlinuxmate/tree/main/pkgbuilds/optional/gtk-slope/

--------------------------------------------------------------------------------

## Configurations

### configure git server

#### instant git web

```sh
ls ./.git
git instaweb -l -p 5757
```

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

### alternative install vim plug

```sh
curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

echo -e "call plug#begin('~/.vim/pack/plug/start')
call plug#end()" | tee ~/.vimrc

vim +PlugStatus
```

### configure vim plugins

```sh
echo -e "call plug#begin('~/.vim/pack/plug/start')
Plug 'neoclide/coc.nvim', {'branch': 'release'}
\"Plug 'ryanoasis/vim-devicons'
Plug 'honza/vim-snippets'
Plug 'chrisbra/csv.vim'
Plug 'SirVer/ultisnips'
call plug#end()

inoremap <silent><expr> <CR> coc#pum#visible() ? coc#pum#confirm()
                              \\: \"\\<C-g>u\\<CR>\\<c-r>=coc#on_enter()\\<CR>\"

hi CocFloating ctermfg=Black ctermbg=Yellow guifg=Black guibg=Yellow
hi CocInlayHint ctermfg=Black ctermbg=Yellow guifg=Black guibg=Yellow
" | tee ~/.vimrc
```

```sh
node -v
cat ~/.vimrc
mkdir -p ~/.vim/pack/plug/start/

vim +PlugInstall
vim -c "CocInstall coc-pairs coc-snippets"
vim -c "CocInstall coc-sh coc-ultisnips"
vim -c "CocInstall coc-clangd coc-jedi"
vim -c "CocInstall coc-json coc-yaml"
vim -c "CocInstall coc-go coc-rust-analyzer"
vim -c "CocInstall coc-tsserver coc-html"
vim +PlugClean

echo "For editing PKGBUILD"
echo ":set ft=PKGBUILD"
```

```sh
mkdir -p ~/.vim
echo '{}' > ~/.vim/coc-settings.json
jq -n '
."clangd.arguments"=["-header-insertion=never"] |
."pairs.enableCharacters"=["(","[","\"","'\''","`"]
' ~/.vim/coc-settings.json > ~/.vim/coc-settings.json
cat ~/.vim/coc-settings.json

echo "vim color setting commands
echo ":h cterm-colors"
echo ":h gui-colors"
echo ":hi"
```

### configure vscodium

```sh
sudo rm -vf /usr/share/applications/codium-wayland.desktop
```

```sh
vscodium --list-extensions

vscodium --force --install-extension cschlosser.doxdocgen
vscodium --force --install-extension llvm-vs-code-extensions.vscode-clangd
vscodium --force --install-extension rust-lang.rust-analyzer
vscodium --force --install-extension golang.Go
vscodium --force --install-extension ms-python.python
vscodium --force --install-extension ms-toolsai.jupyter
vscodium --force --install-extension vscodevim.vim
```

```sh
VSCONFDIR=~/.config/VSCodium/User

mkdir -p "$VSCONFDIR"
echo "{}" > "$VSCONFDIR/settings.json"

jq -n '
."clangd.arguments"=["-header-insertion=never"] |
."C_Cpp.intelliSenseEngine"="disabled" |
."doxdocgen.file.customTag"=["@addtogroup ","@{"] |
."doxdocgen.file.fileOrder"=["file","brief","empty","custom"] |
."editor.fontFamily"="'\''Liberation Mono'\''" |
."editor.fontSize"=10 |
."editor.minimap.enabled"=false |
."files.trimTrailingWhitespace"=true |
."git.openRepositoryInParentFolders"="never" |
."terminal.integrated.fontSize"=10 |
."terminal.integrated.gpuAcceleration"="canvas" |
."debug.console.wordWrap"=false |
."workbench.startupEditor"="none" |
."workbench.activityBar.visible"=false |
."workbench.colorTheme"="Default Light+" |
."security.workspace.trust.untrustedFiles"="open" |
."window.restoreWindows"="none" |
."telemetry.enableTelemetry"=false |
."telemetry.enableCrashReporter"=false
' | tee "$VSCONFDIR/temp.json"

rm -f "$VSCONFDIR/settings.json"
mv "$VSCONFDIR/temp.json" "$VSCONFDIR/settings.json"

cat "$VSCONFDIR/settings.json"
```

### configure clangd

```sh
bear -- gcc -o coba.exe coba.c
bear -- make -j$(nproc)
```

```sh
compiledb gcc -o coba.exe coba.c
compiledb make -j$(nproc)
```

```sh
# Initial clangd config without header cleaning
echo "
Diagnostics:
  UnusedIncludes: None
" | tee ~/.config/clangd/config.yaml

# Disable header cleaning
sed -i 's@UnusedIncludes: Strict@UnusedIncludes: None@g' ~/.config/clangd/config.yaml
```
