#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int flag = 0, frac = 0, i = 0;
  for (int j = 0; j < 4; ++j) dst->bits[j] = 0;
  char str[120] = {0};
  int precision = get_precision(src);
  if (precision > 32)
    flag = 1;
  else {
    if (precision >= 0) {
      sprintf(str, "%.*f", precision, src);
    } else
      sprintf(str, "%.7g", src);
    int len = length(str) > 0 ? length(str) : 1;
    str[len] = '\0';
    from_exp_to_string(str);
    len = length(str) > 0 ? length(str) : 1;
    while (str[i] != '\0') {
      ++i;
      if (str[len - i] == '.') {
        frac = 1;
        break;
      }
    }
    if (frac == 1 && i > 28) {
      flag = 1;
      return 1;
    } else {
      aux con = from_string_to_aux(str);
      if (con.bits[3] != 0 || con.bits[4] != 0 || con.bits[5] != 0)
        flag = 1;
      else {
        unsigned_decimal res = from_string_to_unsigned(str);
        vice_versa(res, dst);
      }
    }
  }
  return flag;
}

void from_exp_to_string(char *str) {
  int i = 0, flag_dot = 0, frac = 0, flag_exp = 0, flag_minus = 0, power = 0,
      e_index = 0, sign = 0;
  int len = length(str);
  if (str[0] == '-') sign = 1;
  while (str[i] != '\0') {
    if (flag_exp == 1) {
      if (str[i] == '-') flag_minus = 1;
      ++i;
      break;
    }
    if (flag_dot == 1) ++frac;
    if (str[i] == '.') flag_dot = 1;
    if (str[i] == 'e') {
      flag_exp = 1;
      e_index = i;
    }
    ++i;
  }
  while (str[i] != '\0') {
    power *= 10;
    power += str[i] - '0';
    ++i;
  }
  if (flag_minus == 0) power -= frac;
  if (flag_exp == 1) {
    delete_dot(str, i, 1 + sign);
    if (flag_minus == 0) {
      for (i = 0; i <= power; ++i) str[e_index - 1 + i] = '0';
    }
    for (i = power + 1; i <= len; ++i) str[e_index - 1 + i] = '\0';
  }
}

int get_precision(float value) {
  int prec = 0, len = 0;
  if (value < 0.0f) value *= -1;
  double val = (double)value;
  if (val < 1000000000.0f) {
    while (val < 1.0) {
      val *= 10.0f;
      ++prec;
    }
    val += 1.0f / pow_of_ten(7);
    float diff = val - (int)val;
    while (1) {
      if (diff <= 0.1f || len == 6) break;
      val *= 10.0f;
      diff = val - (int)val;
      ++len;
    }
  } else
    len = -1;
  return prec + len > 45 ? 45 : prec + len;
}