#!/bin/bash
START_TIME=$(date +%s)
. ./myLib.sh

if ! [ -d $1 ] || [ ! ${1+x} ]; then
echo 'Error! Argument not set or directory does not exist =('
exit
elif [[ "$1" != */ ]]; then
echo 'Error! need '/' character at the end of the line'
exit
fi
dirPath=$1

echo "Total number of folders (including all nested ones) = "$(find $dirPath 2>/dev/null -mindepth 1 -type d | wc -l);
echo "TOP 5 folders of maximum size arranged in descending order (path and size): ";
   du $dirPath -Sh 2>/dev/null| sort -rh | head -5 | awk 'BEGIN{i=1} {printf "%d - %s, %s\n", i, $2, $1; i++}'
echo "Total number of files = ""$(find $dirPath 2>/dev/null -type f | wc -l)"
echo "Number of: "
echo "Configuration files (with the .conf extension) = ""$(find $dirPath 2>/dev/null -type f -name "*.conf" | wc -l)"
echo "Text files = ""$(find $dirPath 2>/dev/null -type f 2>/dev/null | xargs file {} | awk {'print $3'} | grep "text" | grep -v "executable"| wc -l)"
echo "Executable files = ""$(find $dirPath 2>/dev/null -type f -executable | wc -l)"
echo "Log files (with the extension .log) = ""$(find $dirPath 2>/dev/null -type f -name "*.log" 2>/dev/null | wc -l)"
echo "Archive files = ""$(find $dirPath 2>/dev/null -type f | xargs file {} | awk {'print $3'} | grep "archive" | grep -v "executable"| wc -l)"
echo "Symbolic links = ""$(find $dirPath 2>/dev/null -type l | wc -l)"
echo "TOP 10 files of maximum size arranged in descending order (path, size and type):";
    find $dirPath 2>/dev/null -type f -exec du -sh {} 2>/dev/null + | sort -rh | head -n 10 | 
        awk 'BEGIN {
            split($2,arr," ");
        }
            { cmd = ("sh getArrFilePath+Extension.sh " $2)
            while ( ( cmd | getline result ) > 0 ) { 
                $2 = result
            }
            close(cmd);
            }
        {
            split($2,arr," ");
            printf "%d - %s, %s, %s\n", NR, arr[1], $1, arr[2]
        }'

echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file):";
    find $dirPath -type f -executable -exec du -sh {} 2>/dev/null + | sort -rh | head -n 10 | 
        awk '{ cmd = ("md5sum " $2 " ")
            while ( ( cmd | getline result ) > 0 ) { 
                $2 = result
            }
            close(cmd);
            }
        {
            split($2,arr," ");
            printf "%d - %s, %s, %s\n", NR, arr[2], $1, arr[1]
        }'
 
 END_TIME=$(date +%s)
 executionTime=$(( $END_TIME - $START_TIME ))
 echo "Script execution time (in seconds) = " $executionTime