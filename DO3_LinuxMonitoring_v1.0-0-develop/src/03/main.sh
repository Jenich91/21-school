#!/bin/bash
. ./myLib.sh

if [[ $# != 4 ]]; then
    echo "ERROR: Invalid number of arguments. Try calling the script again"
    exit
fi

for i in "$@"
do
    if [[ $i < 1 || $i > 6 ]]; then
        echo "ERROR: Invalid argument value. Try calling the script again"
        exit
    fi
done

if [[ $1 = $2 || $3 = $4 ]]; then
    echo "ERROR: The value of the font color and the background color should be different. Try calling the script again"
    exit
fi

lvalueBgColor=$1
lvalueFontColor=$2
rvalueBgColor=$3
rvalueFontColor=$4

breakColor='\e[0m'

font=([1]='\e[37m' [2]='\e[31m' [3]='\e[32m' [4]='\e[34m' [5]='\e[35m' [6]='\e[30m')
bg=([1]='\e[47m' [2]='\e[41m' [3]='\e[42m' [4]='\e[44m' [5]='\e[45m' [6]='\e[40m')

function SystemResearch {
    AddCollor "HOSTNAME" "$(hostname)"
    AddCollor "TIMEZONE" "$(cat /etc/timezone) "UTC" $(date +"%Z")"
    AddCollor "USER" "$(whoami)"
    AddCollor "OS" "$(cat /etc/issue | awk '{print $1,$2,$3}')"
    AddCollor "DATE" "$(date '+%d %b %Y %H:%M:%S')"
    AddCollor "UPTIME" "$(uptime | awk '{print $1}')"
    AddCollor "UPTIME_SEC" "$(awk '{print $1}' /proc/uptime)"
    ipVar=$(ip address | grep "inet.*enp0s3" | awk '{print $2}')
    AddCollor "IP" "$ipVar"
    AddCollor "MASK" "$(ifconfig enp0s3 | awk '/netmask/{split($4,a,":"); print a[1]}')"
    AddCollor "GATEWAY" "$(ip r | grep default | awk '{print $3}')"

    AddCollor RAM_TOTAL $(BuildRValuePart ram 2 3)
    AddCollor RAM_USED $(BuildRValuePart ram 3 3)
    AddCollor RAM_FREE $(BuildRValuePart ram 4 3)
    AddCollor SPACE_ROOT $(BuildRValuePart root 2 2)
    AddCollor SPACE_ROOT_USED $(BuildRValuePart root 3 2)
    AddCollor SPACE_ROOT_FREE $(BuildRValuePart root 4 2)
}

SystemResearch