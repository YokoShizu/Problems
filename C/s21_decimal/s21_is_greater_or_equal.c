#include "s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return (1 - s21_is_less(value_1, value_2));
}

int aux_is_greater_or_equal(aux value_1, aux value_2) {
  int flag = 0, i = 5;
  int frac_1 = 0, frac_2 = 0;
  frac_1 = (value_1.sign << 1) >> 17;
  frac_2 = (value_2.sign << 1) >> 17;
  if (frac_1 > frac_2)
    aux_equalization(&value_2, frac_1 - frac_2);
  else if (frac_2 > frac_1)
    aux_equalization(&value_1, frac_2 - frac_1);
  char str[60] = {0};
  from_aux_to_string(value_2, str);
  while (value_1.bits[i] == value_2.bits[i] && i > 0) {
    --i;
  }
  if (value_1.sign >= 0 && value_2.sign >= 0) {
    if (value_1.bits[i] >= value_2.bits[i]) flag = 1;
  } else if (value_1.sign < 0 && value_2.sign < 0) {
    if (value_1.bits[i] <= value_2.bits[i]) flag = 1;
  } else if (value_1.sign >= 0 && value_2.sign < 0) {
    flag = 1;
  }
  return flag;
}