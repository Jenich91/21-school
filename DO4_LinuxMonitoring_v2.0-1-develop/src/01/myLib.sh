#!/bin/bash
# . ./main.sh

function checkArg {
if [ "$#" -ne 6 ]; then
    echo "Illegal number of parameters"
    else

    # Параметр 1 - это абсолютный путь. 
    if ! [ -d $1 ] || [ ! ${1+x} ]; then
        echo 'Error! Argument№1 not set or directory does not exist =('
        exit
    else
        absolutePath=$1
    fi

    # Параметр 2 - количество вложенных папок.
    if [[ $2 =~ ^[0-9]+$ ]];then
        foldersNumber=$2
    else
        echo "ERROR: Argument№2 \"$2\" contains non numerical value"
        exit
    fi

    # Параметр 3 - список букв английского алфавита, используемый в названии папок (не более 7 знаков). 
    letterListFolderNames=$3
    if [[ ${#letterListFolderNames} > 7 ]]; then
        echo "ERROR: Argument№3 too much number of arguments"
        exit
    fi  
    if [[ ! "$letterListFolderNames" =~ ^[A-Za-z_]+$ ]]; then 
        echo "ERROR: Argument№3 \"$3\" contains non alphabet value"
        exit
    fi

    # Параметр 4 - количество файлов в каждой созданной папке. 
    numberFilesInEachFolder=$4
    if [[ $4 =~ ^[0-9]+$ ]];then
        numberFilesInEachFolder=$4
    else
        echo "ERROR: Argument№4 \"$4\" contains non numerical value"
        exit
    fi

    # Параметр 5 - список букв английского алфавита, используемый в имени файла и расширении (не более 7 знаков для имени, не более 3 знаков для расширения). 
    letterListfilenameAndExtension=$5
    if [[ ! "$letterListfilenameAndExtension" =~ ^([a-zA-Z]{1,7}).([a-zA-Z]{1,3})$ ]]; then 
        echo "ERROR: Argument№5 \"$5\" contains non alphabet value or has an invalid length"
        exit
    fi

    # Параметр 6 - размер файлов (в килобайтах, но не более 100).
    filesize=$6
    onlySize=${filesize%kb}

    if [[ ! "$6" =~ ^([0-9]+kb)$ ]]; then 
        echo "ERROR: Argument№6 \"$6\" incorrect size format"
        exit
    fi

    if [[ ! $onlySize > 0 || ! $onlySize -le 100 ]]; then 
        echo "ERROR: Argument№6 \"$6\" has an invalid length "
        exit
    fi
fi
}

function StartGen {
    nameLen=${#letterListFolderNames}
    offset=$nameLen

    if [[ nameLen -lt 4 ]]; then
        offset=(4 - $nameLen)
    fi

    for (( i=$offset; i<($foldersNumber+$offset); i++ ))
    do
        dirPath=$(makeDir $absolutePath $i)    # dlinna imeni kajdoi papki
        absolutePath=$dirPath

        for (( j=0; j<$numberFilesInEachFolder; j++ ))
        do
            if [[ $(isOverMemory) == "true" ]]; then
                echo "ERROR! Memory is over 0_0"
                exit              # ecJlN KOH4u/\OCb MECTO
            else
                makeFile $dirPath $j
            fi
        done
    done
}

function makeDir {
    path=$absolutePath/$(FolderNameGen $2)_$('GetDate')
    sudo mkdir -p $path

    AddLogLine $path $(GetDate)
    echo $path
}

function makeFile {
    FolderPath=$1

    baseCharset=${letterListfilenameAndExtension%%.*}
    baselen=${#baseCharset}
    nameLen=$(($baselen))
    if [[ $nameLen -lt 4 ]]
    then
        let "nameLen+=(4-nameLen)"
    fi
    let "nameLen+=j"
    # echo $baselen
    # путь k failu
    FileName=$(FileNameGen $nameLen)

    # дата создания
    AddLogLine $FolderPath/$FileName $(GetDate) $onlySize

    # размер файлa
    sudo fallocate -l ${filesize^} $FolderPath/$FileName
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
    # echo $strFile

    extCharset=${strFile#*.} # получить расширение
    baseCharset=${strFile%%.*} # получить имя файла
    baselen=${#baseCharset}
    base=$baseCharset
    baseMaxLen=$1
    # if [[ $baselen -lt 4 ]]
    # then
    #     baseMaxLen=4
    # fi

    for (( i=$baselen; i<$baseMaxLen; i++ ))
    do
        base="${base:0:1}${base}" # добавляем символ в строку
        let "strlen+=1"
    done

    strlenExt=${#extCharset}
    maxLenExt=3
    ext=$extCharset
    if [[ $maxLenExt -lt 3 ]]
    then
        maxLenExt=3
    fi

    for (( i=$strlenExt; i<$maxLenExt; i++ ))
    do
        ext="${ext:0:1}${ext}" # добавляем символ в строку
        let "strlen+=1"
    done

    echo "$base.$ext"_"$(GetDate)"
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

    echo "$line" >> log.txt
}
