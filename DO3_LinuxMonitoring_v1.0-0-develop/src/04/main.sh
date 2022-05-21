#!/bin/bash
. ./myLib.sh
. ./conf.ini

lvalueBgColor=$column1_background
lvalueFontColor=$column1_font_color
rvalueBgColor=$column2_background
rvalueFontColor=$column2_font_color

lvalueBgColor=${lvalueBgColor:-6}
lvalueFontColor=${lvalueFontColor:-1}
rvalueBgColor=${rvalueBgColor:-2}
rvalueFontColor=${rvalueFontColor:-4}

if [[ $lvalueBgColor < 1 || $lvalueBgColor > 6 ]]; then
    echo "ERROR: Invalid argument value. Change the configuration file and try calling the script again"
    exit
elif [[ $lvalueFontColor < 1 || $lvalueFontColor > 6 ]]; then
    echo "ERROR: Invalid argument value. Try calling the script again"
    exit
elif [[ $rvalueBgColor < 1 || $rvalueBgColor > 6 ]]; then
    echo "ERROR: Invalid argument value. Try calling the script again"
    exit
elif [[ $rvalueFontColor < 1 || $rvalueFontColor > 6 ]]; then
    echo "ERROR: Invalid argument value. Try calling the script again"
    exit
elif [[ $lvalueBgColor = $lvalueFontColor || $rvalueBgColor = $rvalueFontColor ]]; then
    echo "ERROR: The value of the font color and the background color should be different. Try calling the script again"
    exit
fi

breakColor='\e[0m'

font=([1]='\e[37m' [2]='\e[31m' [3]='\e[32m' [4]='\e[34m' [5]='\e[35m' [6]='\e[30m')
bg=([1]='\e[47m' [2]='\e[41m' [3]='\e[42m' [4]='\e[44m' [5]='\e[45m' [6]='\e[40m')

SystemResearch

ColorArr=([1]=white [2]=red [3]=green [4]=blue [5]=purple [6]=black)

if [[ ! ${column1_background+x} ]]; then
    column1_background="default"   
fi
if [[ ! ${column1_font_color+x} ]]; then
    column1_font_color="default"   
fi
if [[ ! ${column2_background+x} ]]; then
    column2_background="default"   
fi
if [[ ! ${column2_font_color+x} ]]; then
    column2_font_color="default"   
fi

echo ""
echo "Column 1 background = ""$column1_background (${ColorArr[$lvalueBgColor]})"
echo "Column 1 font color = ""$column1_font_color (${ColorArr[$lvalueFontColor]})"
echo "Column 2 background = ""$column2_background (${ColorArr[$rvalueBgColor]})"
echo "Column 2 font color = ""$column2_font_color (${ColorArr[$rvalueFontColor]})"