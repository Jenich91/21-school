#!/bin/bash
# Для установки запускаем -> bash installGoAccess.sh
path=''.''
logpath=`find $path -type f -name "*.log" | head -n1`



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
    # смотреть HTTP STATUS CODES
    sudo goaccess $logpath -o stat.html --sort-panel=STATUS_CODES,BY_DATA,DESC -p goaccess.conf
elif [[ $mode -eq 2 ]];then # Все уникальные IP, встречающиеся в записях
    # смотреть VISITOR HOSTNAMES AND IPS - все перечисленные IP уникальные
    sudo goaccess $logpath -o stat.html -p goaccess.conf
elif [[ $mode -eq 3 ]];then # Все запросы с ошибками (код ответа - 4хх или 5хх)
    sudo goaccess $logpath -o stat.html --ignore-status=200 --ignore-status=201 -p goaccess.conf
elif [[ $mode -eq 4 ]];then # Все уникальные IP, которые встречаются среди ошибочных запросов
    # смотреть VISITOR HOSTNAMES AND IPS - все перечисленные IP уникальные среди ошибочных запросов
    sudo goaccess $logpath -o stat.html --ignore-status=200 --ignore-status=201 -p goaccess.conf
fi