#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <stdbool.h>

struct Flag {
    int e, i, v, c, l, n, h, s, f, o, regflag;
}flag = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

#endif  // SRC_GREP_S21_GREP_H_

void s21_grep(int argc, char const *argv[]);
void buildOutput(const char** filePathArr, size_t filesCount,
                 regex_t* redexArr, size_t redexCount, int emptyPatternFlag);
