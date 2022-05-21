#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>

#define EXP_MASK 0x00ff0000;
#define NULL_SCALE 0x80000000;
#define NULL_MASK 0x00000000;
#define DECIMAL_NORMAL {{0, 0, 0, 0}, s21_NORMAL_VALUE};
#define DECIMAL_NORMAL_SUPER {{0, 0, 0, 0, 0, 0, 0}, s21_NORMAL_VALUE};

enum { LOW, MID, HIGH, SCALE };
enum { NLOW, NMID, NHIGH, SLOW, SMID, SHIGH, SSCALE };

typedef enum {
  s21_NORMAL_VALUE = 0,
  s21_INFINITY = 1,
  s21_NEGATIVE_INFINITY = 2,
  s21_NAN = 3
} value_type_t;

typedef struct {
  unsigned int bits[4];
  value_type_t value_type;
} s21_decimal;

typedef struct {
  unsigned int bits[7];
  value_type_t value_type;
} s21_decimal_super;

//  Арифметические операторы
//  При ошибке во время операции в переменную value_type записывается тип ошибки
s21_decimal s21_add(s21_decimal, s21_decimal);
s21_decimal s21_sub(s21_decimal, s21_decimal);
s21_decimal s21_mul(s21_decimal, s21_decimal);
s21_decimal s21_div(s21_decimal, s21_decimal);
s21_decimal s21_mod(s21_decimal, s21_decimal);

//  Операторы сравнение
//  Возвращаемое значение: 0 - TRUE, 1 - FALSE
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

//  Преобразователи
//  Возвращаемое значение - код ошибки: 0 - SUCCESS, 1 - CONVERTING ERROR
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

//  Другие функции
s21_decimal s21_floor(s21_decimal);
s21_decimal s21_round(s21_decimal);
s21_decimal s21_truncate(s21_decimal);
s21_decimal s21_negate(s21_decimal);

//  Вспомогательные функции
void s21_decimal_set_default(s21_decimal *dst);

// Установка и получение bit, scale
int s21_getBit(s21_decimal src, int i);
void s21_setBit(s21_decimal *dst, int i, int value);
int s21_getScale(s21_decimal src);
void s21_setScale(s21_decimal *dst, int value);
int s21_getFloatExp(float src);
int s21_getBitFloat(float src, int i);

// Функции установки знака "-" или "+" в SCALE*/
void s21_setSign(s21_decimal *dst, int value);
int s21_getSign(s21_decimal src);  // функция получения знака числа

// Умножение decimal на 10 */
s21_decimal s21_multi_10(s21_decimal src);
// Сдвиг влево
s21_decimal s21_move_left(s21_decimal src, int shift);
// Функция установки в decimal inf + super decimal inf
s21_decimal s21_decimal_set_inf(int sign);

// Функции выравнивания scale
void s21_equality_scale(s21_decimal *dec1, s21_decimal *dec2);
s21_decimal s21_increase_scale(int diffScale, s21_decimal src);

// Функция деления decimal на 10
s21_decimal s21_div_10_decimal(s21_decimal);
int s21_decimal_equal_int(s21_decimal dec, unsigned int value);
int s21_move_left_for_div(s21_decimal dec1, s21_decimal *dec2);
s21_decimal s21_move_right(s21_decimal src, int shift);
int s21_mod_div_10(s21_decimal src_s);

/*------- super decimal fuctions start -----------*/
s21_decimal_super s21_convert_to_super(s21_decimal);
void s21_displayBits_super(s21_decimal_super);
void s21_equality_scale_super(s21_decimal_super *dec1_s,
                              s21_decimal_super *dec2_s);
s21_decimal_super s21_increase_scale_super(int diffScale,
                                           s21_decimal_super src_s);
s21_decimal_super s21_multi_10_super(s21_decimal_super src_s);
s21_decimal_super s21_move_left_super(s21_decimal_super src_s, int shift);
s21_decimal_super s21_super_set_inf(int sign);
s21_decimal_super s21_add_simple_super(s21_decimal_super dec1_s,
                                       s21_decimal_super dec2_s);

int s21_getBit_super(s21_decimal_super src_s, int i);
int s21_getSign_super(s21_decimal_super src_s);
void s21_setBit_super(s21_decimal_super *dst_s, int i, int value);
void s21_setScale_super(s21_decimal_super *dst_s, int value);
int s21_getScale_super(s21_decimal_super src);
void s21_setSign_super(s21_decimal_super *dst, int value);
s21_decimal s21_convert_to_decimal(s21_decimal_super);
s21_decimal_super s21_div_10_super(s21_decimal_super src_s);
s21_decimal_super s21_sub_simple_super(s21_decimal_super dec1_s, s21_decimal_super dec2_s);
int s21_mod_div_10_super(s21_decimal_super src_s);
s21_decimal_super s21_move_right_super(s21_decimal_super src, int shift);
int s21_move_left_for_div_super(s21_decimal_super dec1, s21_decimal_super *dec2);
s21_decimal_super s21_mod_super(s21_decimal_super dec1, s21_decimal_super dec2);
s21_decimal_super s21_div_simple_super(s21_decimal_super dec1, s21_decimal_super dec2);
int s21_is_greater_or_equal_super(s21_decimal_super dec1_s, s21_decimal_super dec2_s);
int s21_is_greater_super(s21_decimal_super dec1_s, s21_decimal_super dec2_s);
int s21_is_equal_super(s21_decimal_super dec1_s, s21_decimal_super dec2_s);
int s21_decimal_is_equal_null_super(s21_decimal_super dec);
/*------- super decimal fuctions end -----------*/

#endif  //  SRC_S21_DECIMAL_H_
