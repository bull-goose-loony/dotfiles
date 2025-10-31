#########################################################################
#####  Config for all interactive shells
#########################################################################

export SSH_AUTH_SOCK="${XDG_RUNTIME_DIR}/ssh-agent.socket"

HISTFILE="$HOME/.zsh_history"
HISTSIZE=100000
SAVEHIST=100000

# define word delimiters
WORDCHARS=${WORDCHARS//\/[&.;]}
# define `time` output
TIMEFMT=$'%E'

# Backward search
bindkey -v
bindkey "^R" history-incremental-search-backward

# load autocompletion and colors
autoload -Uz compinit colors promptinit
# allow completions and its cache
compinit
# allow prompt customizations
promptinit
# enable loaded colors
colors
# enable aliases
setopt aliases
# prevent the shell from triggering the pc speaker
setopt nobeep
# keep track of commands
setopt appendhistory
# don't put commands starting with space in history
setopt HIST_IGNORE_SPACE
# allow to customize the prompt
setopt prompt_subst
# change folder by typing nits name
setopt autocd
# allow comments in interactive mode
setopt interactivecomments
# report status of background jobs
setopt notify
# sort files numerically when it makes sense
setopt numericglobsort
# delete history duplicates before older entries
setopt hist_expire_dups_first
# show commands typed in other terminal sessions
setopt share_history


# ################################ Cursor
# Set cursor shape: 1=block, 3=bar
function zle-keymap-select {
  if [[ $KEYMAP == vicmd ]]; then
    echo -ne '\e[1 q'  # block
  else
    echo -ne '\e[5 q'  # bar
  fi
}
zle -N zle-keymap-select

# Also change cursor on mode switch
function zle-line-init {
  echo -ne '\e[5 q'  # start in insert (bar)
}
zle -N zle-line-init

# Reset cursor when zsh exits
autoload -Uz add-zsh-hook
add-zsh-hook zshexit reset-cursor
function reset-cursor {
  echo -ne '\e[5 q'
}
# ################################ COMPLETIONS
 
# case-insensitive tab completion
zstyle ':completion:*' matcher-list 'm:{a-zA-Z}={A-Za-z}'
# colored completion (different colors for dirs/files/etc)
zstyle ':completion:*' list-colors "${(s.:.)LS_COLORS}"
# automatically find new executables in path
zstyle ':completion:*' rehash true
#Reverse search
bindkey '^R' history-incremental-search-backward
export TEXT_EDITOR='nvim'

# ################################ Prompt disabled, using starship

# allow to customize the prompt
# setopt prompt_subst

# show git branch in prompt
# git_branch(){
#  branch=$(git symbolic-ref HEAD 2> /dev/null | awk '{gsub(/refs\/heads\//, ""); print}')
#  if [[ $branch != "" ]]; then
#   echo " ($branch)"
#  fi
# }

# _color1=green
# _color2=blue
# _color3=yellow
 
# PS1='[%B%F{$_color1}%*%f %B%F{$_color2}%~%f]%B%F{$_color3}%u%b$(git_branch)%f $ '
# PS2='%B%F{$_color1}%_|>%f%b '

# ################################ ALIASES AND FUNCTIONS
aliasFile="$HOME/.zsh_aliases"
[[ -e $aliasFile ]] && source "$aliasFile"

# ################################ Run
fastfetch --logo Blackarch
eval "$(starship init zsh)"
eval "$(zoxide init zsh)"

source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

# opencode
export PATH=/home/zach/.opencode/bin:$PATH
