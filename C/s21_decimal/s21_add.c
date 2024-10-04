#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;
  int sign_1 = value_1.bits[3] >> 31;
  int sign_2 = value_2.bits[3] >> 31;
  int frac_1 = value_1.bits[3] << 1 >> 17;
  int frac_2 = value_2.bits[3] << 1 >> 17;
  unsigned_decimal val_1, val_2, res;
  converter(value_1, &val_1), converter(value_2, &val_2);
  delete_useless_zeros(&val_1), delete_useless_zeros(&val_2);
  if (sign_1 != sign_2) {
    unsigned_decimal temp = val_2;
    temp.sign ^= 1 << 31;
    flag =
        sub_simple(value_1, value_2, val_1, sign_1, frac_1, temp, frac_2, &res);
  } else {
    char str_1[60] = {0}, str_2[60] = {0};
    from_unsigned_to_string(val_1, str_1);
    from_unsigned_to_string(val_2, str_2);
    flag = add_aux(str_1, sign_1, frac_1, str_2, frac_2, &res);
  }
  vice_versa(res, result);
  return flag;
}

int add_aux(char *str_1, int sign, int frac_1, char *str_2, int frac_2,
            unsigned_decimal *result) {
  int flag = 0;
  aux aux_val_1 = from_string_to_aux(str_1);
  aux aux_val_2 = from_string_to_aux(str_2);
  aux add = {{0, 0, 0, 0, 0, 0}, 0};
  frac_1 = aux_val_1.sign << 1 >> 17;
  frac_2 = aux_val_2.sign << 1 >> 17;
  int frac = frac_1 > frac_2 ? frac_1 : frac_2;
  if (frac_1 > frac_2)
    aux_equalization(&aux_val_2, frac_1 - frac_2);
  else if (frac_1 < frac_2)
    aux_equalization(&aux_val_1, frac_2 - frac_1);
  numbers_for_add_struct(aux_val_1, aux_val_2, &add, sign, frac);
  char str[60] = {0};
  from_aux_to_string(add, str);
  delete_zeroes_string(str);
  sign = sign < 0 ? 1 : 0;
  int quantity_of_digits = length(str) - sign - (frac > 0);
  int len = (quantity_of_digits - frac < 29 ? quantity_of_digits - frac : 29);
  bank_rounding(str, frac, 29 - len);
  delete_zeroes_string(str);
  add = from_string_to_aux(str);
  if (sign == 0 && (add.bits[3] || add.bits[4] || add.bits[5]))
    flag = 1;
  else if (sign == 1 && (add.bits[3] || add.bits[4] || add.bits[5]))
    flag = 2;
  result->sign = add.sign;
  for (int i = 0; i < 3; ++i) result->bits[i] = add.bits[i];
  return flag;
}

void numbers_for_add_struct(aux aux_val_1, aux aux_val_2, aux *add, int sign,
                            int frac) {
  unsigned long long bits_0 = (unsigned long long)aux_val_1.bits[0] +
                              (unsigned long long)aux_val_2.bits[0];
  unsigned long long bits_1 = (unsigned long long)aux_val_1.bits[1] +
                              (unsigned long long)aux_val_2.bits[1];
  unsigned long long bits_2 = (unsigned long long)aux_val_1.bits[2] +
                              (unsigned long long)aux_val_2.bits[2];
  unsigned long long bits_3 = (unsigned long long)aux_val_1.bits[3] +
                              (unsigned long long)aux_val_2.bits[3];
  unsigned long long bits_4 = (unsigned long long)aux_val_1.bits[4] +
                              (unsigned long long)aux_val_2.bits[4];
  unsigned long long bits_5 = (unsigned long long)aux_val_1.bits[5] +
                              (unsigned long long)aux_val_2.bits[5];
  add->bits[0] = bits_0 % (ULMAX + 1);
  bits_1 += bits_0 / (ULMAX + 1);
  add->bits[1] = bits_1 % (ULMAX + 1);
  bits_2 += bits_1 / (ULMAX + 1);
  add->bits[2] = bits_2 % (ULMAX + 1);
  bits_3 += bits_2 / (ULMAX + 1);
  add->bits[3] = bits_3 % (ULMAX + 1);
  bits_4 += bits_3 / (ULMAX + 1);
  add->bits[4] = bits_4 % (ULMAX + 1);
  bits_5 += bits_4 / (ULMAX + 1);
  add->bits[5] = bits_5 % (ULMAX + 1);
  add->sign = (sign << 31) + (frac << 16);
}