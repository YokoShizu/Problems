#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int flag = 0;
  unsigned_decimal val = {{0, 0, 0}, 0};
  if (src >= 0)
    val.bits[0] = src;
  else {
    val.sign |= (1 << 31);
    val.bits[0] = src * (-1);
  }
  vice_versa(val, dst);
  return flag;
}
