#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int flag = 0;
  int frac = src.bits[3] << 1 >> 17;
  if (frac > 29)
    flag = 1;
  else {
    int sign = src.bits[3] >> 31;
    unsigned_decimal val;
    converter(src, &val);
    double to_product = 0.0;
    for (int i = 0; i < 96; ++i) {
      int temp = get_bit_from_dec(val, i);
      to_product += (double)temp * pow_of_two(i);
    }
    for (int i = 0; i < frac; ++i) to_product /= 10.0;
    *dst = (float)to_product;
    if (sign) *dst *= -1;
  }
  return flag;
}

int get_bit_from_dec(unsigned_decimal src, int i) {
  int part = i / 32;
  return (src.bits[part] << (31 - i % 32) >> 31);
}

double pow_of_two(int pow) {
  double result = 1.0;
  for (int i = 0; i < pow; ++i) result *= 2.0;
  return result;
}