#########################################################################
##### Environment
#########################################################################

echo "Sourcing .zshenv"

export HOME=/home/zach
export EDITOR=nvim
export TERM=alacritty
#export XORG_CONFIG=/etc/X11/xorg.conf
export RUST_BACKTRACE=1
export SHELL=/bin/zsh
export HISTCONTROL=ignoreboth # Remove duplicates from history.
# export ERGO=$HOME/qmk_firmware/keyboards/ergodox_ez/keymaps/griff613 # Hoe made
export JAVA_HOME="/usr/lib/jvm/java-21-openjdk"

RUST_LOG="debug cargo run"

#Config file paths
#export XRC=/usr/lib/X11/xinit
#export XMONAD_CONFIG_DIR=$HOME/.config/xmonad
export XDG_CONFIG_HOME=$HOME/.config
export XDG_CACHE_HOME=$HOME/.cache
export PKG_CONFIG_PATH=/lib/pkgconfig/javascriptcoregtk-4.0.pc
export XDG_PICTURES_DIR=$HOME/Photos 
export ZSHRC="$HOME/.zshrc"
export ZSH_ALIAS="$HOME/.zsh_aliases"
export ZSHENV="$HOME/.zshenv"
export NOTES_DIR="$HOME/notes"

# Quick directory paths
export PROJECT_DIRECTORY="$HOME/src"
export STE="PROJECT_DIRECTORY/rust-projects/ste/"

# PATH
export PATH="$HOME/.local/bin:$PATH"
export PATH="$HOME/bin:$PATH"

export PATH="$JAVA_HOME/bin:$PATH"
