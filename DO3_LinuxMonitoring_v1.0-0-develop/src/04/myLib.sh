#!/bin/bash
function GetGbSize {
    local modeArg=$1
    local awkArgNum=$2

    if [[ $modeArg = "ram" ]]; then
        modeArg="free -m"
    elif [[ $modeArg = "root" ]]; then
        modeArg="df -m /"
    else
        echo "ERROR, GetInfo func: Invalid mode argument"
        exit
    fi

    mbSize=$($modeArg  | sed -n 2p | awk x=$awkArgNum'{print $x}')
    local gbSize=$(echo $mbSize / 1024 | bc -l | awk '{printf "%0.3f\n", $1}')
    echo $gbSize
}

function BuildRValuePart {
    precision=$3
    
    gbSize=$(GetGbSize $1 $2)
    echo $(printf "%0.$(($precision))fGb\n" $gbSize)
}

function AddCollor {
    lValue=$1
    rValue=$2
    echo -e "${bg[$lvalueBgColor]}${font[$lvalueFontColor]}$lValue${breakColor} = "${bg[$rvalueBgColor]}${font[$rvalueFontColor]}$rValue${breakColor};
}

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