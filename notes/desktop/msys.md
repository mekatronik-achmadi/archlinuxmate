# MSYS Guidance

## Windows Recommended

- 7Zip: https://www.7-zip.org/download.html
- LiberationFontsTTF: https://github.com/liberationfonts/liberation-fonts/releases/tag/2.1.5
- Firefox Browser: https://www.mozilla.org/id/firefox/all/#product-desktop-release
- Ghostwriter: https://github.com/KDE/ghostwriter/releases
  + Latest MSVC++: https://learn.microsoft.com/id-id/cpp/windows/latest-supported-vc-redist
- CopyQ: https://github.com/hluk/CopyQ/releases

## Installation

### base packages

Download: https://www.msys2.org/

Install as usual and Choose **MSYS2 MINGW64** as default profile.

To run from Windows' Run dialog (Windows+R)

```bat
C:\msys64\mingw64.exe
```

### add to Path Environment

- C:\msys64\usr\bin
- C:\msys64\mingw64\bin

### update/upgrade (optional)

```sh
pacman -Sy
pacman -Su --noconfirm
```

### basic packages

```sh
pacman -S $(echo "
base base-devel vim mc git tig
winpty neofetch bash-completion
tmux nano-syntax-highlighting
")
```

### additional devel packages

```sh
pacman -S $(echo "
mingw-w64-x86_64-python
mingw-w64-x86_64-toolchain
mingw-w64-x86_64-clang-analyzer
mingw-w64-x86_64-clang-tools-extra
")
```

### basic profile

```sh
echo "
export VISUAL=vim
export EDITOR=vim
export PAGER=less
export VIEWER=less
" | tee /etc/profile.d/myprofile.sh
```

## Vim CoC

### install vim-plug

- https://github.com/junegunn/vim-plug/

```sh
curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

echo -e "
call plug#begin('~/.vim/pack/plug/start')
call plug#end()" > ~/.vimrc
```

```sh
vim +PlugStatus
```

### install nodejs

```sh
pacman -S mingw-w64-x86_64-nodejs mingw-w64-x86_64-yarn
```

### install plugins

**WARNING:**  Python error on Vim Ultisnips

```sh
echo "
call plug#begin('~/.vim/pack/plug/start')
    Plug 'preservim/nerdcommenter'
    Plug 'preservim/nerdtree'
    Plug 'jlanzarotta/bufexplorer'
    Plug 'vim-airline/vim-airline'
    Plug 'vim-airline/vim-airline-themes'
    Plug 'tpope/vim-surround'
    Plug 'airblade/vim-gitgutter'
    Plug 'godlygeek/tabular'
    Plug 'preservim/tagbar'
    Plug 'lervag/vimtex'
    Plug 'chrisbra/csv.vim'
\"    Plug 'SirVer/ultisnips'
\"    Plug 'honza/vim-snippets'
    Plug 'neoclide/coc.nvim', {'branch': 'release'}
call plug#end()

let g:coc_data_home = 'C:\\\\msys64\\\\home\\\\$USER\\\\.config\\\\coc'

inoremap <silent><expr> <CR> coc#pum#visible() ? coc#pum#confirm()
                              \\: \"\\<C-g>u\\<CR>\\<c-r>=coc#on_enter()\\<CR>\"

hi CocFloating ctermfg=Black ctermbg=Yellow guifg=Black guibg=Yellow
hi CocInlayHint ctermfg=Black ctermbg=Yellow guifg=Black guibg=Yellow

autocmd BufWritePre * %s/\s\+$//e
filetype plugin on
filetype indent on
filetype plugin indent on
set expandtab ts=4 sw=4 ai
set conceallevel=0
set encoding=utf-8
set termguicolors
set ic is hls
set number
set wrap!
set mouse=a
let g:tagbar_width=30
let g:NERDTreeWinSize=30
syntax on
" | tee ~/.vimrc
```

```sh
node -v
cat ~/.vimrc
ls ~/.vim/pack/plug/start/

vim +PlugInstall
vim -c "CocInstall coc-snippets coc-ultisnips"
vim -c "CocInstall coc-sh coc-clangd coc-jedi"
vim -c "CocInstall coc-json coc-yaml coc-html"
vim -c "CocInstall coc-vimtex coc-tsserver"
vim +PlugClean
```

## Install VSCode

- https://code.visualstudio.com/download

### terminal settings

```json
 "terminal.integrated.profiles.windows": {
    "msys64": {
        "path": "C:\\msys64\\usr\\bin\\bash.exe",
        "args": [
            "--login",
            "-i"
        ],
          "env": {
            "MSYSTEM": "MINGW64",
            "CHERE_INVOKING": "1"
        }
    },
},
"terminal.integrated.defaultProfile.windows": "msys64",
```

### useful plugins

- https://github.com/clangd/vscode-clangd/
- https://github.com/cschlosser/doxdocgen/
- https://github.com/VSCodeVim/Vim/

## Generate Clangd compile_commands.json

```sh
intercept-build gcc -o coba.exe coba.c
```
