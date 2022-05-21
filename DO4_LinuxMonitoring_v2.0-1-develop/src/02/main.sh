#!/bin/bash
. ./myLib.sh

START_TIME=$(date +%s)
timeRunIn=`date +%H:%M:%S`

checkArg $1 $2 $3 $4 $5 $6
StartGen

DoFinalLog