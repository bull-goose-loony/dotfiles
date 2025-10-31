#!/usr/bin/env bash

if [[ -z "$1" ]]; then
  git commit -am "$(date)" && git push # push with generic date message
else
  git commit -am "$1" && git push # push with specified message
fi


