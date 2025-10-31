#!/usr/bin/env bash

if [[ -z "$1" ]]; then
  git commit -am "$(date)" && git push
else
  git commit -am $1 && git push
fi


