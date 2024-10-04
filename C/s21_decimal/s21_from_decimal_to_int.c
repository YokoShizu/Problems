#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  char str[31] = {0};
  unsigned_decimal val = {{0, 0, 0}, 0};
  converter(src, &val);
  unsigned long long temp = 0;
  long long tmp = 0;
  from_unsigned_to_string(val, str);
  if ((val.sign << 1) >> 17) delete_fractial(str);
  int len = strlen(str);
  if (len <= 11) {
    for (int i = 0; i < len; ++i) {
      if (str[i] > 47 && str[i] < 58) temp = temp * 10 + (str[i] - '0');
      tmp = (long long)temp;
      if (tmp < -SHIFT || tmp > SHIFT) {
        flag = 1;
        break;
      }
    }
  } else {
    flag = 1;
  }
  *dst = (int)temp;
  if (src.bits[3] < 0) {
    *dst *= -1;
  }
  return flag;
}

void delete_fractial(char *str) {
  int i = strlen(str);
  do {
    *(str + i) = '\0';
    --i;
  } while (*(str + i) != '.');
  *(str + i) = '\0';
}