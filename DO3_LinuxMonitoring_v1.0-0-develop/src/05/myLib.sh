#!/bin/bash
function GetGbSize {
    local grepArg=$1
    local awkArgNum=$2

    mbSize=$(free -m  | grep $grepArg | awk x=$awkArgNum'{print $x}')
    local gbSize=$(echo $mbSize / 1024 | bc -l | awk '{printf "%0.3f\n", $1}')
    echo $gbSize
}

function BuildRValuePart {
    awkArgNum=$1
    grepArg=$2
    precision=$3
    
    gbSize=$(GetGbSize $grepArg $awkArgNum)
    echo $(printf "%0.$(($precision))fGb\n" $gbSize)
}

function AddCollor {
    lValue=$1
    rValue=$2
    echo -e "${bg[$lvalueBgColor]}${font[$lvalueFontColor]}$lValue${breakColor} = "${bg[$rvalueBgColor]}${font[$rvalueFontColor]}$rValue${breakColor};
}