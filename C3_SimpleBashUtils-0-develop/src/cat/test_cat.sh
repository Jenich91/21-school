#!/bin/sh
GREEN_BACK=$'\e[0;45m'
GREEN_TEXT=$'\e[0;42m'
RED_TEXT=$'\e[0;31m'
# FLASH_TEXT=$'\e[0;05m'
DONE_CHAR=$'\e[0;42m✔'
FAIL_CHAR=$'\e[0;41m✘'
TO_DEFAULT=$'\e[0;00m'

cp ../../data-samples/cat/* ./

##############
./s21_cat -b input.txt input3.txt input2.txt > s21_cat_out
cat -b input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_b_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_b_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -e input.txt input3.txt input2.txt > s21_cat_out
cat -e input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_e_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test1_e_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -n input.txt input3.txt input2.txt > s21_cat_out
cat -n input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_n_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test1_n_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -s input.txt input3.txt input2.txt > s21_cat_out
cat -s input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_s_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_s_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -t input.txt input3.txt input2.txt > s21_cat_out
cat -t input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_t_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -b -e input.txt input3.txt input2.txt > s21_cat_out
cat -b -e input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_b+e_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_b+e_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -b -n input.txt input3.txt input2.txt > s21_cat_out
cat -b -n input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_b+n_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_b+n_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -b -s input.txt input3.txt input2.txt > s21_cat_out
cat -b -s input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_b+s_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_b+s_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -b -t input.txt input3.txt input2.txt > s21_cat_out
cat -b -t input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_b+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_b+t_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -e -n input.txt input3.txt input2.txt > s21_cat_out
cat -e -n input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_e+n_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_e+n_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -e -s input.txt input3.txt input2.txt > s21_cat_out
cat -e -s input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_e+s_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_e+s_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -e -t input.txt input3.txt input2.txt > s21_cat_out
cat -e -t input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_e+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_e+t_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -n -s input.txt input3.txt input2.txt > s21_cat_out
cat -n -s input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_n+s_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_n+s_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -n -t input.txt input3.txt input2.txt > s21_cat_out
cat -n -t input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_n+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_n+t_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -s -t input.txt input3.txt input2.txt > s21_cat_out
cat -s -t input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_s+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_s+t_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -b -e -n input.txt input3.txt input2.txt > s21_cat_out
cat -b -e -n input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_b+e+n_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_b+e+n_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -b -e -s input.txt input3.txt input2.txt > s21_cat_out
cat -b -e -s input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_b+e+s_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_b+e+s_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -b -e -t input.txt input3.txt input2.txt > s21_cat_out
cat -b -e -t input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_b+e+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_b+e+t_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -e -n -s input.txt input3.txt input2.txt > s21_cat_out
cat -e -n -s input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_e+n+s_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_e+n+s_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -e -n -t input.txt input3.txt input2.txt > s21_cat_out
cat -e -n -t input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_e+n+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_e+n+t_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -n -s -t input.txt input3.txt input2.txt > s21_cat_out
cat -n -s -t input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_n+s+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_n+s+t_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -s -t -b input.txt input3.txt input2.txt > s21_cat_out
cat -s -t -b input.txt input3.txt input2.txt > cat_out

if cmp -s cat_out s21_cat_out ; then
 echo Test_s+t+b_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_s+t+b_fail ${FAIL_CHAR}${TO_DEFAULT}
 cat_out
  exit
fi
##############
./s21_cat -b -e -n -s input.txt input2.txt > s21_cat_out
cat -b -e -n -s input.txt input2.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test2_b+e+n+s_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test2_b+e+n+s_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -b -e -n -t input.txt input2.txt > s21_cat_out
cat -b -e -n -t input.txt input2.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test2_b+e+n+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test2_b+e+n+t_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -b -e -s -t input.txt input2.txt > s21_cat_out
cat -b -e -s -t input.txt input2.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test2_b+e+s+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test2_b+e+s+t_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -b -n -s -t input.txt input2.txt > s21_cat_out
cat -b -n -s -t input.txt input2.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test2_b+n+s+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test2_b+n+s+t_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -e -n -s -t input.txt input2.txt > s21_cat_out
cat -e -n -s -t input.txt input2.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test2_e+n+s+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test2_e+n+s+t_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -b -e -n -s -t input.txt input2.txt > s21_cat_out
cat -b -e -n -s -t input.txt input2.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test2_b+e+n+s+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test2_b+e+n+s+t_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -b input.txt input2.txt input.txt > s21_cat_out
cat -b input.txt input2.txt input.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test3_b_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test3_b_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -bte input.txt input2.txt input.txt > s21_cat_out
cat -bte input.txt input2.txt input.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test3_bte_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test3_bte_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -btens input2.txt input.txt input3.txt > s21_cat_out
cat -btens input2.txt input.txt input3.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test3_btens_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test3_btens_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat --number-nonblank --squeeze-blank input.txt input2.txt input3.txt > s21_cat_out
cat -b -s input.txt input2.txt input3.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test3_long_b_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test3_long_b_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -t nonreaderble.txt > s21_cat_out
cat -t nonreaderble.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test_nonreaderble+t_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_nonreaderble+t_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -e nonreaderble.txt > s21_cat_out
cat -e nonreaderble.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test_nonreaderble+e_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_nonreaderble+e_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############
./s21_cat -be nonreaderble.txt input.txt > s21_cat_out
cat -be nonreaderble.txt input.txt > cat_out
if cmp -s cat_out s21_cat_out ; then
 echo Test_nonreaderble+btens_ ${DONE_CHAR}${TO_DEFAULT}
 else
  echo Test_nonreaderble+btens_fail ${FAIL_CHAR}${TO_DEFAULT}
  exit
fi
##############

rm -rf *.txt

echo ${GREEN_BACK}'→→→' $'\e[0;05m All Test Done!'${TO_DEFAULT}