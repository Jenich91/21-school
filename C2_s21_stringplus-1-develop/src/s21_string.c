#include "s21_string.h"

// 1
// void *memchr(const void *str, int c, size_t n)
// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = s21_NULL;
  int breakFlag = 0;

  for (s21_size_t i = 0; i < n && breakFlag == 0; i++) {
    if (*((char *)str + i) == c) {
      res = (char *)str + i;
      breakFlag = 1;
    }
  }
  return res;
}

// 2
// int memcmp(const void *str1, const void *str2, size_t n)
// Сравнивает первые n байтов str1 и str2.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const char *p_Str1 = str1;
  const char *p_Str2 = str2;
  int res;

  if (n == 0) {
    res = 0;
  } else {
    while (--n && *p_Str1 == *p_Str2) {
      p_Str1++;
      p_Str2++;
    }
    res = *p_Str1 - *p_Str2;
  }

  return res;
}

// 3
// void *memcpy(void *dest, const void *src, size_t n)
// Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  void *startDest = dest;

  char *ptrdest = dest;
  const char *ptrsrc = src;

  while (n--) {
    *ptrdest = *ptrsrc;

    ptrdest++;
    ptrsrc++;
  }

  return startDest;
}

// 4
// void *memmove(void *dest, const void *src, size_t n)
// Еще одна функция для копирования n символов из str2 в str1.
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *ptrdest = dest;
  const char *ptrsrc = src;
  s21_size_t i;
  for (i = 0; i < n; i++) {
    ptrdest[i] = ptrsrc[i];
  }
  return ptrdest;
}

// 5
// void *memset(void *str, int c, size_t n)
// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str.
void *s21_memset(void *str, int c, s21_size_t n) {
  char *istr = str;
  int i = 0;
  while (n > 0) {
    istr[i] = c;
    i++;
    n--;
  }
  return istr;
}

// 6
// char *strcat(char *dest, const char *src)
// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest.
char *s21_strcat(char *dest, const char *src) {
  int i = 0;
  int j = 0;
  for (; dest[i] != '\0'; i++) {
  }
  for (; src[j] != '\0'; j++) {
    dest[i + j] = src[j];
  }
  dest[i + j] = '\0';

  return dest;
}

// 7
// char *strncat(char *dest, const char *src, size_t n)
// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p_dest_start = dest;

  while (*dest != '\0') {
    dest++;
  }

  s21_size_t i = 0;
  while (*src != '\0' && i < n) {
    *dest = *src;
    dest++, src++;

    i++;
  }

  *dest = '\0';

  return p_dest_start;
}

// 8
// char *strchr(const char *str, int c)
// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strchr(const char *str, int ch) {
  char *res;
  int exitFlag = 0;

  for (; *str != (char)ch && exitFlag == 0; str++) {
    if (*str == '\0') {
      res = s21_NULL;
      exitFlag = 1;
    }
  }

  if (exitFlag == 0) {
    res = (char *)str;
  }

  return res;
}

// 9
// int strcmp(const char *str1, const char *str2)
// Сравнивает строку, на которую указывает str1, со строкой, на которую
// указывает str2.
int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
    str1++;
    str2++;
  }

  return *str1 - *str2;
}

// 10
// int strncmp(const char *str1, const char *str2, size_t n)
// Сравнивает не более первых n байтов str1 и str2.

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res;
  int exitFlag = 0;

  char ch1 = '\0';
  char ch2 = '\0';
  s21_size_t i = 0;

  while (i < n && n > 0 && exitFlag == 0) {
    ch1 = str1[i];
    ch2 = str2[i];
    i++;
    if (ch1 == '\0' || ch2 == '\0' || ch1 != ch2) {
      res = ch1 - ch2;
      exitFlag = 1;
    }
  }

  if (exitFlag == 0) {
    res = ch1 - ch2;
  }

  return res;
}

// 11
// char *strcpy(char *dest, const char *src)
// Копирует строку, на которую указывает src, в dest.
char *s21_strcpy(char *dest, const char *src) {
  char *dest_start = dest;
  *dest = *src;

  while (*src != '\0') {
      src++, dest++;
      *dest = *src;
  }

  return dest_start;
}

// 12
// char *strncpy(char *dest, const char *src, size_t n)
// Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *p_dest_start = dest;

  s21_size_t i = 0;
  while (i < n) {
    if (*src != '\0') {
      *dest = *src;
      dest++, src++;
    } else {
      *dest = '\0';
      dest++;
    }

    i++;
  }

  return p_dest_start;
}

// 13
// size_t strcspn(const char *str1, const char *str2)
// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  int exitFlag = 0;

  for (int i = 0; str1[i] != 0; i++, len++) {
    for (int j = 0; str2[j]; j++) {
      if (str1[i] == str2[j]) {
        exitFlag = 1;
      }
    }
    if (exitFlag == 1) break;
  }
  return len;
}

// 14
// char *strerror(int errnum)
// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке. Нужно объявить макросы,
// содержащие массивы сообщений об ошибке для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
// осуществляется с помощью директив.

char *s21_strerror(int errnum) {
  const char *res = s21_NULL;

#ifdef __linux__
  int COUNT = 133;
  char *Error[] = {"Success",
                   "Operation not permitted",
                   "No such file or directory",
                   "No such process",
                   "Interrupted system call",
                   "Input/output error",
                   "No such device or address",
                   "Argument list too long",
                   "Exec format error",
                   "Bad file descriptor",

                   "No child processes",
                   "Resource temporarily unavailable",
                   "Cannot allocate memory",
                   "Permission denied",
                   "Bad address",
                   "Block device required",
                   "Device or resource busy",
                   "File exists",
                   "Invalid cross-device link",
                   "No such device",

                   "Not a directory",
                   "Is a directory",
                   "Invalid argument",
                   "Too many open files in system",
                   "Too many open files",
                   "Inappropriate ioctl for device",
                   "Text file busy",
                   "File too large",
                   "No space left on device",
                   "Illegal seek",

                   "Read-only file system",
                   "Too many links",
                   "Broken pipe",
                   "Numerical argument out of domain",
                   "Numerical result out of range",
                   "Resource deadlock avoided",
                   "File name too long",
                   "No locks available",
                   "Function not implemented",
                   "Directory not empty",

                   "Too many levels of symbolic links",
                   "Unknown error 41",
                   "No message of desired type",
                   "Identifier removed",
                   "Channel number out of range",
                   "Level 2 not synchronized",
                   "Level 3 halted",
                   "Level 3 reset",
                   "Link number out of range",
                   "Protocol driver not attached",

                   "No CSI structure available",
                   "Level 2 halted",
                   "Invalid exchange",
                   "Invalid request descriptor",
                   "Exchange full",
                   "No anode",
                   "Invalid request code",
                   "Invalid slot",
                   "Unknown error 58",
                   "Bad font file format",

                   "Device not a stream",
                   "No data available",
                   "Timer expired",
                   "Out of streams resources",
                   "Machine is not on the network",
                   "Package not installed",
                   "Object is remote",
                   "Link has been severed",
                   "Advertise error",
                   "Srmount error",

                   "Communication error on send",
                   "Protocol error",
                   "Multihop attempted",
                   "RFS specific error",
                   "Bad message",
                   "Value too large for defined data type",
                   "Name not unique on network",
                   "File descriptor in bad state",
                   "Remote address changed",
                   "Can not access a needed shared library",

                   "Accessing a corrupted shared library",
                   ".lib section in a.out corrupted",
                   "Attempting to link in too many shared libraries",
                   "Cannot exec a shared library directly",
                   "Invalid or incomplete multibyte or wide character",
                   "Interrupted system call should be restarted",
                   "Streams pipe error",
                   "Too many users",
                   "Socket operation on non-socket",
                   "Destination address required",

                   "Message too long",
                   "Protocol wrong type for socket",
                   "Protocol not available",
                   "Protocol not supported",
                   "Socket type not supported",
                   "Operation not supported",
                   "Protocol family not supported",
                   "Address family not supported by protocol",
                   "Address already in use",
                   "Cannot assign requested address",

                   "Network is down",
                   "Network is unreachable",
                   "Network dropped connection on reset",
                   "Software caused connection abort",
                   "Connection reset by peer",
                   "No buffer space available",
                   "Transport endpoint is already connected",
                   "Transport endpoint is not connected",
                   "Cannot send after transport endpoint shutdown",
                   "Too many references: cannot splice",

                   "Connection timed out",
                   "Connection refused",
                   "Host is down",
                   "No route to host",
                   "Operation already in progress",
                   "Operation now in progress",
                   "Stale file handle",
                   "Structure needs cleaning",
                   "Not a XENIX named type file",
                   "No XENIX semaphores available",

                   "Is a named type file",
                   "Remote I/O error",
                   "Disk quota exceeded",
                   "No medium found",
                   "Wrong medium type",
                   "Operation canceled",
                   "Required key not available",
                   "Key has expired",
                   "Key has been revoked",
                   "Key was rejected by service",
                   "Owner died",
                   "State not recoverable",
                   "Operation not possible due to RF-kill",
                   "Memory page has hardware error",
                   "Unknown error "};
#elif (__APPLE__) || (__MACH__)
  int COUNT = 106;
  char *Error[] = {
      "Undefined error: 0",
      "Operation not permitted",
      "No such file or directory",
      "No such process",
      "Interrupted system call",
      "Input/output error",
      "Device not configured",
      "Argument list too long",
      "Exec format error",
      "Bad file descriptor",

      "No child processes",
      "Resource deadlock avoided",
      "Cannot allocate memory",
      "Permission denied",
      "Bad address",
      "Block device required",
      "Resource busy",
      "File exists",
      "Cross-device link",
      "Operation not supported by device",

      "Not a directory",
      "Is a directory",
      "Invalid argument",
      "Too many open files in system",
      "Too many open files",
      "Inappropriate ioctl for device",
      "Text file busy",
      "File too large",
      "No space left on device",
      "Illegal seek",

      "Read-only file system",
      "Too many links",
      "Broken pipe",
      "Numerical argument out of domain",
      "Result too large",
      "Resource temporarily unavailable",
      "Operation now in progress",
      "Operation already in progress",
      "Socket operation on non-socket",
      "Destination address required",

      "Message too long",
      "Protocol wrong type for socket",
      "Protocol not available",
      "Protocol not supported",
      "Socket type not supported",
      "Operation not supported",
      "Protocol family not supported",
      "Address family not supported by protocol family",
      "Address already in use",
      "Can't assign requested address",

      "Network is down",
      "Network is unreachable",
      "Network dropped connection on reset",
      "Software caused connection abort",
      "Connection reset by peer",
      "No buffer space available",
      "Socket is already connected",
      "Socket is not connected",
      "Can't send after socket shutdown",
      "Too many references: can't splice",

      "Operation timed out",
      "Connection refused",
      "Too many levels of symbolic links",
      "File name too long",
      "Host is down",
      "No route to host",
      "Directory not empty",
      "Too many processes",
      "Too many users",
      "Disc quota exceeded",

      "Stale NFS file handle",
      "Too many levels of remote in path",
      "RPC struct is bad",
      "RPC version wrong",
      "RPC prog. not avail",
      "Program version wrong",
      "Bad procedure for program",
      "No locks available",
      "Function not implemented",
      "Inappropriate file type or format",

      "Authentication error",
      "Need authenticator",
      "Device power is off",
      "Device error",
      "Value too large to be stored in data type",
      "Bad executable (or shared library)",
      "Bad CPU type in executable",
      "Shared library version mismatch",
      "Malformed Mach-o file",
      "Operation canceled",

      "Identifier removed",
      "No message of desired type",
      "Illegal byte sequence",
      "Attribute not found",
      "Bad message",
      "EMULTIHOP (Reserved)",
      "No message available on STREAM",
      "ENOLINK (Reserved)",
      "No STREAM resources",
      "Not a STREAM",

      "Protocol error",
      "STREAM ioctl timeout",
      "Operation not supported on socket",
      "Policy not found",
      "State not recoverable",
      "Previous owner died",
      "Interface output queue is full",
      "Unknown error: ",
  };
#endif

  if (errnum <= COUNT && errnum >= 0) {
    res = Error[errnum];
  } else {
#ifdef __linux__
    static char lastStr[32] = "Unknown error ";
    char numErr[50] = "";
    s21_itoa(errnum, numErr);
    s21_strncpy(lastStr + 14, "", s21_strlen(numErr));
    res = s21_strcat(lastStr, numErr);
#elif (__APPLE__) || (__MACH__)
    static char lastStr[32] = "Unknown error: ";
    char numErr[50] = "";
    s21_itoa(errnum, numErr);
    s21_strncpy(lastStr + 15, "", s21_strlen(numErr));
    res = s21_strcat(lastStr, numErr);
#endif
  }

  return (char *)res;
}

// 15
// size_t strlen(const char *str)
// Вычисляет длину строки str, не включая завершающий нулевой символ.
s21_size_t s21_strlen(const char *str) {
  int len = 0;
  while (*str != '\0') {
    str++;
    len++;
  }

  return len;
}

// 16
// char *strpbrk(const char *str1, const char *str2)
// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;
  int exitFlag = 0;

  for (int i = 0; str1[i] != 0 && exitFlag == 0; i++) {
    for (int j = 0; str2[j] != 0; j++) {
      if (str1[i] == str2[j]) {
        res = (char *)str1 + i;
        exitFlag = 1;
        break;
      }
    }
  }

  return res;
}

// 17
// char *strrchr(const char *str, int c)
// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strrchr(const char *str, int c) {
  const char *last_occurrence = s21_NULL;

  while (*str != '\0') {
    if (*str == (char)c) {
      last_occurrence = str;
    }
    str++;
  }

  if (c == '\0') {
    last_occurrence = str;
  }

  return (char *)last_occurrence;
}

// 18
// size_t strspn(const char *str1, const char *str2)
// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов str2.
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  int exitFlag = 0;

  const char *ptr1;
  const char *ptr2;
  for (ptr1 = str1; *ptr1 && exitFlag == 0; ptr1++) {
    for (ptr2 = str2;; ptr2++) {
      if (*ptr2 == '\0') {
        res = (ptr1 - str1);
        exitFlag = 1;
        break;
      } else if (*ptr1 == *ptr2) {
        break;
      }
    }
  }

  if (exitFlag == 0) {
    res = (ptr1 - str1);
  }

  return res;
}

// 19
// char *strstr(const char *haystack, const char *needle)
// Находит первое вхождение всей строки needle (не включая завершающий нулевой
// символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;
  int exitFlag = 0;

  if (*needle == '\0') {
    res = (char *)haystack;
    exitFlag = 1;
  }
  if (exitFlag == 0) {
    for (int i = 0; haystack[i] != '\0' && exitFlag == 0; i++) {
      int temp = i;
      int j = 0;
      while (haystack[i++] == needle[j++]) {
        if (needle[j] == '\0') {
          res = (char *)&haystack[temp];
          exitFlag = 1;
          break;
        }
      }
      i = temp;
    }
  }

  return res;
}

// 20
// char *strtok(char *str, const char *delim)
// Разбивает строку str на ряд токенов, разделенных delim.
char *s21_strtok(char *s, const char *delim) {
  char *res = 0;
  int exitFlag = 0;
  static char *lasts;
  register int ch;

  if (s == 0) s = lasts;
  do {
    if ((ch = *s++) == '\0') {
      exitFlag = 1;
    }
  } while (s21_strchr(delim, ch) && exitFlag == 0);
  if (exitFlag == 0) {
    --s;
    lasts = s + s21_strcspn(s, delim);
    if (*lasts != 0) {
      *lasts++ = 0;
    }
    res = s;
  }

  return res;
}

// Специальные функции обработки строк

// 1
// void *to_upper(const char *str)
// Возвращает копию строки (str), преобразованной в верхний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_to_upper(const char *str) {
  char *buf = calloc(s21_strlen(str) + 1, sizeof(char));
  char *buf_t = buf;
  for (int i = 0; str[i] != '\0'; i++) {
    if ((str[i] > 96) && (str[i] < 123)) {
      buf_t[i] = str[i] - 32;
    } else {
      buf_t[i] = str[i];
    }
  }
  return buf_t;
}

// 2
// void *to_lower(const char *str)
// Возвращает копию строки (str), преобразованной в нижний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_to_lower(const char *str) {
  char *buf = calloc(s21_strlen(str) + 1, sizeof(char));
  char *buf_t = buf;
  for (int i = 0; str[i] != '\0'; i++) {
    if ((str[i] > 64) && (str[i] < 91)) {
      buf_t[i] = str[i] + 32;
    } else {
      buf_t[i] = str[i];
    }
  }
  return buf_t;
}

// 3
// void *insert(const char *src, const char *str, size_t start_index)
// Возвращает новую строку, в которой указанная строка (str) вставлена
// в указанную позицию (start_index) в данной строке (src).
// В случае какой-либо ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  void *res = 0;
  s21_size_t srcLen = s21_strlen(src);
  s21_size_t strLen = s21_strlen(str);
  s21_size_t maxLen = srcLen + strLen + 1;

  if (((int)start_index < 0 || start_index >= maxLen ||
       start_index > s21_strlen(src))) {
    res = s21_NULL;
  } else {
    char *buf = calloc(s21_strlen(str) + 1, sizeof(char));
    char *buf_t = buf;

    s21_size_t j = 0;
    s21_size_t i = 0;
    s21_size_t len = s21_strlen(src);

    if (srcLen == 0) {
      for (j = 0; str[j] != 0; j++) {
        buf_t[j] = str[j];
      }
    }

    for (; src[i] != 0; i++) {
      if (i == start_index) {
        for (j = 0; str[j] != 0; j++) {
          buf_t[i + j] = str[j];
        }
      }
      buf_t[i + j] = src[i];
    }
    if (len == start_index) {
      for (int b = 0; str[b] != 0; i++, b++) {
        buf_t[i] = str[b];
      }
    }
    res = buf_t;
  }
  return res;
}

// 4
// void *trim(const char *src, const char *trim_chars)
// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL
void *s21_trim(const char *src, const char *trim_chars) {
  void *res;
  if (src == s21_NULL) {
    res = s21_NULL;
  } else {
    char whiteSpaceCharacters[8] = " \n\t";

    if (trim_chars == s21_NULL) {
      trim_chars = whiteSpaceCharacters;
    }

    if (s21_strlen(trim_chars) == 0) {
      s21_strcpy((char *)trim_chars, whiteSpaceCharacters);
    }

    char *src_t = (char* )calloc(s21_strlen(src) + 1, sizeof(char));
    s21_strcpy(src_t, src);

    int p = 0;
    int j = 0;
    int l = 1;
    int len = s21_strlen(src);
    while (j < len) {
      for (int i = 0; trim_chars[i] != 0; i++) {
        if (src_t[p] == trim_chars[i]) {
          p++;
        }
        if (src_t[len - l] == trim_chars[i]) {
          l++;
        }
      }
      j++;
    }
    src_t[len - l + 1] = '\0';
    src_t = src_t + p;

    char *str_temp = (char* )calloc(s21_strlen(src_t) + 1, sizeof(char));
    s21_strcpy(str_temp, src_t);
    res = str_temp;

    free(src_t - p);
  }

  return res;
}

/////////// internal funcs ///////////
char *s21_itoa(int n, char *mass) {
  int i = 0;
  int sign;
  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    mass[i] = n % 10 + '0';
    i++;
  } while ((n /= 10) > 0);
  if (sign < 0) {
    mass[i] = '-';
    i++;
  }
  s21_reverse(mass);
  mass[i++] = '\0';
  return mass;
}

char *s21_reverse(char *str) {
    char tmp, *src, *dst;
    int len;
    if (str != s21_NULL) {
        len = s21_strlen(str);
        if (len > 1) {
            src = str;
            dst = src + len - 1;
            while (src < dst) {
                tmp = *src;
                *src++ = *dst;
                *dst-- = tmp;
            }
        }
    }
    return str;
}

int signum(int VALUE) {
  return (VALUE > 0 ? 1 : (VALUE < 0 ? -1 : 0));
}

/////////// sprintf ///////////
int s21_sprintf(char* str, const char* format, ...) {
    struct Param status = {-1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, '0', '0'};
    s21_size_t len_i = 0;
    int i = 0;
    char *MainSymbol;
    char *TMP;
    MainSymbol = (char*)format;
    va_list factor;
    va_start(factor, format);
    for (; *MainSymbol; MainSymbol++, i++) {
        if (*MainSymbol == '%') {
            char Buff[200] = "";
            MainSymbol++;
            s21_parsing(MainSymbol, &status);
            MainSymbol += status.itoa;
            TMP = s21_ReadSpecific(&status, &factor, Buff);
            len_i = s21_strlen(TMP);
            s21_WriteFlags(str, &status, &i, &len_i);
            s21_strcat(str, TMP);
            s21_sprintfRigth(str, &status, &i, &len_i);
            status.flag = 1;
            i +=len_i - 1;
            va_end(factor);
        }
        if (status.flag == -1) str[i] = *MainSymbol;
        s21_ClearFlag(&status);
    }
    return i;
}

void s21_parsing(char* symbol, struct Param* pars) {
    s21_size_t lenPars = s21_strcspn(symbol, allsymbol);
    pars -> itoa = lenPars;
    pars -> MOD = *(symbol+lenPars);
    int width_pars = 0;
    int H = 0;
    while (width_pars < (int)lenPars) {
        switch (*symbol) {
            case '-':
                    pars -> flag1 = (pars -> flag4 < 0) ? 1 : 2;
                    width_pars +=1;
                    break;
            case '+':
                    pars -> flag2 = (pars -> flag4 < 0) ? 1 : 2;
                    width_pars +=1;
                    break;
            case ' ':
                    pars -> flag3 = 1;
                    width_pars +=1;
                    break;
            case '.':
                    pars -> accuracy = 0;
                    pars -> flag4 = 1;
                    width_pars +=1;
                    break;
            case '0':
                    width_pars +=1;
                    break;
            case 'l':
                    pars -> length = 'l';
                    width_pars +=1;
                    break;
            case 'L':
                    pars -> length = 'L';
                    width_pars +=1;
                    break;
            case 'h':
                    pars -> length = 'h';
                    width_pars +=1;
                    break;
        }
        char BUF[100] = "";
        s21_size_t range = 0;
        if ((*symbol > 0 + '0') && (*symbol <= 9 + '0')) {
            range = s21_strlen(s21_ditoa(atoi(symbol), BUF));
            H = atoi(symbol);
            if (pars -> flag4 < 0) {
                pars -> width = H;
            }
            if (pars -> flag4 > 0) {
                pars -> accuracy = H;
            }
        }
        if (range != 0) {
            symbol += range;
            width_pars += range;
            H = 0;
        } else {
            symbol++;
        }
    }
        if ((pars -> flag1 == 2) || (pars -> flag2 == 2)) {
            pars -> width = pars -> accuracy;
            pars -> accuracy = 0;
        }
}

void* s21_ReadSpecific(struct Param* spec_f, va_list* argc, char* str) {
    signed long long int REZ_I = 0;
    unsigned long long int G = 0;
    long double REZ_D = 0;

    switch (spec_f -> MOD) {
        case 'i':
            REZ_I = va_arg(*argc, signed long long int);
            REZ_I = spec_f -> length == 'h' ? (short int)REZ_I : spec_f -> length == 'l' ? REZ_I : (int)REZ_I;
            if (REZ_I < 0) {
                spec_f -> plus = 1;
                REZ_I *= -1;
            }
            str = s21_ditoa(REZ_I, str);
            break;
        case 'd':
            REZ_I = va_arg(*argc, signed long long int);
            REZ_I = spec_f -> length == 'h' ? (short int)REZ_I : spec_f -> length == 'l' ? REZ_I : (int)REZ_I;
            if (REZ_I < 0) {
                spec_f -> plus = 1;
                REZ_I *= -1;
            }
            s21_ditoa(REZ_I, str);
            break;
        case 'u':
            G = va_arg(*argc, unsigned long long int);
            G = spec_f->length == 'h' ? (unsigned short int)G : spec_f->length == 'l' ? G
                                                                                      : (unsigned int)G;
             s21_ditoa(G, str);
            break;
        case 's':
            if (spec_f -> length == 'l') {
              if (spec_f -> accuracy > -1) {
              wcstombs(str, (wchar_t*)va_arg(*argc, wchar_t*), spec_f -> accuracy);
              } else {
                const wchar_t* F = (wchar_t*)va_arg(*argc, wchar_t*);
                wcstombs(str, F, 16 * wcslen(F));
              }
              break;
            }
            str = spec_f -> accuracy > - 1 ? s21_strncpy(str, (char*)va_arg(*argc, int*),
                                         spec_f -> accuracy) : (char*)va_arg(*argc, int*);
            break;
        case 'f':
            REZ_D = spec_f -> length == 'L' ? va_arg(*argc, long double) : va_arg(*argc, double);
            double check = 1;
            check = copysignl(check, REZ_D);
            if ((REZ_D < 0) || (check < 0)) {
                spec_f -> plus = 1;
                REZ_D *= -1;
            }
            if (spec_f -> accuracy < 0) {
                spec_f -> accuracy = 6;
            }
            REZ_D += 0.5 * pow(10, -spec_f -> accuracy);
            if (spec_f -> accuracy == 0) {
                s21_ditoa(REZ_D, str);
            } else {
                s21_FDot(str, spec_f, REZ_D);
            }
            break;
        case'c':
            if (spec_f -> length == 'l') {
            wctomb(str, va_arg(*argc, wchar_t));
            } else {
              str[0] = (char)va_arg(*argc, int);
              str[1] = '\0';
            }
            break;
        case'%':
            str[0] = '%';
            str[1] = '\0';
            break;
    }
    return str;
}
char* s21_WriteFlags(char* BUF, struct Param* mass_f, int* index, s21_size_t* LEN) {
    switch (mass_f -> MOD) {
        case 'd':
            BUF = s21_sprintf_d(BUF, mass_f, index, LEN);
            break;
        case 'i':
            BUF = s21_sprintf_d(BUF, mass_f, index, LEN);
            break;
        case 'u':
             s21_sprintf_s(BUF, mass_f, index, LEN);
            break;
        case 's':
             s21_sprintf_s(BUF, mass_f, index, LEN);
            break;
        case 'c':
             s21_sprintf_s(BUF, mass_f, index, LEN);
            break;
        case 'f':
            BUF = s21_sprintf_d(BUF, mass_f, index, LEN);
            break;
        case '%':
            s21_sprintf_s(BUF, mass_f, index, LEN);
            break;
    }

    return BUF;
}

void s21_sprintfRigth(char* BUF, struct Param* mass_f, int* index, s21_size_t* LEN) {
            while (mass_f -> width > (int) * LEN && mass_f -> flag1 > 0) {
                BUF[*index + *LEN] = ' ';
                *index +=1;
                mass_f -> width--;
            }
}

char* s21_sprintf_d(char* BUF, struct Param* mass_f, int* index, s21_size_t* LEN) {
    if ((mass_f -> flag3 > 0) && (mass_f -> flag2 < 0) && (mass_f -> plus != 1)) {
                BUF[*index] = ' ';
                *index +=1;
                mass_f -> width--;
        }
    if ((mass_f -> plus == 1) || (mass_f -> flag2 > 0)) {
                mass_f -> width--;
    }
    if (mass_f -> width || mass_f -> accuracy) {
        while (mass_f -> width > (int)*LEN && mass_f -> width > mass_f -> accuracy && mass_f -> flag1 < 1) {
            BUF[*index] = ' ';
            *index +=1;
            mass_f -> width--;
        }
        if (mass_f -> plus == 1) {
            BUF[*index] = '-';
            *index +=1;
        }
        if ((mass_f -> plus == 0) && (mass_f -> flag2 > 0)) {
            BUF[*index] = '+';
            *index +=1;
        }
        while (mass_f -> accuracy > (int)*LEN && mass_f -> MOD != 'f') {
            BUF[*index] = '0';
            *index +=1;
            mass_f -> accuracy--;
            mass_f -> width--;
        }
    }
    return BUF;
}
void s21_ClearFlag(struct Param* flag_c) {
    flag_c -> ERROR = 0;
    flag_c -> flag1 = -1;
    flag_c -> flag2 = -1;
    flag_c -> flag3 = -1;
    flag_c -> flag4 = -1;
    flag_c -> width = -1;
    flag_c -> flag = -1;
    flag_c -> plus = 0;
    flag_c -> accuracy = -1;
    flag_c -> itoa = 0;
    flag_c -> MOD = '\0';
    flag_c -> length = '\0';
}
char* s21_ditoa(unsigned long long int n, char *TMP) {
    int i = 0;
    do {
     TMP[i++] = n % 10 + '0';
    } while ((n /= 10) > 0.0);
    s21_reverse(TMP);
    TMP[i++] = '\0';
    return TMP;
}

void* s21_FDot(char* TMP, struct Param* float_t, long double conv_f) {
    s21_size_t len = 0;
    long double a = 0;
    long double b = 0;
    char BUF[100] = "";
    a = modfl(conv_f, &b);
    s21_ditoa(b, TMP);
    len = s21_strlen(TMP);
    TMP[len] = '.';
    int c = 0;
    s21_size_t m = 0;
    for (m = len + 1; a - (int)a > 0 && 0 < float_t -> accuracy; m++, float_t -> accuracy--) {
        c = 10 * a - (int)a * 10;
        if (c < 1) {
            TMP[m] = '0';
        }
        a *= 10;
    }
    for (m = len + 1;  0 < float_t -> accuracy; m++, float_t -> accuracy--) {
        TMP[m] = '0';
    }
    if ((int)a != 0) {
        s21_ditoa(a, BUF);
    }
    TMP = s21_strcat(TMP, BUF);
    return TMP;
}

void s21_sprintf_s(char* BUF, struct Param* mass_f, int* index, s21_size_t* LEN) {
    if ((mass_f -> accuracy > mass_f -> width) && (mass_f -> MOD != 'u')) {
        mass_f -> accuracy = 0;
    }
    if (mass_f -> width || mass_f -> accuracy) {
        while (mass_f -> width > (int)* LEN && mass_f -> width > mass_f -> accuracy && mass_f -> flag1 < 1) {
            BUF[*index] = ' ';
            *index +=1;
            mass_f -> width--;
        }
        while (mass_f -> accuracy > (int)* LEN && mass_f -> flag1 < 0 && mass_f -> accuracy > 0) {
            BUF[*index] = mass_f -> MOD == 'u' ? '0' : ' ';
            *index +=1;
            mass_f -> accuracy--;
            mass_f -> width--;
        }
    }
}
