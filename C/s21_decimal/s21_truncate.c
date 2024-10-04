#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  char str[33] = {0};
  unsigned_decimal temp = {{0, 0, 0}, 0};
  converter(value, &temp);
  from_unsigned_to_string(temp, str);
  delete_fractial(str);
  temp = from_string_to_unsigned(str);
  vice_versa(temp, result);
  return flag;
}
