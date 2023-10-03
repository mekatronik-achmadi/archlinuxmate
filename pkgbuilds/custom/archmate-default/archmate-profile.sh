# binary path
export PATH=$PATH:~/.local/bin

# cli browser
export BROWSER=w3m

# java settings
export _JAVA_OPTIONS='-Dawt.useSystemAAFontSettings=on -Dswing.aatext=true -Djdk.util.zip.ensureTrailingSlash=false -Dswing.defaultlaf=com.sun.java.swing.plaf.gtk.GTKLookAndFeel -Dswing.crossplatformlaf=com.sun.java.swing.plaf.gtk.GTKLookAndFeel'
export JAVA_FONTS=/usr/share/fonts/TTF

# qt5/qt6 theme
export QT_QPA_PLATFORMTHEME=qt5ct

# cli editor
export VISUAL=vim
export EDITOR=vim
export PAGER=most
export VIEWER=most

# font TTF settings
export FREETYPE_PROPERTIES="truetype:interpreter-version=40"
export FT2_SUBPIXEL_HINTING=2

# force gtk3 nocsd
export GTK_CSD=0
export LD_PRELOAD=/usr/lib/libgtk3-nocsd.so.0:$LD_PRELOAD
