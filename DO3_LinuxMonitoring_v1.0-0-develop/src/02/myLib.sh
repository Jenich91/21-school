#!/bin/bash
function GetInfo {
    local modeArg=$1
    local awkArgNum=$2
    local preText=$3
    local precision=$4

    if [[ $modeArg = "ram" ]]; then
        modeArg="free -m"
    elif [[ $modeArg = "root" ]]; then
        modeArg="df -m /"
    else
        echo "ERROR, GetInfo func: Invalid mode argument"
        exit
    fi

    mbSize=$($modeArg  | sed -n 2p | awk x=$awkArgNum'{print $x}')
    gbSize=$(echo $mbSize / 1024 | bc -l | awk '{printf "%0.3f\n", $1}')
    printf "$preText = %0.$(($precision))fGb\n" $gbSize
}

function SystemResearch {
    echo "HOSTNAME = "$(hostname);
    echo "TIMEZONE = "$(cat /etc/timezone) "UTC" $(date +"%Z");
    echo "USER = "$(whoami);
    echo "OS = "$(cat /etc/issue | awk '{print $1,$2,$3}');
    echo "DATE = "$(date '+%d %b %Y %H:%M:%S')
    echo "UPTIME = "$(uptime | awk '{print $1}')
    echo "UPTIME_SEC = "$(awk '{print $1}' /proc/uptime)
    ipVar=$(ip address | grep "inet.*enp0s3" | awk '{print $2}')
    echo "IP = "$ipVar
    echo "MASK = "$(ifconfig enp0s3 | awk '/netmask/{split($4,a,":"); print a[1]}')
    echo "GATEWAY = "$(ip r | grep default | awk '{print $3}')

    GetInfo ram 2 RAM_TOTAL 3
    GetInfo ram 3 RAM_USED 3
    GetInfo ram 4 RAM_FREE 3
    GetInfo root 2 SPACE_ROOT 2
    GetInfo root 3 SPACE_ROOT_USED 2
    GetInfo root 4 SPACE_ROOT_FREE 2
}

function LogToFile {
    read -p 'Write data to file? ' userInput

    if [[ $userInput = 'Y' || $userInput = 'y' ]]; then
        filename=$(date '+%d_%m_%y_%H_%M_%S').status
        echo "$outputVar" | tee $filename > /dev/null
    fi
}
