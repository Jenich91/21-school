#!/bin/bash
path=''.''
filePath=`find $path -type f -name "*.log" | head -n1`

# Написать bash-скрипт для разбора логов nginx из Части 4 через awk.
# Скрипт запускается с 1 параметром, который принимает значение 1, 2, 3 или 4.

# проверка на число и непустоту переменной
if [[ $1 =~ ^[0-9]+$ ]];then
    mode=$1
else
    echo "ERROR: Argument№1 \"$1\" contains non numerical value"
    exit
fi
if [[ ! $mode > 0 || ! $mode -le 4 ]]; then 
    echo "ERROR: Argument№1 \"$1\" has an invalid range "
    exit
fi

# В зависимости от значения параметра вывести:
if [[ $mode -eq 1 ]];then # Все записи, отсортированные по коду ответа
    awk '{print $0 | "sort -k 10 -t\047 \047 -n"}' $filePath
elif [[ $mode -eq 2 ]];then # Все уникальные IP, встречающиеся в записях
    awk '{print $1 | "sort -k 10 -t\047 \047 -rn | uniq"}' $filePath
elif [[ $mode -eq 3 ]];then # Все запросы с ошибками (код ответа - 4хх или 5хх)
    awk -e '$10 ~ /^[4-5]../ {printf $7" "$8" "$9 "\n"}' $filePath
elif [[ $mode -eq 4 ]];then # Все уникальные IP, которые встречаются среди ошибочных запросов
    awk -e '$10 ~ /^[4-5]../ {print $1 | "sort -u"}' $filePath
fi
