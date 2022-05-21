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