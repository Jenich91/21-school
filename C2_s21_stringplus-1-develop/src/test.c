#include <check.h>
#include <errno.h>
#include <string.h>
#include "s21_string.h"
#include <wchar.h>
#include <locale.h>

START_TEST(memchrTest) {
  char str1[55] = "qwerty\n54321";
  str1[9] = '\0';
  str1[11] = '\123';
  ck_assert_ptr_eq(s21_memchr(str1, (int)'1', strlen(str1)),
                   memchr(str1, (int)'1', strlen(str1)));
  ck_assert_ptr_eq(s21_memchr(str1, (int)'t', strlen(str1)),
                   memchr(str1, (int)'t', strlen(str1)));
  ck_assert_ptr_eq(s21_memchr(str1, (int)'Z', strlen(str1)),
                   memchr(str1, (int)'Z', strlen(str1)));
  ck_assert_ptr_eq(s21_memchr(str1, (int)'\0', strlen(str1)),
                   memchr(str1, (int)'\0', strlen(str1)));
  ck_assert_ptr_eq(s21_memchr(str1, (int)'q', 0), memchr(str1, (int)'q', 0));
  char str2[5] = "";
  ck_assert_ptr_eq(s21_memchr(str2, (int)'q', 5), memchr(str2, (int)'q', 5));
  char str3[] = "абоба";
  ck_assert_ptr_eq(s21_memchr(str3, str3[3], strlen(str3)),
                   memchr(str3, str3[3], strlen(str3)));
  ck_assert_ptr_eq(s21_memchr(str1, (int)'\034', 0),
                   memchr(str1, (int)'\034', 0));
}
END_TEST

START_TEST(memcmpTest) {
  char str1[10] = "zzzzz";
  char str2[10] = "aaaaa";
  ck_assert_int_eq(signum(s21_memcmp(str1, str2, 5)), signum(memcmp(str1, str2, 5)));
  char str3[10] = "aaaaa";
  char str4[10] = "zzzzz";
  ck_assert_int_eq(signum(s21_memcmp(str3, str4, 2)), signum(memcmp(str3, str4, 2)));
  ck_assert_int_eq(signum(s21_memcmp(str3, str4, 0)), signum(memcmp(str3, str4, 0)));
  char str5[10] = "\naaab";
  char str6[10] = "aaaaa";
  ck_assert_int_eq(signum(s21_memcmp(str5, str6, 5)), signum(memcmp(str5, str6, 5)));
  char str7[10] = "aaaa!";
  char str8[10] = "aa\0a@";
  ck_assert_int_eq(signum(s21_memcmp(str7, str8, 5)), signum(memcmp(str7, str8, 5)));
  char str9[10] = "░";
  char str10[10] = "¶";
  ck_assert_int_eq(signum(s21_memcmp(str9, str10, 5)), signum(memcmp(str9, str10, 5)));
}
END_TEST

START_TEST(memcpyTest) {
  char dest1[10] = "";
  char dest2[10] = "";
  char src1[10] = "zzzzz";

  int len = strlen(src1);
  ck_assert_str_eq(s21_memcpy(dest1, src1, len), memcpy(dest2, src1, len));

  char dest3[10] = "";
  char dest4[10] = "";
  char str2[10] = "";
  len = 0;

  ck_assert_str_eq(s21_memcpy(dest3, str2, len), memcpy(dest4, str2, len));

  char dest5[10] = "";
  char dest6[10] = "";
  char str3[10] = "\000";
  len = strlen(str3);

  ck_assert_str_eq(s21_memcpy(dest5, str3, len), memcpy(dest6, str3, len));

  char dest7[10] = "1232";
  char dest8[10] = "1232";
  char str4[10] = "wfe\0fw";
  len = 5;

  ck_assert_str_eq(s21_memcpy(dest7, str4, len), memcpy(dest8, str4, len));

  char dest9[10] = "qwer";
  char dest10[10] = "qwer";
  char str5[10] = "wfe\nfw";
  len = strlen(str3);

  ck_assert_str_eq(s21_memcpy(dest9, str5, len), memcpy(dest10, str5, len));
}
END_TEST

START_TEST(memmoveTest) {
  char dest1[10] = "qwerty";
  char dest2[10] = "qwerty";
  char src1[10] = "1234577";

  int len = strlen(src1);
  ck_assert_str_eq(s21_memmove(dest1, src1, 5), memmove(dest2, src1, 5));

  char dest3[10] = "";
  char dest4[10] = "";
  char str2[10] = "";
  len = 0;

  ck_assert_str_eq(s21_memmove(dest3, str2, len), memmove(dest4, str2, len));

  char dest5[10] = "";
  char dest6[10] = "";
  char str3[10] = "\000";

  ck_assert_str_eq(s21_memmove(dest5, str3, 1), memmove(dest6, str3, 1));

  char dest7[10] = "1232";
  char dest8[10] = "1232";
  char str4[10] = "wfe\0fw";
  len = 5;

  ck_assert_str_eq(s21_memmove(dest7, str4, 4), memmove(dest8, str4, 4));

  char dest9[10] = "qwer";
  char dest10[10] = "qwer";
  char str5[10] = "wfe\nfw";

  ck_assert_str_eq(s21_memmove(dest9, str5, 6), memmove(dest10, str5, 6));
}
END_TEST

START_TEST(memsetTest) {
  char dest1[10] = "12345";
  char dest2[10] = "12345";
  char src1 = 'z';

  int len = 5;
  ck_assert_str_eq(s21_memset(dest1, src1, len), memset(dest2, src1, len));

  char dest3[10] = "ytrewq";
  char dest4[10] = "ytrewq";
  char str2 = 'z';
  len = 3;

  ck_assert_str_eq(s21_memset(dest3, str2, len), memset(dest4, str2, len));

  char dest5[10] = "ytrewq";
  char dest6[10] = "ytrewq";
  char str3 = '\000';
  len = 3;

  ck_assert_str_eq(s21_memset(dest5, str3, len), memset(dest6, str3, len));

  char dest7[10] = "";
  char dest8[10] = "";
  char str4 = '\123';
  len = 5;

  ck_assert_str_eq(s21_memset(dest7, str4, len), memset(dest8, str4, len));
}
END_TEST

START_TEST(strcatTest) {
  char dest1[20] = "12345  ";
  char dest2[20] = "12345  ";
  char str1[] = "zzz  ";
  char strOut1[20] = "";
  snprintf(strOut1, strlen(dest2) + strlen(str1) + 1, "%s%s", dest2, str1) < 0
      ? abort()
      : s21_NULL;
  ck_assert_str_eq(s21_strcat(dest1, str1), strOut1);

  char dest3[20] = "qwertyq";
  char dest4[20] = "qwertyq";
  char str2[] = "zzz";
  char strOut2[20] = "";
  snprintf(strOut2, strlen(dest4) + strlen(str2) + 1, "%s%s", dest4, str2) < 0
      ? abort()
      : s21_NULL;
  ck_assert_str_eq(s21_strcat(dest3, str2), strOut2);

  char dest5[20] = "ytrewq";
  char dest6[20] = "ytrewq";
  char str3[] = "\000wgw";
  char strOut3[20] = "";
  snprintf(strOut3, strlen(dest6) + strlen(str3) + 1, "%s%s", dest6, str3) < 0
      ? abort()
      : s21_NULL;
  ck_assert_str_eq(s21_strcat(dest5, str3), strOut3);

  char dest7[20] = "ytr\0ewq123";
  char dest8[20] = "ytr\0ewq123";
  char str4[] = "zzz";
  char strOut4[20] = "";
  snprintf(strOut4, strlen(dest8) + strlen(str4) + 1, "%s%s", dest8, str4) < 0
      ? abort()
      : s21_NULL;
  ck_assert_str_eq(s21_strcat(dest7, str4), strOut4);

  char dest9[20] = "";
  char dest10[20] = "";
  char str5[] = "235";
  char strOut5[20] = "";
  snprintf(strOut5, strlen(dest10) + strlen(str5) + 1, "%s%s", dest10, str5) < 0
      ? abort()
      : s21_NULL;
  ck_assert_str_eq(s21_strcat(dest9, str5), strOut5);
}
END_TEST

START_TEST(strncatTest) {
  char str1[11] = "zzzzz";
  char str2[11] = "zzzzz";
  char str3[6] = "aaaaa";
  int len = 5;
  char strOut1[20] = "";
  snprintf(strOut1, strlen(str2) + 1 + len, "%s%s", str2, str3) < 0 ? abort()
                                                                    : s21_NULL;
  ck_assert_str_eq(s21_strncat(str1, str3, len), strOut1);

  char str4[11] = "zzzzz";
  char str5[11] = "zzzzz";
  char str6[6] = "aaaaa";
  len = 0;
  char strOut2[20] = "";
  snprintf(strOut2, strlen(str5) + 1 + len, "%s%s", str5, str6) < 0 ? abort()
                                                                    : s21_NULL;
  ck_assert_str_eq(s21_strncat(str4, str6, len), strOut2);

  char str7[11] = "zzzzz";
  char str8[11] = "zzzzz";
  char str9[6] = "aaaaa";
  len = 3;
  char strOut3[20] = "";
  snprintf(strOut3, strlen(str8) + 1 + len, "%s%s", str8, str9) < 0 ? abort()
                                                                    : s21_NULL;
  ck_assert_str_eq(s21_strncat(str7, str9, len), strOut3);

  char str10[11] = "zzzzz";
  char str11[11] = "zzzzz";
  char str12[11] = "aaaaa";
  len = 5;
  char strOut4[20] = "";
  snprintf(strOut4, strlen(str11) + 1 + len, "%s%s", str11, str12) < 0
      ? abort()
      : s21_NULL;
  ck_assert_str_eq(s21_strncat(str10, str12, len), strOut4);

  char str13[11] = "#\ntg";
  char str14[11] = "#\ntg";
  char str15[11] = "\?\0\?|>P}?";
  len = 4;
  char strOut5[20] = "";
  snprintf(strOut5, len + strlen(str14), "%s%s", str14, str15) < 0 ? abort()
                                                                   : s21_NULL;
  ck_assert_str_eq(s21_strncat(str13, str15, len), strOut5);

  char str16[11] = "";
  char str17[11] = "";
  char str18[11] = "3\t43";
  len = 5;
  char strOut6[20] = "";
  snprintf(strOut6, strlen(str17) + 1 + len, "%s%s", str17, str18) < 0
      ? abort()
      : s21_NULL;
  ck_assert_str_eq(s21_strncat(str16, str18, len), strOut6);
}
END_TEST

START_TEST(strchrTest) {
  char str1[11] = "0123456789";

  ck_assert_ptr_eq(s21_strchr(str1, '3'), strchr(str1, '3'));

  char str2[11] = "0123456789";
  str2[4] = '\0';

  ck_assert_ptr_eq(s21_strchr(str2, '\0'), strchr(str2, '\0'));

  char str3[11] = "qwerty";
  str3[4] = '\n';

  ck_assert_ptr_eq(s21_strchr(str3, '\n'), strchr(str3, '\n'));

  char str4[11] = "zweZrty";

  ck_assert_ptr_eq(s21_strchr(str4, '\132'), strchr(str4, '\132'));

  char str5[11] = "zwertz";

  ck_assert_ptr_eq(s21_strchr(str5, 'z'), strchr(str5, 'z'));

  char str6[11] = "zwertz";

  ck_assert_ptr_eq(s21_strchr(str6, '\000'), strchr(str6, '\000'));

  char str7[11] = "";

  ck_assert_ptr_eq(s21_strchr(str7, '@'), strchr(str7, '@'));
}
END_TEST

START_TEST(strcmpTest) {
  char str1[10] = "zzzz\0z";
  char str2[10] = "aaaa\0a";
  ck_assert_int_eq(signum(s21_strcmp(str1, str2)), signum(strcmp(str1, str2)));
  char str3[10] = "123";
  char str4[10] = "321";
  ck_assert_int_eq(signum(s21_strcmp(str3, str4)), signum(strcmp(str3, str4)));
  char str5[10] = "\0zzzzz";
  char str6[10] = "\0aaaaa";
  ck_assert_int_eq(signum(s21_strcmp(str5, str6)), signum(strcmp(str5, str6)));
  char str7[10] = "aa\naa!";
  char str8[10] = "aa\nzz!";
  ck_assert_int_eq(signum(s21_strcmp(str7, str8)), signum(strcmp(str7, str8)));
  char str9[10] = "";
  char str10[10] = "\0";
  ck_assert_int_eq(signum(s21_strcmp(str9, str10)), signum(strcmp(str9, str10)));
  char str11[10] = "\0zzzzz";
  char str12[10] = "aaaaa";
  ck_assert_int_eq(signum(s21_strcmp(str11, str12)), signum(strcmp(str11, str12)));
}
END_TEST

START_TEST(strncmpTest) {
  char str1[10] = "zzzz\0z";
  char str2[10] = "aaaa\0a";
  int len = strlen(str1);
  ck_assert_int_eq(signum(s21_strncmp(str1, str2, len)), signum(strncmp(str1, str2, len)));
  char str3[10] = "123";
  char str4[10] = "321";
  len = strlen(str3);
  ck_assert_int_eq(signum(s21_strncmp(str3, str4, len)), signum(strncmp(str3, str4, len)));
  char str5[10] = "\0zzzzz";
  char str6[10] = "\0aaaaa";
  len = strlen(str5);
  ck_assert_int_eq(signum(s21_strncmp(str5, str6, len)), signum(strncmp(str5, str6, len)));
  char str7[10] = "aa\naa!";
  char str8[10] = "aa\nzz!";
  len = strlen(str7);
  ck_assert_int_eq(signum(s21_strncmp(str7, str8, len)), signum(strncmp(str7, str8, len)));
  char str9[10] = "";
  char str10[10] = "\0";
  len = strlen(str10);
  ck_assert_int_eq(signum(s21_strncmp(str9, str10, len)), signum(strncmp(str9, str10, len)));
  char str11[10] = "aaaaa";
  char str12[10] = "\0zzzzz";
  len = strlen(str11);
  ck_assert_int_eq(signum(s21_strncmp(str11, str12, len)), signum(strncmp(str11, str12, len)));
  char str13[10] = "World\n";
  char str14[10] = "WoR";
  len = 4;
  ck_assert_int_eq(signum(s21_strncmp(str13, str14, len)), signum(strncmp(str13, str14, len)));
}
END_TEST

START_TEST(strcpyTest) {
  char src1[] = "\000Быть или не быть";
  char dest1[128] = "";

  char src2[] = "\000Быть или не быть";
  char dest2[128] = "";

  char strOut1[128] = "";
  snprintf(strOut1, sizeof(strOut1), "%.128s%.129s", src2, dest2) < 0
      ? abort()
      : s21_NULL;
  ck_assert_str_eq(s21_strcpy(dest1, src1), strOut1);

  char src3[] = "To be or \not to be";
  char dest3[128] = "";

  char src4[] = "To be or \not to be";
  char dest4[128] = "";
  char strOut2[128] = "";
  snprintf(strOut2, sizeof(strOut2), "%s%s", src4, dest4) < 0 ? abort()
                                                              : s21_NULL;
  ck_assert_str_eq(s21_strcpy(dest3, src3), strOut2);

  char src6[10] = "\0";
  char dest6[128] = "123";
  char strOut3[128] = "123";
  snprintf(strOut3, sizeof(src6), "%s", src6) < 0 ? abort() : s21_NULL;
  ck_assert_str_eq(s21_strcpy(dest6, src6), strOut3);

  char src7[] = "обра\0зец\nстроки";
  char dest7[128] = "";

  char src8[] = "обра\0зец\nстроки";
  char dest8[128] = "";
  char strOut4[128] = "";
  snprintf(strOut4, sizeof(strOut4), "%s%s", src8, dest8) < 0 ? abort()
                                                              : s21_NULL;
  ck_assert_str_eq(s21_strcpy(dest7, src7), strOut4);
}
END_TEST

START_TEST(strncpyTest) {
  char src1[] = "Быть или не быть";
  char dest1[10] = "";

  char src2[] = "Быть или не быть";
  char dest2[10] = "";
  int len = 8;

  ck_assert_str_eq(s21_strncpy(dest1, src1, len), strncpy(dest2, src2, len));

  char src3[] = "To be or not to be";
  char dest3[10] = "";

  char src4[] = "To be or not to be";
  char dest4[10] = "";
  len = 5;

  ck_assert_str_eq(s21_strncpy(dest3, src3, len), strncpy(dest4, src4, len));

  char src5[] = "";
  char dest5[128] = "образец строки";

  char src6[] = "";
  char dest6[128] = "образец строки";
  len = sizeof(dest4) - 1;

  ck_assert_str_eq(s21_strncpy(dest5, src5, len), strncpy(dest6, src6, len));

  char src7[] = "обра\0зец\nстроки";
  char dest7[10] = "";

  char src8[] = "обра\0зец\nстроки";
  char dest8[10] = "";
  len = sizeof(dest7) - 1;

  ck_assert_str_eq(s21_strncpy(dest7, src7, len), strncpy(dest8, src8, len));
}
END_TEST

START_TEST(strcspnTest) {
  char str1[] = "LOST: 4-8-15-16-23-42";
  char str2[] = "1234567890";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  char str3[10] = "1234";
  char str4[10] = "567";
  ck_assert_int_eq(s21_strcspn(str3, str4), strcspn(str3, str4));
  char str5[] = "\0findofyoucan";
  char str6[10] = "\0can";
  ck_assert_int_eq(s21_strcspn(str5, str6), strcspn(str5, str6));
  char str7[] = "01234567\n89";
  char str8[10] = "9876";
  ck_assert_int_eq(s21_strcspn(str7, str8), strcspn(str7, str8));
  char str9[10] = "0123456789";
  char str10[10] = "\0";
  ck_assert_int_eq(s21_strcspn(str9, str10), strcspn(str9, str10));
  char str11[10] = "\0";
  char str12[10] = "";
  ck_assert_int_eq(s21_strcspn(str11, str12), strcspn(str11, str12));
}
END_TEST

START_TEST(strerrorTest) {
  for (int i = -1; i <= 10000; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  ck_assert_str_eq(s21_strerror(1), strerror(1));
}
END_TEST

START_TEST(strlenTest) {
  char str1[10] = "zzzzz";
  ck_assert_uint_eq(s21_strlen(str1), strlen(str1));
  char str2[10] = "a";
  ck_assert_uint_eq(s21_strlen(str2), strlen(str2));
  char str3[10] = "";
  ck_assert_uint_eq(s21_strlen(str3), strlen(str3));
  char str4[10] = "zzz\0zz";
  ck_assert_uint_eq(s21_strlen(str4), strlen(str4));
  char str5[10] = "\0asdsd";
  ck_assert_uint_eq(s21_strlen(str5), strlen(str5));
  char str6[10] = "\0\0\0";
  ck_assert_uint_eq(s21_strlen(str6), strlen(str6));
}
END_TEST

START_TEST(strpbrkTest) {
  char str1[] = "LOST: 4-8-15-16-23-42";
  char str2[] = "1234567890";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  char str3[10] = "0123456789";
  char str4[10] = "369";
  ck_assert_ptr_eq(s21_strpbrk(str3, str4), strpbrk(str3, str4));
  char str5[] = "findofyouca\n";
  char str6[10] = "can";
  ck_assert_ptr_eq(s21_strpbrk(str5, str6), strpbrk(str5, str6));
  char str7[] = "verter sila!";
  char str8[10] = "!";
  ck_assert_ptr_eq(s21_strpbrk(str7, str8), strpbrk(str7, str8));
  char str9[10] = "0123456789";
  char str10[10] = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str9, str10), strpbrk(str9, str10));
  char str11[10] = "\0";
  char str12[10] = "";
  ck_assert_ptr_eq(s21_strpbrk(str11, str12), strpbrk(str11, str12));
}
END_TEST

START_TEST(strrchrTest) {
  char str1[11] = "0123456789";

  ck_assert_ptr_eq(s21_strrchr(str1, '3'), strrchr(str1, '3'));

  char str2[11] = "0123456789";
  str2[4] = '\0';

  ck_assert_ptr_eq(s21_strrchr(str2, '\0'), strrchr(str2, '\0'));

  char str3[11] = "qwerty";
  str3[4] = '\n';

  ck_assert_ptr_eq(s21_strrchr(str3, '\n'), strrchr(str3, '\n'));

  char str4[11] = "zweZrty";

  ck_assert_ptr_eq(s21_strrchr(str4, '\132'), strrchr(str4, '\132'));

  char str5[11] = "zwertz";

  ck_assert_ptr_eq(s21_strrchr(str5, 'z'), strrchr(str5, 'z'));

  char str6[11] = "zwertz";

  ck_assert_ptr_eq(s21_strrchr(str6, '\000'), strrchr(str6, '\000'));

  char str7[11] = "";

  ck_assert_ptr_eq(s21_strrchr(str7, '@'), strrchr(str7, '@'));
}
END_TEST

START_TEST(strspnTest) {
  char str1[11] = "0123456789";

  ck_assert_int_eq(s21_strspn(str1, "210"), strspn(str1, "210"));

  char str2[11] = "0123456789";
  str2[0] = '\0';

  ck_assert_int_eq(s21_strspn(str2, "\0"), strspn(str2, "\0"));

  char str3[11] = "qwerty";
  str3[4] = '\0';

  ck_assert_int_eq(s21_strspn(str3, "rty"), strspn(str3, "rty"));

  char str4[11] = "zweZrty";

  ck_assert_int_eq(s21_strspn(str4, "ty\0"), strspn(str4, "ty\0"));

  char str5[11] = "zwertz";

  ck_assert_int_eq(s21_strspn(str5, "zerg"), strspn(str5, "zerg"));

  char str6[11] = "!zwert!z";

  ck_assert_int_eq(s21_strspn(str6, "!z"), strspn(str6, "!z"));

  char str7[11] = "@";

  ck_assert_int_eq(s21_strspn(str7, "\0@"), strspn(str7, "\0@"));
}
END_TEST

START_TEST(strstrTest) {
  char str1[11] = "0123456789";

  ck_assert_ptr_eq(s21_strstr(str1, "210"), strstr(str1, "210"));

  char str2[11] = "0123456789";

  ck_assert_ptr_eq(s21_strstr(str2, ""), strstr(str2, ""));

  char str3[11] = "qwerty";
  str3[4] = '\0';

  ck_assert_ptr_eq(s21_strstr(str3, "rty"), strstr(str3, "rty"));

  char str4[11] = "zweZrty";

  ck_assert_ptr_eq(s21_strstr(str4, "ty\0"), strstr(str4, "ty\0"));

  char str5[11] = "zwertz";

  ck_assert_ptr_eq(s21_strstr(str5, "\0"), strstr(str5, "\0"));

  char str6[11] = "!zwert!z";

  ck_assert_ptr_eq(s21_strstr(str6, "!z"), strstr(str6, "!z"));

  char str7[11] = "@";

  ck_assert_ptr_eq(s21_strstr(str7, "\0@"), strstr(str7, "\0@"));
}
END_TEST

START_TEST(strtokTest) {
  char str1[111] = "test1/test2/test3/test4";

  ck_assert_ptr_eq(s21_strtok(str1, "/"), strtok(str1, "/"));

  char str2[111] = "test1/test2/test3/test4";

  ck_assert_ptr_eq(s21_strtok(str2, "1234"), strtok(str2, "1234"));

  char str3[111] = "test1/test2/test3/test4";

  ck_assert_ptr_eq(s21_strtok(str3, " "), strtok(str3, " "));

  char str4[111] = "test1\0test2\0test3\0test4";

  ck_assert_ptr_eq(s21_strtok(str4, "\0"), strtok(str4, "\0"));

  char str5[111] = "test1/test2/test3/test4";

  ck_assert_ptr_eq(s21_strtok(str5, " "), strtok(str5, " "));

  char str6[111] = "test1/test2/test3/test4";

  ck_assert_ptr_eq(s21_strtok(str6, ""), strtok(str6, ""));

  char str7[111] = "/";

  ck_assert_ptr_eq(s21_strtok(str7, "/"), strtok(str7, "/"));
}
END_TEST

START_TEST(to_upperTest) {
  char str1[111] = "zag-zag!";
  char *dest1 = s21_to_upper(str1);
  ck_assert_str_eq(dest1, "ZAG-ZAG!");
  free(dest1);
  char str2[111] = "ZAG-ZAG";
  char *dest2 = s21_to_upper(str2);
  ck_assert_str_eq(dest2, "ZAG-ZAG");
  free(dest2);
  char str3[111] = "{_cAzInO_";
  char *dest3 = s21_to_upper(str3);
  ck_assert_str_eq(dest3, "{_CAZINO_");
  free(dest3);
  char str4[111] = "ProverkA";
  char *dest4 = s21_to_upper(str4);
  ck_assert_str_eq(dest4, "PROVERKA");
  free(dest4);
  char str5[111] = "Prove\nr04kA";
  char *dest5 = s21_to_upper(str5);
  ck_assert_str_eq(dest5, "PROVE\nR04KA");
  free(dest5);
  char str6[111] = "Prover04kA";
  char *dest6 = s21_to_upper(str6);
  ck_assert_str_eq(dest6, "PROVER04KA");
  free(dest6);
}
END_TEST

START_TEST(to_lowerTest) {
  char str1[111] = "ZAG-ZAG";
  char *dest1 = s21_to_lower(str1);
  ck_assert_str_eq(dest1, "zag-zag");
  free(dest1);
  char str2[111] = "PRIVET KRASAF4EG!";
  char *dest2 = s21_to_lower(str2);
  ck_assert_str_eq(dest2, "privet krasaf4eg!");
  free(dest2);
  char str3[111] = " \n \0";
  char *dest3 = s21_to_lower(str3);
  ck_assert_str_eq(dest3, " \n ");
  free(dest3);
  char str4[111] = "123";
  char *dest4 = s21_to_lower(str4);
  ck_assert_str_eq(dest4, "123");
  free(dest4);
  char str5[111] = "$^//&^*&(*PO";
  char *dest5 = s21_to_lower(str5);
  ck_assert_str_eq(dest5, "$^//&^*&(*po");
  free(dest5);
  char str6[111] = "Prover04kA";
  char *dest6 = s21_to_lower(str6);
  ck_assert_str_eq(dest6, "prover04ka");
  free(dest6);
  char str7[111] = "";
  char *dest7 = s21_to_lower(str7);
  ck_assert_str_eq(dest7, "");
  free(dest7);
}
END_TEST

START_TEST(insertTest) {
  char src1[11] = "qwerty";
  char str1[6] = "12345";
  char *dest1 = s21_insert(src1, str1, 2);
  ck_assert_str_eq(dest1, "qw12345erty");
  free(dest1);
  char src2[11] = "qwerty";
  char str2[6] = "12345";
  char *dest2 = s21_insert(src2, str2, 6);
  ck_assert_str_eq(dest2, "qwerty12345");
  free(dest2);
  char src3[11] = "zzzzz";
  char str3[6] = "aaaaa";
  char *dest3 = s21_insert(src3, str3, 6);
  ck_assert_ptr_eq(dest3, s21_NULL);
  char src4[11] = "qwerty";
  char str4[6] = "12345";
  char *dest4 = s21_insert(src4, str4, 0);
  ck_assert_str_eq(dest4, "12345qwerty");
  free(dest4);
  char src5[11] = "";
  char str5[6] = "aaaaa";
  char *dest5 = s21_insert(src5, str5, 0);
  ck_assert_str_eq(dest5, "aaaaa");
  free(dest5);
  char src6[11] = "";
  char str6[6] = "";
  char *dest6 = s21_insert(src6, str6, 0);
  ck_assert_str_eq(dest6, "");
  free(dest6);
}
END_TEST

START_TEST(trimTest) {
  char src1[128] = "*** Much Ado About Nothing ***";
  char str1[32] = {'*', ' '};
  char *tempPointer = s21_trim(src1, str1);
  ck_assert_str_eq(tempPointer, "Much Ado About Nothing");
  free(tempPointer);

  char src2[128] = "*** Much Ado About Nothing ***";
  char str2[32] = "+";
  tempPointer = s21_trim(src2, str2);
  ck_assert_str_eq(tempPointer, "*** Much Ado About Nothing ***");
  free(tempPointer);

  char src3[128] = "*** Much Ado About Nothing ***";
  char str3[32] = "";
  tempPointer = s21_trim(src3, str3);
  ck_assert_str_eq(tempPointer, "*** Much Ado About Nothing ***");
  free(tempPointer);

  char src4[128] = "*** Much Ado About Nothing ***";
  char str4[32] = "";
  tempPointer = s21_trim(src4, str4);
  ck_assert_str_eq(tempPointer, "*** Much Ado About Nothing ***");
  free(tempPointer);

  char src5[128] = "1";
  char str5[32] = "1";
  tempPointer = s21_trim(src5, str5);
  ck_assert_str_eq(tempPointer, "");
  free(tempPointer);

  char src6[128] = "\n   /fi ehf ieh/  \t";
  tempPointer = s21_trim(src6, s21_NULL);
  ck_assert_str_eq(tempPointer, "/fi ehf ieh/");
  free(tempPointer);

  char src7[128] = "/*+";
  tempPointer = s21_trim(s21_NULL, src7);
  ck_assert_ptr_eq(tempPointer, s21_NULL);
  free(tempPointer);
}
END_TEST

START_TEST(sprintfTest) {
  char str1[512] = "";
  char str2[512] = "";
  int len1 = s21_sprintf(str1, "%s", "Hello");
  int len2 = snprintf(str2, sizeof(str1), "%s", "Hello");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(len1, len2);

  char str17[512] = "";
  char str18[512] = "";
  int len17 = s21_sprintf(str17, "%s", "");
  int len18 = snprintf(str18, sizeof(str1), "%s", "");
  ck_assert_str_eq(str17, str18);
  ck_assert_int_eq(len18, len17);

  //     //  %c
  char str3[512] = "";
  char str4[512] = "";
  int len3 = s21_sprintf(str3, "%c", '?');
  int len4 = snprintf(str4, sizeof(str1), "%c", '?');
  ck_assert_str_eq(str3, str4);
  ck_assert_int_eq(len3, len4);

  char str5[512] = "";
  char str6[512] = "";
  int len5 = s21_sprintf(str5, "%-c", '?');
  int len6 = snprintf(str6, sizeof(str1), "%-c", '?');
  ck_assert_str_eq(str5, str6);
  ck_assert_int_eq(len5, len6);

  char str7[512] = "";
  char str8[512] = "";
  int len7 = s21_sprintf(str7, "%3c", '?');
  int len8 = snprintf(str8, sizeof(str1), "%3c", '?');
  ck_assert_str_eq(str7, str8);
  ck_assert_int_eq(len7, len8);

  char str9[512]="";
  char str10[512]="";
  int len9 = s21_sprintf(str9, "%-3c", '?');
  int len10 = snprintf(str10, sizeof(str1), "%-3c", '?');
  ck_assert_str_eq(str9, str10);
  ck_assert_int_eq(len9, len10);

  char str11[512] = "";
  char str12[512] = "";
  int len11 = s21_sprintf(str11, "%lc", '?');
  int len12 = snprintf(str12, sizeof(str1), "%lc", '?');
  ck_assert_str_eq(str11, str12);
  ck_assert_int_eq(len11, len12);

  char str13[512] = "";
  char str14[512] = "";
  int len13 = s21_sprintf(str13, "%-lc", '?');
  int len14 = snprintf(str14, sizeof(str1), "%-lc", '?');
  ck_assert_str_eq(str13, str14);
  ck_assert_int_eq(len13, len14);

  char str15[512]="";
  char str16[512]="";
  int len16 = s21_sprintf(str15, "%-3lc", '?');
  int len15 = snprintf(str16, sizeof(str1), "%-3lc", '?');
  ck_assert_str_eq(str15, str16);
  ck_assert_int_eq(len15, len16);

  //     // %d
  char str19[512] = "";
  char str20[512] = "";
  int len19 = s21_sprintf(str19, "%d", -10);
  int len20 = snprintf(str20, sizeof(str1), "%d", -10);
  ck_assert_str_eq(str19, str20);
  ck_assert_int_eq(len19, len20);

  char str21[512] = "";
  char str22[512] = "";
  int len21 = s21_sprintf(str21, "%-d", -10);
  int len22 = snprintf(str22, sizeof(str1), "%-d", -10);
  ck_assert_str_eq(str21, str22);
  ck_assert_int_eq(len21, len22);

  char str23[512] = "";
  char str24[512] = "";
  int len23 = s21_sprintf(str23, "% d", -10);
  int len24 = snprintf(str24, sizeof(str1), "% d", -10);
  ck_assert_str_eq(str23, str24);
  ck_assert_int_eq(len23, len24);

  char str25[512] = "";
  char str26[512] = "";
  int len25 = s21_sprintf(str25, "%+d", -10);
  int len26 = snprintf(str26, sizeof(str1), "%+d", -10);
  ck_assert_str_eq(str25, str26);
  ck_assert_int_eq(len25, len26);

  char str27[512] = "";
  char str28[512] = "";
  int len27 = s21_sprintf(str27, "%5d", -10);
  int len28 = snprintf(str28, sizeof(str1), "%5d", -10);
  ck_assert_str_eq(str27, str28);
  ck_assert_int_eq(len27, len28);

  char str29[512] = "";
  char str30[512] = "";
  int len29 = s21_sprintf(str29, "%.d", -10);
  int len30 = snprintf(str30, sizeof(str1), "%.d", -10);
  ck_assert_str_eq(str29, str30);
  ck_assert_int_eq(len29, len30);

  char str31[512] = "";
  char str32[512] = "";
  int len31 = s21_sprintf(str31, "%-+d", -10);
  int len32 = snprintf(str32, sizeof(str1), "%-+d", -10);
  ck_assert_str_eq(str31, str32);
  ck_assert_int_eq(len31, len32);

  char str33[512] = "";
  char str34[512] = "";
  int len33 = s21_sprintf(str33, "%- d", -10);
  int len34 = snprintf(str34, sizeof(str1), "%- d", -10);
  ck_assert_str_eq(str33, str34);
  ck_assert_int_eq(len33, len34);

  char str35[512]="";
  char str36[512]="";
  int len35 = s21_sprintf(str35, "%-5d", -10);
  int len36 = snprintf(str36, sizeof(str1), "%-5d", -10);
  ck_assert_str_eq(str35, str36);
  ck_assert_int_eq(len35, len36);

  char str37[512]="";
  char str38[512]="";
  int len37 = s21_sprintf(str37, "%-5.d", -10);
  int len38 = snprintf(str38, sizeof(str1), "%-5.d", -10);
  ck_assert_str_eq(str37, str38);
  ck_assert_int_eq(len37, len38);

  //     // %i
  char str39[512] = "";
  char str40[512] = "";
  int len39 = s21_sprintf(str39, "%i", -10);
  int len40 = snprintf(str40, sizeof(str1), "%i", -10);
  ck_assert_str_eq(str39, str40);
  ck_assert_int_eq(len39, len40);

  char str41[512] = "";
  char str42[512] = "";
  int len41 = s21_sprintf(str41, "%-i", -10);
  int len42 = snprintf(str42, sizeof(str1), "%-i", -10);
  ck_assert_str_eq(str41, str42);
  ck_assert_int_eq(len41, len42);

  char str43[512] = "";
  char str44[512] = "";
  int len43 = s21_sprintf(str43, "%+i", -10);
  int len44 = snprintf(str44, sizeof(str1), "%+i", -10);
  ck_assert_str_eq(str43, str44);
  ck_assert_int_eq(len43, len44);

  char str45[512] = "";
  char str46[512] = "";
  int len45 = s21_sprintf(str45, "% i", -10);
  int len46 = snprintf(str46, sizeof(str1), "% i", -10);
  ck_assert_str_eq(str45, str46);
  ck_assert_int_eq(len45, len46);

  char str47[512] = "";
  char str48[512] = "";
  int len47 = s21_sprintf(str47, "%5i", -10);
  int len48 = snprintf(str48, sizeof(str1), "%5i", -10);
  ck_assert_str_eq(str47, str48);
  ck_assert_int_eq(len47, len48);

  char str49[512] = "";
  char str50[512] = "";
  int len49 = s21_sprintf(str49, "%.i", -10);
  int len50 = snprintf(str50, sizeof(str1), "%.i", -10);
  ck_assert_str_eq(str49, str50);
  ck_assert_int_eq(len49, len50);

  char str51[512] = "";
  char str52[512] = "";
  int len51 = s21_sprintf(str51, "%-+i", -10);
  int len52 = snprintf(str52, sizeof(str1), "%-+i", -10);
  ck_assert_str_eq(str51, str52);
  ck_assert_int_eq(len51, len52);

  char str53[512] = "";
  char str54[512] = "";
  int len53 = s21_sprintf(str53, "%- i", -10);
  int len54 = snprintf(str54, sizeof(str1), "%- i", -10);
  ck_assert_str_eq(str53, str54);
  ck_assert_int_eq(len53, len54);

  char str55[512] = "";
  char str56[512] = "";
  int len55 = s21_sprintf(str55, "%-5i", -10);
  int len56 = snprintf(str56, sizeof(str1), "%-5i", -10);
  ck_assert_str_eq(str55, str56);
  ck_assert_int_eq(len55, len56);

  char str57[512] = "";
  char str58[512] = "";
  int len57 = s21_sprintf(str57, "%-5.i", -10);
  int len58 = snprintf(str58, sizeof(str1), "%-5.i", -10);
  ck_assert_str_eq(str57, str58);
  ck_assert_int_eq(len57, len58);

  //     // %f

  char str59[512] = "";
  char str60[512] = "";
  int len59 = s21_sprintf(str59, "%f", 0.0);
  int len60 = snprintf(str60, sizeof(str1), "%f", 0.0);
  ck_assert_str_eq(str59, str60);
  ck_assert_int_eq(len59, len60);

  char str61[512] = "";
  char str62[512] = "";
  int len61 = s21_sprintf(str61, "%-f", -0.00000);
  int len62 = snprintf(str62, sizeof(str1), "%-f", -0.00000);
  ck_assert_str_eq(str61, str62);
  ck_assert_int_eq(len61, len62);

  char str63[512] = "";
  char str64[512] = "";
  int len63 = s21_sprintf(str63, "%+f", -0.00000);
  int len64 = snprintf(str64, sizeof(str1), "%+f", -0.00000);
  ck_assert_str_eq(str63, str64);
  ck_assert_int_eq(len63, len64);

  char str65[512] = "";
  char str66[512] = "";
  int len65 = s21_sprintf(str65, "% f", 3.14159);
  int len66 = snprintf(str66, sizeof(str1), "% f", 3.14159);
  ck_assert_str_eq(str65, str66);
  ck_assert_int_eq(len65, len66);

  char str67[512] = "";
  char str68[512] = "";
  int len67 = s21_sprintf(str67, "%5f", 3.14159);
  int len68 = snprintf(str68, sizeof(str1), "%5f", 3.14159);
  ck_assert_str_eq(str67, str68);
  ck_assert_int_eq(len67, len68);

  char str69[512] = "";
  char str70[512] = "";
  int len69 = s21_sprintf(str69, "%.f", 3.14159);
  int len70 = snprintf(str70, sizeof(str1), "%.f", 3.14159);
  ck_assert_str_eq(str69, str70);
  ck_assert_int_eq(len69, len70);

  char str71[512] = "";
  char str72[512] = "";
  int len71 = s21_sprintf(str71, "%-+f", 3.14159);
  int len72 = snprintf(str72, sizeof(str1), "%-+f", 3.14159);
  ck_assert_str_eq(str71, str72);
  ck_assert_int_eq(len71, len72);

  char str73[512] = "";
  char str74[512] = "";
  int len73 = s21_sprintf(str73, "%- f", 3.14159);
  int len74 = snprintf(str74, sizeof(str1), "%- f", 3.14159);
  ck_assert_str_eq(str73, str74);
  ck_assert_int_eq(len73, len74);

  char str75[512] = "";
  char str76[512] = "";
  int len75 = s21_sprintf(str75, "%-5f", 3.14159);
  int len76 = snprintf(str76, sizeof(str1), "%-5f", 3.14159);
  ck_assert_str_eq(str75, str76);
  ck_assert_int_eq(len75, len76);

  char str77[512] = "";
  char str78[512] = "";
  int len77 = s21_sprintf(str77, "%-5.f", 3.14159);
  int len78 = snprintf(str78, sizeof(str1), "%-5.f", 3.14159);
  ck_assert_str_eq(str77, str78);
  ck_assert_int_eq(len77, len78);

  char str79[512] = "";
  char str80[512] = "";
  int len79 = s21_sprintf(str79, "%20.20lf", 3.000);
  int len80 = snprintf(str80, sizeof(str1), "%20.20lf", 3.000);
  ck_assert_str_eq(str79, str80);
  ck_assert_int_eq(len79, len80);

  char str81[512] = "";
  char str82[512] = "";
  int len81 = s21_sprintf(str81, "%-5.lf", 3.14159);
  int len82 = snprintf(str82, sizeof(str1), "%-5.lf", 3.14159);
  ck_assert_str_eq(str81, str82);
  ck_assert_int_eq(len81, len82);

  //     // %s

  char str83[512] = "";
  char str84[512] = "";
  int len83 = s21_sprintf(str83, "%s", "don't hurt me");
  int len84 = snprintf(str84, sizeof(str1), "%s", "don't hurt me");
  ck_assert_str_eq(str83, str84);
  ck_assert_int_eq(len83, len84);

  char str85[512] = "";
  char str86[512] = "";
  int len85 = s21_sprintf(str85, "%-s", "don't hurt me");
  int len86 = snprintf(str86, sizeof(str1), "%-s", "don't hurt me");
  ck_assert_str_eq(str85, str86);
  ck_assert_int_eq(len85, len86);

  char str87[512] = "";
  char str88[512] = "";
  int len87 = s21_sprintf(str87, "%6s", "don't hurt me");
  int len88 = snprintf(str88, sizeof(str1), "%6s", "don't hurt me");
  ck_assert_str_eq(str87, str88);
  ck_assert_int_eq(len87, len88);

  char str89[512] = "";
  char str90[512] = "";
  int len89 = s21_sprintf(str89, "%.6s", "don't hurt me");
  int len90 = snprintf(str90, sizeof(str1), "%.6s", "don't hurt me");
  ck_assert_str_eq(str89, str90);
  ck_assert_int_eq(len89, len90);

  char str91[512] = "";
  char str92[512] = "";
  int len91 = s21_sprintf(str91, "%-6s", "don't hurt me");
  int len92 = snprintf(str92, sizeof(str1), "%-6s", "don't hurt me");
  ck_assert_str_eq(str91, str92);
  ck_assert_int_eq(len91, len92);

  char str93[512] = "";
  char str94[512] = "";
  int len93 = s21_sprintf(str93, "%-.6s", "don't hurt me");
  int len94 = snprintf(str94, sizeof(str1), "%-.6s", "don't hurt me");
  ck_assert_str_eq(str93, str94);
  ck_assert_int_eq(len93, len94);

  char str95[512] = "";
  char str96[512] = "";
  int len95 = s21_sprintf(str95, "%-6.6s", "don't hurt me");
  int len96 = snprintf(str96, sizeof(str1), "%-6.6s", "don't hurt me");
  ck_assert_str_eq(str95, str96);
  ck_assert_int_eq(len95, len96);

  //     // %u

  char str97[512] = "";
  char str98[512] = "";
  int len97 = s21_sprintf(str97, "%.3u", 42);
  int len98 = snprintf(str98, sizeof(str1), "%.3u", 42);
  ck_assert_str_eq(str97, str98);
  ck_assert_int_eq(len97, len98);

  char str99[512] = "";
  char str100[512] = "";
  int len99 = s21_sprintf(str99, "%-u", 42);
  int len100 = snprintf(str100, sizeof(str1), "%-u", 42);
  ck_assert_str_eq(str99, str100);
  ck_assert_int_eq(len99, len100);

  char str101[512] = "";
  char str102[512] = "";
  int len101 = s21_sprintf(str101, "%5u", 42);
  int len102 = snprintf(str102, sizeof(str1), "%5u", 42);
  ck_assert_str_eq(str101, str102);
  ck_assert_int_eq(len101, len102);

  char str103[512] = "";
  char str104[512] = "";
  int len103 = s21_sprintf(str103, "%.u", 42);
  int len104 = snprintf(str104, sizeof(str1), "%.u", 42);
  ck_assert_str_eq(str103, str104);
  ck_assert_int_eq(len103, len104);

  char str105[512] = "";
  char str106[512] = "";
  int len105 = s21_sprintf(str105, "%-5u", 42);
  int len106 = snprintf(str106, sizeof(str1), "%-5u", 42);
  ck_assert_str_eq(str105, str106);
  ck_assert_int_eq(len105, len106);

  char str107[512] = "";
  char str108[512] = "";
  int len107 = s21_sprintf(str107, "%-5.u", 42);
  int len108 = snprintf(str108, sizeof(str1), "%-5.u", 42);
  ck_assert_str_eq(str107, str108);
  ck_assert_int_eq(len107, len108);

  char str109[512] = "";
  char str110[512] = "";
  int len109 = s21_sprintf(str109, "%c%c", '?', '!');
  int len110 = snprintf(str110, sizeof(str1), "%c%c", '?', '!');
  ck_assert_str_eq(str109, str110);
  ck_assert_int_eq(len109, len110);

  char str111[512] = "";
  char str112[512] = "";
  int len111 = s21_sprintf(str111, "%d%c", 42, '?');
  int len112 = snprintf(str112, sizeof(str1), "%d%c", 42, '?');
  ck_assert_str_eq(str111, str112);
  ck_assert_int_eq(len111, len112);

  char str113[512] = "";
  char str114[512] = "";
  int len113 = s21_sprintf(str113, "%i%c", 42, '?');
  int len114 = snprintf(str114, sizeof(str1),  "%i%c", 42, '?');
  ck_assert_str_eq(str113, str114);
  ck_assert_int_eq(len113, len114);

  char str115[512] = "";
  char str116[512] = "";
  int len115 = s21_sprintf(str115, "%f%c", 3.1415926535897932, '?');
  int len116 = snprintf(str116, sizeof(str1), "%f%c", 3.1415926535897932, '?');
  ck_assert_str_eq(str115, str116);
  ck_assert_int_eq(len115, len116);

  char str117[512] = "";
  char str118[512] = "";
  int len117 = s21_sprintf(str117, "%s%c", "No more", '?');
  int len118 = snprintf(str118, sizeof(str1), "%s%c", "No more", '?');
  ck_assert_str_eq(str117, str118);
  ck_assert_int_eq(len117, len118);

  char str119[512] = "";
  char str120[512] = "";
  int len119 = s21_sprintf(str119, "%d %d", 42, 10);
  int len120 = snprintf(str120, sizeof(str1), "%d %d", 42, 10);
  ck_assert_str_eq(str119, str120);
  ck_assert_int_eq(len119, len120);

  char str121[512] = "";
  char str122[512] = "";
  int len121 = s21_sprintf(str121, "%d %i", 42, 10);
  int len122 = snprintf(str122, sizeof(str1), "%d %i", 42, 10);
  ck_assert_str_eq(str121, str122);
  ck_assert_int_eq(len121, len122);

  char str123[512] = "";
  char str124[512] = "";
  int len123 = s21_sprintf(str123, "%d %f", 42, 3.1415926535897932);
  int len124 = snprintf(str124, sizeof(str1), "%d %f", 42, 3.1415926535897932);
  ck_assert_str_eq(str123, str124);
  ck_assert_int_eq(len123, len124);

  char str125[512] = "";
  char str126[512] = "";
  int len125 = s21_sprintf(str125, "%d %s", 42, "is the answer");
  int len126 = snprintf(str126, sizeof(str1), "%d %s", 42, "is the answer");
  ck_assert_str_eq(str125, str126);
  ck_assert_int_eq(len125, len126);

  char str127[512] = "";
  char str128[512] = "";
  int len127 = s21_sprintf(str127, "%-5.u", 42);
  int len128 = snprintf(str128, sizeof(str1), "%-5.u", 42);
  ck_assert_str_eq(str127, str128);
  ck_assert_int_eq(len127, len128);

  char str129[512] = "";
  char str130[512] = "";
  int len129 = s21_sprintf(str129, "%d%%", 42);
  int len130 = snprintf(str130, sizeof(str1), "%d%%", 42);
  ck_assert_str_eq(str129, str130);
  ck_assert_int_eq(len129, len130);

  char str131[512] = "";
  char str132[512] = "";
  int len131 = s21_sprintf(str131, "%i %i", 42, 10);
  int len132 = snprintf(str132, sizeof(str1), "%i %i", 42, 10);
  ck_assert_str_eq(str131, str132);
  ck_assert_int_eq(len131, len132);

  char str133[512] = "";
  char str134[512] = "";
  int len133 = s21_sprintf(str133, "%i %f", 42, 3.1415926535897932);
  int len134 = snprintf(str134, sizeof(str1), "%i %f", 42, 3.1415926535897932);
  ck_assert_str_eq(str133, str134);
  ck_assert_int_eq(len133, len134);

  char str135[512] = "";
  char str136[512] = "";
  int len135 = s21_sprintf(str135, "%i %s", 42, "is the answer");
  int len136 = snprintf(str136, sizeof(str1), "%i %s", 42, "is the answer");
  ck_assert_str_eq(str135, str136);
  ck_assert_int_eq(len135, len136);

  char str137[512] = "";
  char str138[512] = "";
  int len137 = s21_sprintf(str137, "%i %u", 42, 10);
  int len138 = snprintf(str138, sizeof(str1), "%i %u", 42, 10);
  ck_assert_str_eq(str137, str138);
  ck_assert_int_eq(len137, len138);

  char str139[512] = "";
  char str140[512] = "";
  int len139 = s21_sprintf(str139, "%i%%", 42);
  int len140 = snprintf(str140, sizeof(str1), "%i%%", 42);
  ck_assert_str_eq(str139, str140);
  ck_assert_int_eq(len139, len140);

  char str141[512] = "";
  char str142[512] = "";
  int len141 =
      s21_sprintf(str141, "%f%f", 3.1415926535897932, 3.1415926535897932);
  int len142 = snprintf(str142, sizeof(str1), "%f%f", 3.1415926535897932, 3.1415926535897932);
  ck_assert_str_eq(str141, str142);
  ck_assert_int_eq(len141, len142);

  char str143[512] = "";
  char str144[512] = "";
  int len143 = s21_sprintf(str143, "%f%s", 3.1415926535897932, "is not a limit");
  int len144 = snprintf(str144, sizeof(str1), "%f%s", 3.1415926535897932, "is not a limit");
  ck_assert_str_eq(str143, str144);
  ck_assert_int_eq(len143, len144);

  char str145[512] = "";
  char str146[512] = "";
  int len145 = s21_sprintf(str145, "%f%u", 3.1415926535897932, 3);
  int len146 = snprintf(str146, sizeof(str1), "%f%u", 3.1415926535897932, 3);
  ck_assert_str_eq(str145, str146);
  ck_assert_int_eq(len145, len146);

  char str147[512] = "";
  char str148[512] = "";
  int len147 = s21_sprintf(str147, "%i%%", 42);
  int len148 = snprintf(str148, sizeof(str1), "%i%%", 42);
  ck_assert_str_eq(str147, str148);
  ck_assert_int_eq(len147, len148);

  char str149[512] = "";
  char str150[512] = "";
  int len149 = s21_sprintf(str149, "%s%u", "The answer is", 42);
  int len150 = snprintf(str150, sizeof(str1), "%s%u", "The answer is", 42);
  ck_assert_str_eq(str149, str150);
  ck_assert_int_eq(len149, len150);

  char str151[512] = "";
  char str152[512] = "";
  int len151 = s21_sprintf(str151, "%s%%", "Infa 100");
  int len152 = snprintf(str152, sizeof(str1), "%s%%", "Infa 100");
  ck_assert_str_eq(str151, str152);
  ck_assert_int_eq(len151, len152);

  char str153[512] = "";
  char str154[512] = "";
  int len153 = s21_sprintf(str153,
  "%-3lc%+-5.5d%+-5.5i%-5.5lf%-6.6s%-5.u%%", '?', 42, 24, 3.1415926535897932, "WTF", 28);
  int len154 = snprintf(str154, sizeof(str1),
  "%-3lc%+-5.5d%+-5.5i%-5.5lf%-6.6s%-5.u%%", '?', 42, 24, 3.1415926535897932, "WTF", 28);
  ck_assert_str_eq(str153, str154);
  ck_assert_int_eq(len153, len154);

  char str155[512] = "";
  char str156[512] = "";
  int len155 = s21_sprintf(str155, "%-5.u%%%-3lc%+-5.5d%+-5.5i%-5.5lf%-6.6s",
                          28, '?', 24, 42, 3.1415926535897932, "WTF");
  int len156 = snprintf(str156, sizeof(str1),
                       "%-5.u%%%-3lc%+-5.5d%+-5.5i%-5.5lf%-6.6s", 28, '?', 24, 42, 3.1415926535897932, "WTF");
  ck_assert_str_eq(str155, str156);
  ck_assert_int_eq(len155, len156);

  char str157[512] = "";
  char str158[512] = "";
  int len157 = s21_sprintf(str157, "%u%%%c%d%i%f%s", 28, '?', 24, 42, 3.1415926535897932, "WTF");
  int len158 = snprintf(str158, sizeof(str1), "%u%%%c%d%i%f%s", 28, '?', 24, 42, 3.1415926535897932, "WTF");
  ck_assert_str_eq(str157, str158);
  ck_assert_int_eq(len157, len158);

  char str159[512] = "";
  char str160[512] = "";
  int len159 = s21_sprintf(str159, "%hi", 52787);
  int len160 = snprintf(str160, sizeof(str1), "%hi", 52787);
  ck_assert_str_eq(str159, str160);
  ck_assert_int_eq(len159, len160);

  char str161[512] = "";
  char str162[512] = "";
  int len161 = s21_sprintf(str161, "%Lf",  (long double)3.1415926535897932384626433832795028841971);
  int len162 = snprintf(str162, sizeof(str1), "%Lf",
                       (long double)3.1415926535897932384626433832795028841971);
  ck_assert_str_eq(str161, str162);
  ck_assert_int_eq(len161, len162);

  char str163[512] = "";
  char str164[512] = "";
  int len163 = s21_sprintf(str163, "%ls", L"ஹலோ உலகம்");
  int len164 = snprintf(str164, sizeof(str1), "%ls", L"ஹலோ உலகம்");
  ck_assert_str_eq(str163, str164);
  ck_assert_int_eq(len163, len164);

  char str165[512] = "";
  char str166[512] = "";
  int len165 = s21_sprintf(str165, "%hi", 52787);
  int len166 = snprintf(str166, sizeof(str1), "%hi", 52787);
  ck_assert_str_eq(str165, str166);
  ck_assert_int_eq(len165, len166);

  char str167[512] = "";
  char str168[512] = "";
  int len167 = s21_sprintf(str167, "%li", (long) 2147483647);
  int len168 = snprintf(str168, sizeof(str1), "%li", (long) 2147483647);
  ck_assert_str_eq(str167, str168);
  ck_assert_int_eq(len167, len168);

  char str169[512] = "";
  char str170[512] = "";
  int len169 = s21_sprintf(str169, "%lc", L'Ы');
  int len170 = snprintf(str170, sizeof(str1), "%lc", L'Ы');
  ck_assert_str_eq(str169, str170);
  ck_assert_int_eq(len169, len170);

  char str171[512] = "";
  char str172[512] = "";
  wchar_t * src171 = L"превед";
  int len171 = s21_sprintf(str171, "%-10.ls", src171);
  int len172 = snprintf(str172, sizeof(str1), "%-10.0ls", src171);
  ck_assert_str_eq(str171, str172);
  ck_assert_int_eq(len171, len172);

  char str173[512] = "";
  char str174[512] = "";
  wchar_t * src173 = L"ЮЖЪ";
  int len173 = s21_sprintf(str173, "%.0ls", src173);
  int len174 = snprintf(str174, sizeof(str1), "%.0ls", src173);
  ck_assert_str_eq(str173, str174);
  ck_assert_int_eq(len173, len174);
  }
END_TEST

int main(void) {
  (void)setlocale(LC_ALL, "");
  Suite *string_suite = suite_create("s21_String_suite");
  SRunner *suiteRunner = srunner_create(string_suite);
  int statusFlag;

  TCase *stringCase = tcase_create("s21_stringCase");

  suite_add_tcase(string_suite, stringCase);

  tcase_add_test(stringCase, memchrTest);
  tcase_add_test(stringCase, memcmpTest);
  tcase_add_test(stringCase, memcpyTest);
  tcase_add_test(stringCase, memmoveTest);
  tcase_add_test(stringCase, memsetTest);
  tcase_add_test(stringCase, strcatTest);
  tcase_add_test(stringCase, strncatTest);
  tcase_add_test(stringCase, strchrTest);
  tcase_add_test(stringCase, strcmpTest);
  tcase_add_test(stringCase, strncmpTest);
  tcase_add_test(stringCase, strcpyTest);
  tcase_add_test(stringCase, strncpyTest);
  tcase_add_test(stringCase, strcspnTest);
  tcase_add_test(stringCase, strerrorTest);
  tcase_add_test(stringCase, strlenTest);
  tcase_add_test(stringCase, strpbrkTest);
  tcase_add_test(stringCase, strrchrTest);
  tcase_add_test(stringCase, strspnTest);
  tcase_add_test(stringCase, strstrTest);
  tcase_add_test(stringCase, strtokTest);
  tcase_add_test(stringCase, to_upperTest);
  tcase_add_test(stringCase, to_lowerTest);
  tcase_add_test(stringCase, insertTest);
  tcase_add_test(stringCase, trimTest);
  tcase_add_test(stringCase, sprintfTest);

  srunner_run_all(suiteRunner, CK_ENV);
  statusFlag = srunner_ntests_failed(suiteRunner);
  srunner_free(suiteRunner);
  return statusFlag == 0 ? 0 : 1;
}
