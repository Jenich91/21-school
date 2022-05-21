#!/bin/bash
. ./myLib.sh

# mkdir -p /test/
# sudo rm -rf /test/* #clean

touch log.txt
checkArg $1 $2 $3 $4 $5 $6
StartGen

tree /test tree --du --si --dirsfirst