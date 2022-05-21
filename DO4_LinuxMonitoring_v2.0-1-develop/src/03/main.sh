#!/bin/bash
. ./myLib.sh

checkArg $1
if [[ $mode = 1 ]]; then
    LogFileClearing
elif [[ $mode = 2 ]]; then
    DateTimeClearing
elif [[ $mode = 3 ]]; then
    NameMaskClearing $2
fi

sudo bash -c "> log.txt"
sudo bash -c "> ../02/log.txt"