#!/bin/sh
GREEN_BACK=$'\e[0;45m'
GREEN_TEXT=$'\e[0;42m'
RED_TEXT=$'\e[0;31m'
# FLASH_TEXT=$'\e[0;05m'
DONE_CHAR=$'\e[0;42m✔'
FAIL_CHAR=$'\e[0;41m✘\e[0;00m'
TO_DEFAULT=$'\e[0;00m'

counter=0

cp ../../data-samples/grep/* ./

#############
./s21_grep "" input.txt > s21_grep_out
grep "" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######e#####
./s21_grep -e "" input.txt > s21_grep_out
grep -e "" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#############
./s21_grep -e "her" input.txt input2.txt > s21_grep_out
grep -e "her" input.txt input2.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_grep -e him input.txt input2.txt > s21_grep_out
grep -e him input.txt input2.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_grep -e "\([a-z]\)\([a-z]\)[a-z]\2\1" input3.txt > s21_grep_out
grep -e "\([a-z]\)\([a-z]\)[a-z]\2\1" input3.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_grep -e "[[:digit:]]" input3.txt  > s21_grep_out
grep -e "[[:digit:]]" input3.txt  > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
######e_multi_pattern#####
./s21_grep -e "But" input.txt -e "son" input2.txt > s21_grep_out
grep -e "But" input.txt -e "son" input2.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -e "son" -e "But" input2.txt input.txt > s21_grep_out
grep -e "son" -e "But" input2.txt input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######i######
./s21_grep -i "Him" input.txt input2.txt > s21_grep_out
grep -i "Him" input.txt input2.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######v######
./s21_grep -v "[[:digit:]]" input3.txt > s21_grep_out
grep -v "[[:digit:]]" input3.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_grep -v "+" input.txt input2.txt > s21_grep_out
grep -v "+" input.txt input2.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######c######
./s21_grep -c "her" input.txt input2.txt > s21_grep_out
grep -c "her" input.txt input2.txt  > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######l######
./s21_grep -l "she" input.txt input2.txt > s21_grep_out
grep -l "she" input.txt input2.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_grep -n "she" input.txt input2.txt > s21_grep_out
grep -n "she" input.txt input2.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_grep -h "she" input.txt input2.txt > s21_grep_out
grep -h "she" input.txt input2.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_grep -h " " input2.txt input3.txt > s21_grep_out
grep -h " " input2.txt input3.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#############
./s21_grep -s "her" input1.txt input2.txt > s21_grep_out
grep -s "her" input1.txt input2.txt  > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#############
./s21_grep -s "son" input2.txt input1.txt > s21_grep_out
grep -s "son" input2.txt input1.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -f regex2.txt input4.txt > s21_grep_out
grep -f regex2.txt input4.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -f regex.txt input3.txt > s21_grep_out
grep -f regex.txt input3.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -o "her" input.txt > s21_grep_out
grep -o "her" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -o "her" input.txt input2.txt > s21_grep_out
grep -o "her" input.txt input2.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
######e-multi-flag######
./s21_grep -e "her" input.txt -i > s21_grep_out
grep -e "her" input.txt -i > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -e "her" -v input.txt > s21_grep_out
grep -e "her" -v input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -e "her" -c input.txt > s21_grep_out
grep -e "her" -c input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -e "her" -c input.txt > s21_grep_out
grep -e "her" -c input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -e "her" input.txt -l > s21_grep_out
grep -e "her" input.txt -l > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -e "her" input.txt -n > s21_grep_out
grep -e "her" input.txt -n > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -e "her" input.txt -h > s21_grep_out
grep -e "her" input.txt -h > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -e "her" input.txt -s > s21_grep_out
grep -e "her" input.txt -s > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# ############
./s21_grep -f regex.txt input3.txt -e "her" input.txt > s21_grep_out
grep -f regex.txt input3.txt -e "her" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -e "er" input.txt -o > s21_grep_out
grep -e "er" input.txt -o > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -e "er" input.txt -o > s21_grep_out
grep -e "er" input.txt -o > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######i-multi-flag#####
./s21_grep -i "her" input.txt -v > s21_grep_out
grep -i "her" input.txt -v > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -i "her" input.txt input2.txt -c > s21_grep_out
grep -i "her" input.txt input2.txt -c > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -i "her" input.txt input2.txt -l > s21_grep_out
grep -i "her" input.txt input2.txt -l > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -i "her" input.txt input2.txt -n > s21_grep_out
grep -i "her" input.txt input2.txt -n > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -i "her" input.txt input2.txt -h > s21_grep_out
grep -i "her" input.txt input2.txt -h > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -i "her" input.txt inpuht2.txt -s > s21_grep_out
grep -i "her" input.txt inpuht2.txt -s > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#############
./s21_grep -i -e "her" -f regex.txt input.txt > s21_grep_out
grep -i -e "her" -f regex.txt input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#############
./s21_grep -i -o "are" input.txt > s21_grep_out
grep -i -o "are" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######v-multi-flag######
./s21_grep -v "her" input.txt -v > s21_grep_out
grep -v "her" input.txt -v > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# ############
./s21_grep -v "her" input.txt input2.txt -c > s21_grep_out
grep -v "her" input.txt input2.txt -c > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# ############
./s21_grep -v "her" input.txt input2.txt -l > s21_grep_out
grep -v "her" input.txt input2.txt -l > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# ############
./s21_grep -v "her" input.txt input2.txt -n > s21_grep_out
grep -v "her" input.txt input2.txt -n > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# ############
./s21_grep -v "her" input.txt input2.txt -h > s21_grep_out
grep -v "her" input.txt input2.txt -h > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# ############
./s21_grep -v "her" input.txt inpuht2.txt -s > s21_grep_out
grep -v "her" input.txt inpuht2.txt -s > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# #############
./s21_grep -v -e "her" -f regex.txt input.txt > s21_grep_out
grep -v -e "her" -f regex.txt input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# #############
./s21_grep -v -o "are" input.txt > s21_grep_out
grep -v -o "are" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######c-multi-flag######
./s21_grep -c -l "her" input.txt > s21_grep_out
grep -c -l "her" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
############
./s21_grep -c "her" input.txt input2.txt -n > s21_grep_out
grep -c "her" input.txt input2.txt -n > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# ############
./s21_grep -c "her" input.txt input2.txt -h > s21_grep_out
grep -c "her" input.txt input2.txt -h > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# ############
./s21_grep -c "her" input.txt inpuht2.txt -s > s21_grep_out
grep -c "her" input.txt inpuht2.txt -s > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# #############
./s21_grep -c -e "her" -f regex.txt input.txt > s21_grep_out
grep -c -e "her" -f regex.txt input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# #############
./s21_grep -c -o "are" input.txt > s21_grep_out
grep -c -o "are" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######l-multi-flag######
./s21_grep -l "her" input.txt input2.txt -n > s21_grep_out
grep -l "her" input.txt input2.txt -n > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# ############
./s21_grep -l "her" input.txt input2.txt -h > s21_grep_out
grep -l "her" input.txt input2.txt -h > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# ############
./s21_grep -l "her" input.txt inpuht2.txt -s > s21_grep_out
grep -l "her" input.txt inpuht2.txt -s > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# #############
./s21_grep -l -e "her" -f regex.txt input.txt > s21_grep_out
grep -l -e "her" -f regex.txt input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#############
./s21_grep -l -o "are" input.txt > s21_grep_out
grep -l -o "are" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######n-multi-flag######
./s21_grep -n "her" input.txt input2.txt -h > s21_grep_out
grep -n "her" input.txt input2.txt -h > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# ############
./s21_grep -n "her" input.txt inpuht2.txt -s > s21_grep_out
grep -n "her" input.txt inpuht2.txt -s > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#############
./s21_grep -n -e "her" -f regex.txt input.txt > s21_grep_out
grep -n -e "her" -f regex.txt input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# #############
./s21_grep -n -o "are" input.txt > s21_grep_out
grep -n -o "are" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######h-multi-flag######
./s21_grep -h "her" input.txt inpuht2.txt -s > s21_grep_out
grep -h "her" input.txt inpuht2.txt -s > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#############
./s21_grep -h -e "her" -f regex.txt input.txt > s21_grep_out
grep -h -e "her" -f regex.txt input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
# #############
./s21_grep -h -o "are" input.txt > s21_grep_out
grep -h -o "are" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######s-multi-flag######
./s21_grep -s -e "her" -f regex.txt input.txt > s21_grep_out
grep -s -e "her" -f regex.txt input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#############
./s21_grep -s -o "are" input.txt > s21_grep_out
grep -s -o "are" input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
#######f&o-multi-flag######
./s21_grep -o -f regex.txt input.txt > s21_grep_out
grep -o -f regex.txt input.txt > grep_out
counter=$((counter+1))
if cmp -s grep_out s21_grep_out ; then
 echo Test_done_№"$counter" ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_fail_№"$counter" ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi

rm -rf *.txt

echo ${GREEN_BACK}'→→→' $'\e[0;05m All Test Done!'${TO_DEFAULT}