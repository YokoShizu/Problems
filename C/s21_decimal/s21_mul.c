#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;
  unsigned_decimal val_1, val_2, res;
  converter(value_1, &val_1);
  converter(value_2, &val_2);
  delete_useless_zeros(&val_1);
  delete_useless_zeros(&val_2);
  aux mul = {{0, 0, 0, 0, 0, 0}, 0};
  int sign = (val_1.sign < 0) ^ (val_2.sign < 0);
  int frac = (val_1.sign << 1 >> 17) + (val_2.sign << 1 >> 17);
  mul.sign = (sign << 31) + (frac << 16);
  unsigned long long bits_0, bits_1, bits_2, bits_3, bits_4;
  mul_simple(val_1, val_2, &bits_0, &bits_1, &bits_2, &bits_3, &bits_4);
  mul.bits[0] = bits_0 % (ULMAX + 1);
  mul.bits[1] = bits_1 % (ULMAX + 1);
  mul.bits[2] = bits_2 % (ULMAX + 1);
  mul.bits[3] = bits_3 % (ULMAX + 1);
  mul.bits[4] = bits_4 % (ULMAX + 1);
  mul.bits[5] = bits_4 / (ULMAX + 1);
  mul.sign = (sign << 31) + (frac << 16);
  char str[60] = {0};
  from_aux_to_string(mul, str);
  delete_zeroes_string(str);
  int quantity_of_digits = length(str) > 0 ? length(str) : 1;
  quantity_of_digits = quantity_of_digits - sign - (frac > 0);
  int len = (quantity_of_digits - frac < 29 ? quantity_of_digits - frac : 29);
  bank_rounding(str, frac, 29 - len);
  delete_zeroes_string(str);
  mul = from_string_to_aux(str);
  if (sign == 0 && (mul.bits[3] || mul.bits[4] || mul.bits[5]))
    flag = 1;
  else if (sign == 1 && (mul.bits[3] || mul.bits[4] || mul.bits[5]))
    flag = 2;
  if (!flag) {
    res = from_string_to_unsigned(str);
    vice_versa(res, result);
  }
  return flag;
}

void mul_simple(unsigned_decimal val_1, unsigned_decimal val_2,
                unsigned long long *bits_0, unsigned long long *bits_1,
                unsigned long long *bits_2, unsigned long long *bits_3,
                unsigned long long *bits_4) {
  *bits_4 =
      (unsigned long long)val_1.bits[2] * (unsigned long long)val_2.bits[2];
  unsigned long long bits_3_part_1 =
      (unsigned long long)val_1.bits[2] * (unsigned long long)val_2.bits[1];
  *bits_4 += bits_3_part_1 / (ULMAX + 1);
  bits_3_part_1 %= (ULMAX + 1);
  unsigned long long bits_3_part_2 =
      (unsigned long long)val_1.bits[1] * (unsigned long long)val_2.bits[2];
  *bits_4 += bits_3_part_2 / (ULMAX + 1);
  bits_3_part_2 %= (ULMAX + 1);
  *bits_3 = bits_3_part_1 + bits_3_part_2;
  unsigned long long bits_2_part_1 =
      (unsigned long long)val_1.bits[2] * (unsigned long long)val_2.bits[0];
  *bits_3 += bits_2_part_1 / (ULMAX + 1);
  bits_2_part_1 %= (ULMAX + 1);
  unsigned long long bits_2_part_2 =
      (unsigned long long)val_1.bits[1] * (unsigned long long)val_2.bits[1];
  *bits_3 += bits_2_part_2 / (ULMAX + 1);
  bits_2_part_2 %= (ULMAX + 1);
  unsigned long long bits_2_part_3 =
      (unsigned long long)val_1.bits[0] * (unsigned long long)val_2.bits[2];
  *bits_3 += bits_2_part_3 / (ULMAX + 1);
  bits_2_part_3 %= (ULMAX + 1);
  *bits_2 = bits_2_part_1 + bits_2_part_2 + bits_2_part_3;
  *bits_3 += *bits_2 / (ULMAX + 1);
  *bits_2 %= (ULMAX + 1);
  *bits_4 += *bits_3 / (ULMAX + 1);
  *bits_3 %= (ULMAX + 1);
  unsigned long long bits_1_part_1 =
      (unsigned long long)val_1.bits[1] * (unsigned long long)val_2.bits[0];
  *bits_2 += bits_1_part_1 / (ULMAX + 1);
  bits_1_part_1 %= (ULMAX + 1);
  unsigned long long bits_1_part_2 =
      (unsigned long long)val_1.bits[0] * (unsigned long long)val_2.bits[1];
  *bits_2 += bits_1_part_2 / (ULMAX + 1);
  bits_1_part_2 %= (ULMAX + 1);
  *bits_1 = bits_1_part_1 + bits_1_part_2;
  *bits_2 += *bits_1 / (ULMAX + 1);
  *bits_1 %= (ULMAX + 1);
  *bits_3 += *bits_2 / (ULMAX + 1);
  *bits_2 %= (ULMAX + 1);
  *bits_4 += *bits_3 / (ULMAX + 1);
  *bits_3 %= (ULMAX + 1);
  *bits_0 =
      (unsigned long long)val_1.bits[0] * (unsigned long long)val_2.bits[0];
  *bits_1 += *bits_0 / (ULMAX + 1);
  *bits_0 %= (ULMAX + 1);
  *bits_2 += *bits_1 / (ULMAX + 1);
  *bits_1 %= (ULMAX + 1);
  *bits_3 += *bits_2 / (ULMAX + 1);
  *bits_2 %= (ULMAX + 1);
  *bits_4 += *bits_3 / (ULMAX + 1);
  *bits_3 %= (ULMAX + 1);
}