#include <check.h>

#include "s21_decimal.h"

START_TEST(not_equal1) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 2;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(not_equal2) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 4;
  dec2.bits[3] = POWER;

  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(not_equal3) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = 0;

  int res = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(equal) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less1) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 0;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less2) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 0;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less3) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 0;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less4) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER * 2;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less5) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = -1;
  dec1.bits[1] = -1;
  dec1.bits[2] = -1;
  dec1.bits[3] = 0;

  dec2.bits[0] = -1;
  dec2.bits[1] = -1;
  dec2.bits[2] = -1;
  dec2.bits[3] = POWER * 28;

  int res = s21_is_less(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less6) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = POWER - SHIFT;

  int res = s21_is_less(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less7) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 2;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = (1 << 31);

  dec2.bits[0] = 1;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = (1 << 31);

  int res = s21_is_less(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(gre1) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 0;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_greater(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(gre2) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 0;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_greater(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(gre3) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 0;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_greater(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(gre4) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER * 2;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_greater(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(gre5) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = -1;
  dec1.bits[1] = -1;
  dec1.bits[2] = -1;
  dec1.bits[3] = 0;

  dec2.bits[0] = -1;
  dec2.bits[1] = -1;
  dec2.bits[2] = -1;
  dec2.bits[3] = POWER * 28;

  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(gre6) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = POWER - SHIFT;

  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(gre7) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = (1 << 31);

  dec2.bits[0] = 2;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = (1 << 31);

  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(lessequal0) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(lessequal1) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 0;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(lessequal2) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 0;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(lessequal3) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 0;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(lessequal4) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER * 2;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(aux_greater1) {
  aux dec1, dec2;
  dec1.sign = 0;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = 1;
  dec1.bits[4] = 1;
  dec1.bits[5] = 1;

  dec2.sign = 1 << 31;
  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = 1;
  dec2.bits[4] = 1;
  dec2.bits[5] = 1;

  int res = aux_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(aux_greater2) {
  aux dec1, dec2;
  dec1.sign = 1 << 31;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = 1;
  dec1.bits[4] = 1;
  dec1.bits[5] = 1;

  dec2.sign = 1 << 31;
  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = 0;
  dec2.bits[4] = 1;
  dec2.bits[5] = 1;

  int res = aux_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(aux_greater3) {
  aux dec1, dec2;
  dec1.sign = 0;
  dec1.bits[0] = 1;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = 0;
  dec1.bits[4] = 0;
  dec1.bits[5] = 0;

  dec2.sign = POWER * 10;
  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 0;
  dec2.bits[3] = 0;
  dec2.bits[4] = 0;
  dec2.bits[5] = 0;

  int res = aux_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(lessequal5) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = -1;
  dec1.bits[1] = -1;
  dec1.bits[2] = -1;
  dec1.bits[3] = 0;

  dec2.bits[0] = -1;
  dec2.bits[1] = -1;
  dec2.bits[2] = -1;
  dec2.bits[3] = POWER * 28;

  int res = s21_is_less_or_equal(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(lessequal6) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = POWER - SHIFT;

  int res = s21_is_less_or_equal(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(grequal0) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_greater_or_equal(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(grequal1) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 0;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_greater_or_equal(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(grequal2) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 0;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_greater_or_equal(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(grequal3) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 0;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_greater_or_equal(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(grequal4) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 1;
  dec1.bits[2] = 1;
  dec1.bits[3] = POWER * 2;

  dec2.bits[0] = 1;
  dec2.bits[1] = 1;
  dec2.bits[2] = 1;
  dec2.bits[3] = POWER;

  int res = s21_is_greater_or_equal(dec2, dec1);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(grequal5) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = -1;
  dec1.bits[1] = -1;
  dec1.bits[2] = -1;
  dec1.bits[3] = 0;

  dec2.bits[0] = -1;
  dec2.bits[1] = -1;
  dec2.bits[2] = -1;
  dec2.bits[3] = POWER * 28;

  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(grequal6) {
  s21_decimal dec1, dec2;
  dec1.bits[0] = 1;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = POWER;

  dec2.bits[0] = 1;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = POWER - SHIFT;

  int res = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(toINT1) {
  s21_decimal dec;
  dec.bits[0] = 10;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = POWER;
  int conv, val = 1;
  int res = s21_from_decimal_to_int(dec, &conv);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(conv, val);
}
END_TEST

START_TEST(toINT2) {
  s21_decimal dec;
  dec.bits[0] = 9;
  dec.bits[1] = 0;
  dec.bits[2] = 0;
  dec.bits[3] = POWER;
  int conv, val = 0;
  int res = s21_from_decimal_to_int(dec, &conv);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(conv, val);
}
END_TEST

START_TEST(toINT3) {
  s21_decimal dec;
  dec.bits[0] = 0;
  dec.bits[1] = 2;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  int conv;
  int res = s21_from_decimal_to_int(dec, &conv);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(toINT4) {
  s21_decimal dec;
  dec.bits[0] = 0;
  dec.bits[1] = 4;
  dec.bits[2] = 0;
  dec.bits[3] = 0;
  int conv;
  int res = s21_from_decimal_to_int(dec, &conv);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(toINT5) {
  int conv;
  s21_decimal dec = {{100, 0, 0, 1 << 31}};
  int res = s21_from_decimal_to_int(dec, &conv);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(conv, -100);
}
END_TEST

START_TEST(fromINTtoDEC1) {
  int value = 100;
  s21_decimal src, val = {{100, 0, 0, 0}};
  int res = s21_from_int_to_decimal(value, &src);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(src.bits[0], val.bits[0]);
  ck_assert_int_eq(src.bits[1], val.bits[1]);
  ck_assert_int_eq(src.bits[2], val.bits[2]);
  ck_assert_int_eq(src.bits[3], val.bits[3]);
}
END_TEST

START_TEST(fromINTtoDEC2) {
  int value = -100;
  s21_decimal src, val = {{100, 0, 0, 1 << 31}};
  int res = s21_from_int_to_decimal(value, &src);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(src.bits[0], val.bits[0]);
  ck_assert_int_eq(src.bits[1], val.bits[1]);
  ck_assert_int_eq(src.bits[2], val.bits[2]);
  ck_assert_int_eq(src.bits[3], val.bits[3]);
}
END_TEST

START_TEST(fromFLOATtoDEC1) {
  float value = 2.0e-32f;
  s21_decimal src;
  int res = s21_from_float_to_decimal(value, &src);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(fromFLOATtoDEC2) {
  float value = 7.9229e29f;
  s21_decimal src;
  int res = s21_from_float_to_decimal(value, &src);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(fromFLOATtoDEC3) {
  float value = 7.9225e28f;
  char str[] = "79225000000000000000000000000";
  s21_decimal src, val;
  unsigned_decimal result = from_string_to_unsigned(str);
  vice_versa(result, &val);
  int res = s21_from_float_to_decimal(value, &src);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(src.bits[0], val.bits[0]);
  ck_assert_int_eq(src.bits[1], val.bits[1]);
  ck_assert_int_eq(src.bits[2], val.bits[2]);
  ck_assert_int_eq(src.bits[3], val.bits[3]);
}
END_TEST

START_TEST(fromFLOATtoDEC4) {
  float value = -7.9229f;
  s21_decimal src, val = {{79229, 0, 0, (1 << 31) + POWER * 4}};
  int res = s21_from_float_to_decimal(value, &src);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(src.bits[0], val.bits[0]);
  ck_assert_int_eq(src.bits[1], val.bits[1]);
  ck_assert_int_eq(src.bits[2], val.bits[2]);
  ck_assert_int_eq(src.bits[3], val.bits[3]);
}
END_TEST

START_TEST(fromFLOATtoDEC5) {
  float value = -7.922921f;
  s21_decimal src, val = {{7922921, 0, 0, (1 << 31) + POWER * 6}};
  int res = s21_from_float_to_decimal(value, &src);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(src.bits[0], val.bits[0]);
  ck_assert_int_eq(src.bits[1], val.bits[1]);
  ck_assert_int_eq(src.bits[2], val.bits[2]);
  ck_assert_int_eq(src.bits[3], val.bits[3]);
}
END_TEST

START_TEST(fromFLOATtoDEC6) {
  float value = -7.9229e-5f;
  s21_decimal src, val = {{79229, 0, 0, (1 << 31) + (POWER * 9)}};
  int res = s21_from_float_to_decimal(value, &src);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(src.bits[0], val.bits[0]);
  ck_assert_int_eq(src.bits[1], val.bits[1]);
  ck_assert_int_eq(src.bits[2], val.bits[2]);
  ck_assert_int_eq(src.bits[3], val.bits[3]);
}
END_TEST

START_TEST(fromFLOATtoDEC7) {
  float value = -7.9225e28f;
  char str[] = "-79225000000000000000000000000";
  s21_decimal src, val;
  unsigned_decimal result = from_string_to_unsigned(str);
  vice_versa(result, &val);
  int res = s21_from_float_to_decimal(value, &src);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(src.bits[0], val.bits[0]);
  ck_assert_int_eq(src.bits[1], val.bits[1]);
  ck_assert_int_eq(src.bits[2], val.bits[2]);
  ck_assert_int_eq(src.bits[3], val.bits[3]);
}
END_TEST

START_TEST(fromFLOATtoDEC8) {
  float value = 2.0e-20f;
  s21_decimal src, val;
  char str[] = "0.00000000000000000002";
  unsigned_decimal result = from_string_to_unsigned(str);
  vice_versa(result, &val);
  int res = s21_from_float_to_decimal(value, &src);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(src.bits[0], val.bits[0]);
  ck_assert_int_eq(src.bits[1], val.bits[1]);
  ck_assert_int_eq(src.bits[2], val.bits[2]);
  ck_assert_int_eq(src.bits[3], val.bits[3]);
}
END_TEST

START_TEST(fromFLOATtoDEC9) {
  float value = -79225.0f;
  char str[] = "-79225";
  s21_decimal src, val;
  unsigned_decimal result = from_string_to_unsigned(str);
  vice_versa(result, &val);
  int res = s21_from_float_to_decimal(value, &src);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(src.bits[0], val.bits[0]);
  ck_assert_int_eq(src.bits[1], val.bits[1]);
  ck_assert_int_eq(src.bits[2], val.bits[2]);
  ck_assert_int_eq(src.bits[3], val.bits[3]);
}
END_TEST

START_TEST(toFLOAT1) {
  s21_decimal src = {{-1, -1, -1, 0}};
  float value, valU = 79228170000000000000000000000.0f,
               valD = 79228150000000000000000000000.0f;
  int res = s21_from_decimal_to_float(src, &value);
  ck_assert_int_eq(res, 0);
  ck_assert_float_le(value, valU);
  ck_assert_float_ge(value, valD);
}
END_TEST

START_TEST(toFLOAT2) {
  s21_decimal src = {{1, 0, 0, POWER}};
  float value, val = 0.1f;
  int res = s21_from_decimal_to_float(src, &value);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(value, val);
}
END_TEST

START_TEST(toFLOAT3) {
  char str[60] = "1234567.8";
  unsigned_decimal v = from_string_to_unsigned(str);
  s21_decimal src;
  vice_versa(v, &src);
  float value, val = 1234567.8f;
  int res = s21_from_decimal_to_float(src, &value);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(value, val);
}
END_TEST

START_TEST(toFLOAT4) {
  char str[60] = "123.45678";
  unsigned_decimal v = from_string_to_unsigned(str);
  s21_decimal src;
  vice_versa(v, &src);
  float value, val = 123.45678f;
  int res = s21_from_decimal_to_float(src, &value);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(value, val);
}
END_TEST

START_TEST(toFLOAT5) {
  char str[60] = "7.9228162514264337593543950335";
  unsigned_decimal v = from_string_to_unsigned(str);
  s21_decimal src;
  vice_versa(v, &src);
  float value, val = 7.922816f;
  int res = s21_from_decimal_to_float(src, &value);
  float diff = value - val;
  ck_assert_int_eq(res, 0);
  ck_assert_float_le(diff, 0.000001f);
}
END_TEST

START_TEST(toFLOAT6) {
  char str[60] = "792281625142.64337593543950335";
  unsigned_decimal v = from_string_to_unsigned(str);
  s21_decimal src;
  vice_versa(v, &src);
  float value, val = 7.922816e11f;
  int res = s21_from_decimal_to_float(src, &value);
  float diff = value - val;
  ck_assert_int_eq(res, 0);
  ck_assert_float_le(diff, 1e5f);
}
END_TEST

START_TEST(toFLOAT7) {
  char str[60] = "792281.62514264337593543950335";
  unsigned_decimal v = from_string_to_unsigned(str);
  s21_decimal src;
  vice_versa(v, &src);
  float value, val = 7.922816e5f;
  int res = s21_from_decimal_to_float(src, &value);
  float diff = value - val;
  ck_assert_int_eq(res, 0);
  ck_assert_float_le(diff, 0.1f);
}
END_TEST

START_TEST(toFLOAT8) {
  char str[60] = "-7.9228162514264337593543950335";
  unsigned_decimal v = from_string_to_unsigned(str);
  s21_decimal src;
  vice_versa(v, &src);
  float value, val = -7.9228162514264337593543950335f;
  int res = s21_from_decimal_to_float(src, &value);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(value, val);
}
END_TEST

START_TEST(toFLOAT9) {
  char str[60] = "-792281625142.64337593543950335";
  unsigned_decimal v = from_string_to_unsigned(str);
  s21_decimal src;
  vice_versa(v, &src);
  float value, val = -792281625142.64337593543950335f;
  int res = s21_from_decimal_to_float(src, &value);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(value, val);
}
END_TEST

START_TEST(toFLOAT10) {
  char str[60] = "-792281.62514264337593543950335";
  unsigned_decimal v = from_string_to_unsigned(str);
  s21_decimal src;
  vice_versa(v, &src);
  float value, val = -7.922816e5f;
  int res = s21_from_decimal_to_float(src, &value);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(value, val);
}
END_TEST

START_TEST(toFLOAT11) {
  char str[60] = "-10000000000";
  unsigned_decimal v = from_string_to_unsigned(str);
  s21_decimal src;
  vice_versa(v, &src);
  float value, val = -1e10f;
  int res = s21_from_decimal_to_float(src, &value);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(value, val);
}
END_TEST

START_TEST(add1) {
  char str1[60] = "79228162514264337593543950327";
  char str2[60] = "7.9228162514264337593543950334";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  s21_decimal value_1, value_2, result, m = {{-1, -1, -1, 0}};
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  int res = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(add2) {
  char str1[60] = "79228162514264337593543950335";
  char str2[60] = "-1";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  s21_decimal value_1, value_2, result, m = {{-2, -1, -1, 0}};
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  int res = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(add3) {
  char str1[60] = "79228162514264337593543950335";
  char str2[60] = "1";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  s21_decimal value_1, value_2, result;
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  int res = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(add4) {
  char str1[60] = "-79228162514264337593543950335";
  char str2[60] = "-1";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  s21_decimal value_1, value_2, result;
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  int res = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(sub1) {
  char str1[60] = "79228162514264337593543950335";
  char str2[60] = "7.9228162514264337593543950334";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  s21_decimal value_1, value_2, result, m = {{-9, -1, -1, 0}};
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub2) {
  char str1[60] = "79228162514264337593543950335";
  char str2[60] = "1";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  s21_decimal value_1, value_2, result, m = {{-2, -1, -1, 0}};
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub3) {
  char str1[60] = "79228162514264337593543950335";
  char str2[60] = "-1";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  s21_decimal value_1, value_2, result;
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(sub4) {
  char str1[60] = "-79228162514264337593543950335";
  char str2[60] = "1";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  s21_decimal value_1, value_2, result;
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(sub5) {
  s21_decimal value_1 = {{0, 1, 0, 0}}, value_2 = {{1, 0, 0, 0}}, result,
              m = {{-1, 0, 0, 0}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub6) {
  s21_decimal value_1 = {{0, 0, 1, 0}}, value_2 = {{0, 0, 2, 0}}, result,
              m = {{0, 0, 1, 1 << 31}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub7) {
  s21_decimal value_1 = {{1, 0, 0, 0}}, value_2 = {{1, 0, 0, POWER}}, result,
              m = {{9, 0, 0, POWER}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub8) {
  s21_decimal value_1 = {{1, 0, 0, 2 * POWER}}, value_2 = {{1, 0, 0, POWER}},
              result, m = {{9, 0, 0, (1 << 31) + 2 * POWER}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub9) {
  s21_decimal value_1 = {{0, 0, 1, 0}}, value_2 = {{1, 0, 0, POWER * 28}},
              result, m = {{0, 0, 1, 0}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub10) {
  s21_decimal value_1 = {{0, 0, 1, 0}}, value_2 = {{0, 1, 0, 0}}, result,
              m = {{0, -1, 0, 0}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub11) {
  s21_decimal value_1 = {{0, 0, 1, 0}}, value_2 = {{1, 0, 0, 0}}, result,
              m = {{-1, -1, 0, 0}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub12) {
  s21_decimal value_1 = {{0, 1, 0, 0}}, value_2 = {{0, 2, 0, 0}}, result,
              m = {{0, 1, 0, 1 << 31}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub13) {
  s21_decimal value_1 = {{0, 1, 0, 0}}, value_2 = {{1, 0, 0, POWER * 20}},
              result, m = {{0, 1, 0, 0}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub14) {
  s21_decimal value_1 = {{0, 0, 1, 0}}, value_2 = {{1, 0, 0, POWER * 28}},
              result, m = {{0, 0, 1, 1 << 31}};
  int res = s21_sub(value_2, value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub15) {
  s21_decimal value_1 = {{0, 1, 0, 0}}, value_2 = {{1, 0, 0, POWER * 28}},
              result, m = {{0, 1, 0, 1 << 31}};
  int res = s21_sub(value_2, value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub16) {
  s21_decimal value_1 = {{1, 0, 1, 0}}, value_2 = {{2, 0, 2, POWER * 27}},
              result, m = {{999999963, 0, 1000000000, (1 << 31) + 589824}};
  int res = s21_sub(value_2, value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub17) {
  s21_decimal value_1 = {{1, 0, 1, 0}}, value_2 = {{0, 2, 0, POWER * 27}},
              result, m = {{1, 0, 1, 0}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub18) {
  s21_decimal value_1 = {{0, 0, 10000, 0}}, value_2 = {{1, 0, 0, POWER * 28}},
              result, m = {{0, 0, 10000, 0}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub19) {
  s21_decimal value_1 = {{0, 0, 100000000, 0}},
              value_2 = {{1, 0, 0, POWER * 28}}, result,
              m = {{0, 0, 100000000, 1 << 31}};
  int res = s21_sub(value_2, value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub20) {
  s21_decimal value_1 = {{0, 0, 100000000, 0}},
              value_2 = {{0, 1, 0, POWER * 28}}, result,
              m = {{0, 0, 100000000, 1 << 31}};
  int res = s21_sub(value_2, value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub21) {
  s21_decimal value_1 = {{0, 0, 100, 0}}, value_2 = {{0, 0, 1, POWER * 28}},
              result, m = {{0, 0, 100, 1 << 31}};
  int res = s21_sub(value_2, value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub22) {
  s21_decimal value_1 = {{0, 1, 0, POWER * 28}}, value_2, result,
              m = {{1522115079, 1593240287, 1844674407, 0}};
  char valu2[60] = "34028236692093846346337460743";
  unsigned_decimal val1, val2 = from_string_to_unsigned(valu2);
  converter(value_1, &val1);
  vice_versa(val2, &value_2);
  int res = s21_sub(value_2, value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub23) {
  s21_decimal value_1 = {{0, 0, 0, 0}}, value_2 = {{1, 0, 0, 0}}, result,
              m = {{1, 0, 0, 1 << 31}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(sub24) {
  s21_decimal value_1 = {{1, 0, 0, 0}}, value_2 = {{0, 0, 0, 0}}, result,
              m = {{1, 0, 0, 0}};
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(mul1) {
  char str1[60] = "79228162514264337593543950335";
  char str2[60] = "0.000000000000000000000000001";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  s21_decimal value_1, value_2, result, m = {{-1, -1, -1, POWER * 27}};
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(mul2) {
  char str1[60] = "7922816251426433759354395.0335";
  char str2[60] = "0.000000000000000000000000001";
  char re[60] = "0.007922816251426433759354395";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  unsigned_decimal r = from_string_to_unsigned(re);
  s21_decimal value_1, value_2, result, m;
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  vice_versa(r, &m);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(mul3) {
  char str1[60] = "79228162514264337593543950335";
  char str2[60] = "79228162514264337593543950335";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  s21_decimal value_1, value_2, result;
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(mul4) {
  char str1[60] = "-79228162514264337593543950335";
  char str2[60] = "79228162514264337593543950335";
  unsigned_decimal var1 = from_string_to_unsigned(str1);
  unsigned_decimal var2 = from_string_to_unsigned(str2);
  s21_decimal value_1, value_2, result;
  vice_versa(var1, &value_1);
  vice_versa(var2, &value_2);
  int res = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(flr1) {
  s21_decimal value_1 = {{123456, 0, 0, POWER * 3}}, result,
              m = {{123, 0, 0, 0}};
  int res = s21_floor(value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(flr2) {
  s21_decimal value_1 = {{123456, 0, 0, (1 << 31) + POWER * 3}}, result,
              m = {{124, 0, 0, 1 << 31}};
  int res = s21_floor(value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(trnct) {
  s21_decimal value_1 = {{123456, 0, 0, (1 << 31) + POWER * 3}}, result,
              m = {{123, 0, 0, 1 << 31}};
  int res = s21_truncate(value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(neg) {
  s21_decimal value_1 = {{123, 0, 0, 1 << 31}}, result, m = {{123, 0, 0, 0}};
  int res = s21_negate(value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(rnd1) {
  s21_decimal value_1 = {{123, 0, 0, POWER}}, result, m = {{12, 0, 0, 0}};
  int res = s21_round(value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(rnd2) {
  s21_decimal value_1 = {{126, 0, 0, POWER}}, result, m = {{13, 0, 0, 0}};
  int res = s21_round(value_1, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], m.bits[0]);
  ck_assert_int_eq(result.bits[1], m.bits[1]);
  ck_assert_int_eq(result.bits[2], m.bits[2]);
  ck_assert_int_eq(result.bits[3], m.bits[3]);
}
END_TEST

START_TEST(divzero) {
  s21_decimal dividend = {{10, 0, 0, 0}}, divider = {{0, 0, 0, 0}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(div0) {
  s21_decimal dividend = {{0, 0, 0, 0}}, divider = {{5, 0, 0, 0}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(div1) {
  s21_decimal dividend = {{10, 0, 0, 0}}, divider = {{5, 0, 0, 0}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], 2);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(div2) {
  s21_decimal dividend = {{4, 1, 0, 0}}, divider = {{10, 0, 0, 0}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq((unsigned)result.bits[0], 429496730);
  ck_assert_int_eq((unsigned)result.bits[1], 0);
  ck_assert_int_eq((unsigned)result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(div3) {
  s21_decimal dividend = {{10, 0, 0, 0}},
              divider = {{1, 0, 0, 5 * POWER - SHIFT}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], 1000000);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], -SHIFT);
}
END_TEST

START_TEST(div4) {
  s21_decimal dividend = {{0, 0, 1, 0}}, divider = {{0, 1, 0, 0}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 1);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(divbig) {
  s21_decimal dividend = {{9999999, 9999999, 9999999, 0}},
              divider = {{1, 0, 0, POWER * 28}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(divsmol) {
  s21_decimal dividend = {{9999999, 9999999, 9999999, 0}},
              divider = {{1, 0, 0, POWER * 28 - SHIFT}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(divround) {
  s21_decimal dividend = {{5, 0, 0, 28 * POWER - SHIFT}},
              divider = {{2, 0, 0, 0}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], 3);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 28 * POWER - SHIFT);
}
END_TEST

START_TEST(divbuf) {
  s21_decimal dividend = {{1, 0, 0, POWER}}, divider = {{1, 1, 1, 0}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], 54210109);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 28 * POWER);
}
END_TEST

START_TEST(divdec) {
  s21_decimal dividend = {{-2147483647, -2147483647, -2147483647, 0}},
              divider = {{0, 0, 1, 0}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], -1626950521);
  ck_assert_int_eq(result.bits[1], 354333831);
  ck_assert_int_eq(result.bits[2], 1164153219);
  ck_assert_int_eq(result.bits[3], 19 * POWER);
}
END_TEST

START_TEST(div_zero) {
  s21_decimal dividend = {{0, 0, 0, 0}}, divider = {{0, 0, 1, 0}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(div_minus) {
  s21_decimal dividend = {{1, 0, 0, 0}}, divider = {{1, 0, 0, -SHIFT}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], 1);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], -SHIFT);
}
END_TEST

START_TEST(div_over) {
  s21_decimal dividend = {{0, 3, 0, 0}}, divider = {{-SHIFT, 1, 0, 0}}, result;
  int res = s21_div(dividend, divider, &result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(result.bits[0], 2);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc);
  tcase_add_test(tc, equal);
  tcase_add_test(tc, not_equal1);
  tcase_add_test(tc, not_equal2);
  tcase_add_test(tc, not_equal3);
  tcase_add_test(tc, less1);
  tcase_add_test(tc, less2);
  tcase_add_test(tc, less3);
  tcase_add_test(tc, less4);
  tcase_add_test(tc, less5);
  tcase_add_test(tc, less6);
  tcase_add_test(tc, less7);
  tcase_add_test(tc, gre1);
  tcase_add_test(tc, gre2);
  tcase_add_test(tc, gre3);
  tcase_add_test(tc, gre4);
  tcase_add_test(tc, gre5);
  tcase_add_test(tc, gre6);
  tcase_add_test(tc, gre7);
  tcase_add_test(tc, lessequal0);
  tcase_add_test(tc, lessequal1);
  tcase_add_test(tc, lessequal2);
  tcase_add_test(tc, lessequal3);
  tcase_add_test(tc, lessequal4);
  tcase_add_test(tc, lessequal5);
  tcase_add_test(tc, lessequal6);
  tcase_add_test(tc, grequal0);
  tcase_add_test(tc, grequal1);
  tcase_add_test(tc, grequal2);
  tcase_add_test(tc, grequal3);
  tcase_add_test(tc, grequal4);
  tcase_add_test(tc, grequal5);
  tcase_add_test(tc, grequal6);
  tcase_add_test(tc, toINT1);
  tcase_add_test(tc, toINT2);
  tcase_add_test(tc, toINT3);
  tcase_add_test(tc, toINT4);
  tcase_add_test(tc, toINT5);
  tcase_add_test(tc, fromINTtoDEC1);
  tcase_add_test(tc, fromINTtoDEC2);
  tcase_add_test(tc, fromFLOATtoDEC1);
  tcase_add_test(tc, fromFLOATtoDEC2);
  tcase_add_test(tc, fromFLOATtoDEC3);
  tcase_add_test(tc, fromFLOATtoDEC4);
  tcase_add_test(tc, fromFLOATtoDEC5);
  tcase_add_test(tc, fromFLOATtoDEC6);
  tcase_add_test(tc, fromFLOATtoDEC7);
  tcase_add_test(tc, fromFLOATtoDEC8);
  tcase_add_test(tc, fromFLOATtoDEC9);
  tcase_add_test(tc, toFLOAT1);
  tcase_add_test(tc, toFLOAT2);
  tcase_add_test(tc, toFLOAT3);
  tcase_add_test(tc, toFLOAT4);
  tcase_add_test(tc, toFLOAT5);
  tcase_add_test(tc, toFLOAT6);
  tcase_add_test(tc, toFLOAT7);
  tcase_add_test(tc, toFLOAT8);
  tcase_add_test(tc, toFLOAT9);
  tcase_add_test(tc, toFLOAT10);
  tcase_add_test(tc, toFLOAT11);
  tcase_add_test(tc, add1);
  tcase_add_test(tc, add2);
  tcase_add_test(tc, add3);
  tcase_add_test(tc, add4);
  tcase_add_test(tc, sub1);
  tcase_add_test(tc, sub2);
  tcase_add_test(tc, sub3);
  tcase_add_test(tc, sub4);
  tcase_add_test(tc, sub5);
  tcase_add_test(tc, sub6);
  tcase_add_test(tc, sub7);
  tcase_add_test(tc, sub8);
  tcase_add_test(tc, sub9);
  tcase_add_test(tc, sub10);
  tcase_add_test(tc, sub11);
  tcase_add_test(tc, sub12);
  tcase_add_test(tc, sub13);
  tcase_add_test(tc, sub14);
  tcase_add_test(tc, sub15);
  tcase_add_test(tc, sub16);
  tcase_add_test(tc, sub17);
  tcase_add_test(tc, sub18);
  tcase_add_test(tc, sub19);
  tcase_add_test(tc, sub20);
  tcase_add_test(tc, sub21);
  tcase_add_test(tc, sub22);
  tcase_add_test(tc, sub23);
  tcase_add_test(tc, sub24);
  tcase_add_test(tc, mul1);
  tcase_add_test(tc, mul2);
  tcase_add_test(tc, mul3);
  tcase_add_test(tc, mul4);
  tcase_add_test(tc, flr1);
  tcase_add_test(tc, flr2);
  tcase_add_test(tc, trnct);
  tcase_add_test(tc, neg);
  tcase_add_test(tc, rnd1);
  tcase_add_test(tc, rnd2);
  tcase_add_test(tc, divzero);
  tcase_add_test(tc, div0);
  tcase_add_test(tc, div1);
  tcase_add_test(tc, div2);
  tcase_add_test(tc, div3);
  tcase_add_test(tc, div4);
  tcase_add_test(tc, divbig);
  tcase_add_test(tc, divsmol);
  tcase_add_test(tc, divround);
  tcase_add_test(tc, divbuf);
  tcase_add_test(tc, divdec);
  tcase_add_test(tc, div_zero);
  tcase_add_test(tc, div_minus);
  tcase_add_test(tc, div_over);
  tcase_add_test(tc, aux_greater1);
  tcase_add_test(tc, aux_greater2);
  tcase_add_test(tc, aux_greater3);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}