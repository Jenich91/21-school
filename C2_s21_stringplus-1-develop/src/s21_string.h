#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdarg.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#ifndef s21_NULL
#define s21_NULL ((void *)0)
#endif

typedef unsigned int s21_size_t;

#define allsymbol "cdieEfgGosuxXpn%"

struct Param {
    int flag1, flag2, flag3, flag4, flag, width, accuracy, ERROR, plus, dot, itoa;
    char MOD;
    char length;
};

void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strrchr(const char *str, int c);
char *s21_strtok(char *s, const char *delim);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

char *s21_itoa(int n, char *mass);
char *s21_reverse(char *str);
int signum(int VALUE);

int s21_sprintf(char *str, const char *format, ...);
void s21_parsing(char* symbol, struct Param* pars);
void* s21_ReadSpecific(struct Param* spec_f, va_list* argc, char* str);
char* s21_WriteFlags(char* BUF, struct Param* mass_f, int* index, s21_size_t* LEN);
char* s21_sprintf_d(char* BUF, struct Param* mass_f, int* index, s21_size_t* LEN);
void s21_ClearFlag(struct Param* flag_c);
char* s21_ditoa(unsigned long long int n, char *TMP);
void* s21_FDot(char* TMP, struct Param* float_t, long double conv_f);
char* s21_accuracy_s(char *TMP, int len);
void s21_sprintf_s(char* BUF, struct Param* mass_f, int* index, s21_size_t* LEN);
void s21_sprintfRigth(char* BUF, struct Param* mass_f, int* index, s21_size_t* LEN);

#endif  // SRC_S21_STRING_H_
