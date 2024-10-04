#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (value.bits[3] >= 0)
    s21_truncate(value, result);
  else if (value.bits[3] < 0) {
    s21_truncate(value, result);
    ++result->bits[0];
  }
  return flag;
}
