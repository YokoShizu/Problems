#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int flag = 0, i = 5;
  int frac_1 = 0, frac_2 = 0;
  unsigned_decimal val_1 = {{0, 0, 0}, 0}, val_2 = {{0, 0, 0}, 0};
  converter(value_1, &val_1);
  converter(value_2, &val_2);
  char str_1[60] = {0}, str_2[60] = {0};
  from_unsigned_to_string(val_1, str_1);
  from_unsigned_to_string(val_2, str_2);
  aux aux_val_1 = from_string_to_aux(str_1);
  aux aux_val_2 = from_string_to_aux(str_2);
  frac_1 = (value_1.bits[3] << 1) >> 17;
  frac_2 = (value_2.bits[3] << 1) >> 17;
  if (frac_1 > frac_2)
    aux_equalization(&aux_val_2, frac_1 - frac_2);
  else if (frac_2 > frac_1)
    aux_equalization(&aux_val_1, frac_2 - frac_1);
  char a1[60] = {0}, a2[60] = {0};
  from_aux_to_string(aux_val_1, a1);
  from_aux_to_string(aux_val_2, a2);
  while (aux_val_1.bits[i] == aux_val_2.bits[i] && i > 0) {
    --i;
  }
  if (value_1.bits[3] >= 0 && value_2.bits[3] >= 0) {
    if (aux_val_1.bits[i] < aux_val_2.bits[i] ||
        (aux_val_1.bits[0] == aux_val_2.bits[0] && frac_1 > frac_2))
      flag = 1;
  } else if (value_1.bits[3] < 0 && value_2.bits[3] < 0) {
    if (aux_val_1.bits[i] > aux_val_2.bits[i] ||
        (aux_val_1.bits[0] == aux_val_2.bits[0] && frac_1 < frac_2))
      flag = 1;
  } else if (value_1.bits[3] < 0 && value_2.bits[3] >= 0) {
    flag = 1;
  }
  return flag;
}
