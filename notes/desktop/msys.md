# MSYS Guidance

## Windows Recommended

- 7Zip: https://www.7-zip.org/download.html
- LiberationFontsTTF: https://github.com/liberationfonts/liberation-fonts/releases/tag/2.1.5
- Firefox Browser: https://www.mozilla.org/id/firefox/all/#product-desktop-release
- Latest MSVC++: https://learn.microsoft.com/id-id/cpp/windows/latest-supported-vc-redist
- CopyQ: https://github.com/hluk/CopyQ/releases
- MarkText: https://www.marktext.cc/
- WinMerge: https://winmerge.org/downloads/?lang=en
- Notepad++: https://notepad-plus-plus.org/downloads/
- Git: https://git-scm.com/download/win
- Git-Cola: https://git-cola.github.io/downloads.html

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
base base-devel gvim mc git tig openssh
winpty neofetch bash-completion rsync
bear tmux nano-syntax-highlighting
")
```

### additional devel packages

```sh
pacman -S $(echo "
mingw-w64-x86_64-python
mingw-w64-x86_64-cython0
mingw-w64-x86_64-python-pip
mingw-w64-x86_64-toolchain
mingw-w64-x86_64-clang-analyzer
mingw-w64-x86_64-clang-tools-extra
mingw-w64-x86_64-ttf-liberation-mono-nerd
")
```

### basic profile

```sh
echo "
export PATH=$PATH:~/.local/bin
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
    Plug 'tpope/vim-commentary'
    Plug 'airblade/vim-gitgutter'
    Plug 'godlygeek/tabular'
    Plug 'preservim/tagbar'
    Plug 'lervag/vimtex'
    Plug 'chrisbra/csv.vim'
\"    Plug 'ryanoasis/vim-devicons'
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
if has(\"gui_running\")
  set guifont=LiterationMono\ Nerd\ Font\ Mono\ 8
\"  colorscheme evening
endif" | tee ~/.vimrc
```

```sh
node -v
cat ~/.vimrc
ls ~/.vim/pack/plug/start/

vim +PlugInstall
vim -c "CocInstall coc-pairs coc-snippets"
vim -c "CocInstall coc-sh coc-ultisnips"
vim -c "CocInstall coc-clangd coc-jedi"
vim -c "CocInstall coc-vimtex coc-json coc-yaml"
vim -c "CocInstall coc-tsserver coc-rust-analyzer"
vim -c "CocInstall coc-go coc-r-lsp coc-html"
vim +PlugClean

echo "For editing PKGBUILD"
echo ":set ft=PKGBUILD"
```

## Generate Clangd compile_commands.json

```sh
bear -- gcc -o coba.exe coba.c
bear -- make -j$(nproc)
```

```sh
pip install compiledb

compiledb gcc -o coba.exe coba.c
compiledb make -j$(nproc)
```
