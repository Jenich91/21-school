#!/bin/bash

function checkArg {
# Параметр 1 - список букв английского алфавита, используемый в названии папок (не более 7 знаков). 
letterListFolderNames=$1
if [[ ${#letterListFolderNames} > 7 ]]; then
    echo "ERROR: Argument№1 too much number of arguments"
    exit
fi  
if [[ ! "$letterListFolderNames" =~ ^[A-Za-z_]+$ ]]; then 
    echo "ERROR: Argument№1 \"$1\" contains non alphabet value"
    exit
fi

# Параметр 2 - список букв английского алфавита, используемый в имени файла и расширении (не более 7 знаков для имени, не более 3 знаков для расширения). 
letterListfilenameAndExtension=$2
if [[ ! "$letterListfilenameAndExtension" =~ ^([a-zA-Z]{1,7}).([a-zA-Z]{1,3})$ ]]; then 
    echo "ERROR: Argument№2 \"$2\" contains non alphabet value or has an invalid length"
    exit
fi

# Параметр 3 - размер файла (в Мегабайтах, но не более 100).
filesize=$3
onlySize=${filesize%Mb}

if [[ ! "$3" =~ ^([0-9]+Mb)$ ]]; then 
    echo "ERROR: Argument№3 \"$3\" incorrect size format"
    exit
fi

if [[ ! $onlySize > 0 || ! $onlySize -le 100 ]]; then 
    echo "ERROR: Argument№3 \"$3\" has an invalid length "
    exit
fi
}

function StartGen {
    nameLen=${#letterListFolderNames}
    offset=$nameLen

    if [[ nameLen -lt 5 ]]; then
        offset=(5 - $nameLen)
    fi
    
    subfoldersNumber=$((1 + $RANDOM % 100)) #количество файлов в каждой созданной папке. 
    randPath=`GetRandomPath`

    for (( i=$offset; i<($subfoldersNumber+$offset); i++ ))
    do
        dirPath=$(makeDir $randPath $i)    # dlinna imeni kajdoi papki
        randPath=$dirPath

        randNum=$((1 + $RANDOM % 100))
        maXnameLen=$((randNum+5))

        for (( j=5; j<$maXnameLen; j++ ))
        do
                if [[ $(isOverMemory) == "true" ]]; then
                echo "ERROR! Memory is over (∩╹□╹∩)"
                echo -e "On folder:\n"$dirPath
                DoFinalLog
                exit              # ecJlN KOH4u/\OCb MECTO
            else
                isDigit='^[0-9]+$'
                if [[ $j =~ $isDigit ]]; then
                    makeFile $dirPath $j
                fi
            fi
        done
    done
}

function makeDir {
    path=$randPath/$(FolderNameGen $2)_$('GetDate')
    sudo mkdir $path 2>/dev/null

    AddLogLine $path $(GetDate)
    echo $path
}

function makeFile {
    FolderPath=$1
    nameLen=$2
    FileName=$(FileNameGen $nameLen)

    sudo bash -c "fallocate -l ${filesize^} $FolderPath/$FileName 2>/dev/null"

    # путь k failu
    # дата создания
    # размер файлa
    AddLogLine $FolderPath/$FileName $(GetDate) $onlySize
}


function GetDate
{
    echo `date +%d%m%y`
}

function FolderNameGen {
    str=$letterListFolderNames
    maxLen=$1
    charsNumber=${#str}

    strlen=${#str}
    lastChar=${str:strlen-1}
    firstChar=${str:0:1}

    for (( i=$strlen; i<$maxLen; i++ ))
    do
        str="${str:0:1}${str}" #добавляем символ в строку
        let "strlen+=1" 
    done

    echo $str
}

function FileNameGen {
    strFile=$letterListfilenameAndExtension
    baseCharset=${strFile%%.*} #получить имя файла
    extCharset=${strFile#*.} #получить расширение

    baselen=$(printf "%s" "$baseCharset" | wc -c)

    baseMaxLen=$1
    base=$baseCharset

    if [[ $baseMaxLen -lt 4 ]]
    then
        baseMaxLen=4
    fi

    for (( i=$baselen; i<$baseMaxLen; i++ ))
    do
        base="${base:0:1}${base}" #добавляем символ в строку
        let "strlen+=1"
    done

    ext=$extCharset

    echo "$base"_"$(GetDate).$ext"
}

function GetFreeSize {
    echo `df / -BM | awk '{print $4}' | tail -n 1 | cut -d 'M' -f1`
}

function isOverMemory {
    if [[ $(GetFreeSize) -lt "1024" ]]; then
        echo "true"
    else
        echo "false"
    fi
}

function AddLogLine {
    # путь
    fullPath=$1
    # дата создания
    date=$2
    # размер файлa
    size=$3
  
    line="$fullPath $date $size"
    sudo bash -c "echo '$line' >> log.txt"

}

function randomPathGen {
    echo `find / -maxdepth 5 -type d -writable 2>/dev/null | sort -R | tail -1 | grep -v "bin|sbin"`
}

function GetRandomPath {
    i=0
    while true; do
        RandPath=$(randomPathGen)

        if [[ -d "${RandPath}" && ! -L "${RandPath}" ]] ; then 
            echo $RandPath      
            break
        fi
    done
}

function DoFinalLog {
    timeCompletedIn=`date +%H:%M:%S`
    END_TIME=$(date +%s)
    executionTime=$(( $END_TIME - $START_TIME ))

    echo "Script is running in = $(date '+%Y-%m-%d') $timeRunIn"
    echo "Script completed in = $(date '+%Y-%m-%d') $timeCompletedIn"
    echo "Script execution time (in seconds) = $executionTime"

    sudo bash -c "echo 'Script is running in = $(date '+%Y-%m-%d') $timeRunIn' >> log.txt"
    sudo bash -c "echo 'Script completed in = $(date '+%Y-%m-%d') $timeCompletedIn' >> log.txt"
    sudo bash -c "echo 'Script execution time (in seconds) = $executionTime' >> log.txt"

    sudo bash -c "cat log.txt >> ../03/log.txt" # copy log to log for cleaner script
}