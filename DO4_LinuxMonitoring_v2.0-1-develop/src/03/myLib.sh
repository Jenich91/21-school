#!/bin/bash

function checkArg {
# Параметр 1 - режим очистки. 
if [[ $1 =~ ^[1-3]+$ ]];then
    mode=$1
else
    echo "ERROR: Argument№1 \"$1\" contains non numerical value or value in an invalid range"
    exit
fi
}

function LogFileClearing {
    while read line
    do
        path=$(echo $line | awk '{print $1}')
        sudo rm -rf $path
    done < log.txt
}

function DateTimeClearing {
    echo "input should be like: $(date '+%Y-%m-%d %H:%M:%S')"

    read -p "enter the beginning of the search range for files to delete, date and time: " START_TIME
    read -p "enter the end of the file search range to delete, date: " END_TIME

    echo "deleting files created from "$START_TIME" to "$END_TIME"..."
    find / -newermt "$START_TIME" -not -newermt "$END_TIME" 2>/dev/null | sudo xargs rm -r 2>/dev/null
}

function NameMaskClearing {
    # nameMask=$1
    echo "input slould be like: qwerty_$(date '+%d%m%y')"
    read -p "enter the namemask: " nameMask

    echo "deleting files with mask = $nameMask..."
    find / -type f -name "*$nameMask*" 2>/dev/null | sudo xargs rm -r 2>/dev/null
    find / -type d -name "*$nameMask*" 2>/dev/null | sudo xargs rm -r 2>/dev/null
}