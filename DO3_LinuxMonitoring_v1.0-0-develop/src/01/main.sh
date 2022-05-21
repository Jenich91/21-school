#!/bin/bash
input=$1

if [ -z ${1+x} ]; then
    echo "Empty input!";
    exit
elif [[ $1 =~ (^[+-]?[0-9]+([./,][0-9]+)?$) ]]; then
    echo "Invalid input!"
else
    echo $1
fi
