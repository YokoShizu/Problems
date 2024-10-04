#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int flag = 0;
  if (value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0) {
    int f = value_2.bits[3] << 1 >> 17;
    int s = value_2.bits[3] >> 31;
    result->bits[3] = ((1 - s) << 31) + (f << 16);
    for (int j = 0; j < 3; ++j) result->bits[j] = value_2.bits[j];
  } else if (value_2.bits[0] == 0 && value_2.bits[1] == 0 &&
             value_2.bits[2] == 0) {
    for (int j = 0; j < 4; ++j) result->bits[j] = value_1.bits[j];
  } else {
    unsigned_decimal val_1, val_2, res = {{0, 0, 0}, 0};
    converter(value_1, &val_1);
    converter(value_2, &val_2);
    delete_useless_zeros(&val_1);
    delete_useless_zeros(&val_2);
    int frac_1 = val_1.sign << 1 >> 17;
    int frac_2 = val_2.sign << 1 >> 17;
    int sign_1 = val_1.sign >> 31;
    int sign_2 = val_2.sign >> 31;
    if (sign_1 != sign_2) {
      unsigned_decimal temp = val_2;
      temp.sign ^= 1 << 31;
      char str_1[60] = {0}, str_2[60] = {0};
      from_unsigned_to_string(val_1, str_1);
      from_unsigned_to_string(temp, str_2);
      flag = add_aux(str_1, sign_1, frac_1, str_2, frac_2, &res);
    } else {
      char str_1[60] = {0}, str_2[60] = {0};
      from_unsigned_to_string(val_1, str_1);
      from_unsigned_to_string(val_2, str_2);
      int len_1 = (length(str_1) > 0 ? length(str_1) : 1) - sign_1 -
                  (frac_1 > 0) - frac_1;
      int len_2 = (length(str_2) > 0 ? length(str_2) : 1) - sign_2 -
                  (frac_2 > 0) - frac_2;
      int frac = frac_1 > frac_2 ? frac_1 : frac_2;
      int total = (len_1 > len_2 ? len_1 : len_2) + frac;
      if (total > 29) {
        sub_aux(str_1, sign_1, frac_1, str_2, frac_2, &res);
      } else
        flag = sub_simple(value_1, value_2, val_1, sign_1, frac_1, val_2,
                          frac_2, &res);
    }
    if (!flag) vice_versa(res, result);
  }
  return flag;
}

int sub_simple(s21_decimal value_1, s21_decimal value_2, unsigned_decimal val_1,
               int sign, int frac_1, unsigned_decimal val_2, int frac_2,
               unsigned_decimal *result) {
  int flag = 0;
  int frac = frac_1 > frac_2 ? frac_1 : frac_2;
  if (frac_1 > frac_2)
    equalization(&val_2, frac_1 - frac_2);
  else if (frac_1 < frac_2)
    equalization(&val_1, frac_2 - frac_1);
  int which_one = s21_is_greater_or_equal(value_1, value_2);
  result->sign = ((1 - which_one) << 31) + (frac << 16);
  if ((which_one && !sign) || (!which_one && sign)) {
    result->bits[2] = val_1.bits[2] - val_2.bits[2];
    middle_bits_sub(val_1, val_2, result);
  } else {
    result->bits[2] = val_2.bits[2] - val_1.bits[2];
    middle_bits_sub(val_2, val_1, result);
  }
  char str[33] = {0};
  from_unsigned_to_string(val_2, str);
  return flag;
}

void middle_bits_sub(unsigned_decimal value_1, unsigned_decimal value_2,
                     unsigned_decimal *result) {
  if (value_1.bits[1] >= value_2.bits[1]) {
    result->bits[1] = value_1.bits[1] - value_2.bits[1];
    low_bits_sub(value_1, value_2, result);
  } else {
    --(result->bits[2]);
    result->bits[1] = UMAX - (value_2.bits[1] - 1 - value_1.bits[1]);
    low_bits_sub(value_1, value_2, result);
  }
}

void low_bits_sub(unsigned_decimal value_1, unsigned_decimal value_2,
                  unsigned_decimal *result) {
  if (value_1.bits[0] >= value_2.bits[0]) {
    result->bits[0] = value_1.bits[0] - value_2.bits[0];
  } else if (value_1.bits[0] < value_2.bits[0] && result->bits[1] > 0) {
    --(result->bits[1]);
    result->bits[0] = UMAX - (value_2.bits[0] - 1 - value_1.bits[0]);
  } else {
    --(result->bits[2]);
    result->bits[1] = UMAX;
    result->bits[0] = UMAX - (value_2.bits[0] - 1 - value_1.bits[0]);
  }
}

void sub_aux(char *str_1, int sign, int frac_1, char *str_2, int frac_2,
             unsigned_decimal *result) {
  aux aux_val_1 = from_string_to_aux(str_1);
  aux aux_val_2 = from_string_to_aux(str_2);
  aux sub = {{0, 0, 0, 0, 0, 0}, 0};
  int frac = frac_1 > frac_2 ? frac_1 : frac_2;
  frac_1 = aux_val_1.sign << 1 >> 17;
  frac_2 = aux_val_2.sign << 1 >> 17;
  frac = frac_1 > frac_2 ? frac_1 : frac_2;
  if (frac_1 > frac_2)
    aux_equalization(&aux_val_2, frac_1 - frac_2);
  else if (frac_1 < frac_2)
    aux_equalization(&aux_val_1, frac_2 - frac_1);
  char str1[60] = {0}, str2[60] = {0};
  from_aux_to_string(aux_val_1, str1);
  from_aux_to_string(aux_val_2, str2);
  int which_one = aux_is_greater_or_equal(aux_val_1, aux_val_2);
  sub.sign = ((1 - which_one) << 31) + (frac << 16);
  if ((which_one && !sign) || (!which_one && sign)) {
    sub.bits[5] = aux_val_1.bits[5] - aux_val_2.bits[5];
    aux_bits_4_sub(aux_val_1, aux_val_2, &sub);
  } else {
    sub.bits[5] = aux_val_2.bits[5] - aux_val_1.bits[5];
    aux_bits_4_sub(aux_val_2, aux_val_1, &sub);
  }
  char str[60] = {0};
  from_aux_to_string(sub, str);
  delete_zeroes_string(str);
  int quantity_of_digits = length(str) - (sub.sign < 0) - (frac > 0);
  int len = (quantity_of_digits - frac < 29 ? quantity_of_digits - frac : 29);
  bank_rounding(str, frac, 29 - len);
  delete_zeroes_string(str);
  *result = from_string_to_unsigned(str);
}

void aux_bits_4_sub(aux value_1, aux value_2, aux *result) {
  result->bits[4] = value_1.bits[4] - value_2.bits[4];
  aux_bits_3_sub(value_1, value_2, result);
}

void aux_bits_3_sub(aux value_1, aux value_2, aux *result) {
  result->bits[3] = value_1.bits[3] - value_2.bits[3];
  aux_bits_2_sub(value_1, value_2, result);
}

void aux_bits_2_sub(aux value_1, aux value_2, aux *result) {
  if (value_1.bits[2] >= value_2.bits[2]) {
    result->bits[2] = value_1.bits[2] - value_2.bits[2];
    aux_bits_1_sub(value_1, value_2, result);
  } else {
    --(result->bits[3]);
    result->bits[2] = UMAX - (value_2.bits[2] - 1 - value_1.bits[2]);
    aux_bits_1_sub(value_1, value_2, result);
  }
}

void aux_bits_1_sub(aux value_1, aux value_2, aux *result) {
  if (value_1.bits[1] >= value_2.bits[1]) {
    result->bits[1] = value_1.bits[1] - value_2.bits[1];
    aux_bits_0_sub(value_1, value_2, result);
  } else if (value_1.bits[1] < value_2.bits[1] && result->bits[2] > 0) {
    --(result->bits[2]);
    result->bits[1] = UMAX - (value_2.bits[1] - 1 - value_1.bits[1]);
    ;
    aux_bits_0_sub(value_1, value_2, result);
  } else if (value_1.bits[1] < value_2.bits[1] && result->bits[2] == 0 &&
             result->bits[3] > 0) {
    --(result->bits[3]);
    result->bits[2] = UMAX;
    result->bits[1] = UMAX - (value_2.bits[1] - 1 - value_1.bits[1]);
    aux_bits_0_sub(value_1, value_2, result);
  }
}

void aux_bits_0_sub(aux value_1, aux value_2, aux *result) {
  if (value_1.bits[0] >= value_2.bits[0]) {
    result->bits[0] = value_1.bits[0] - value_2.bits[0];
  } else if (value_1.bits[0] < value_2.bits[0] && result->bits[1] > 0) {
    --(result->bits[1]);
    result->bits[0] = UMAX - (value_2.bits[0] - 1 - value_1.bits[0]);
  } else if (value_1.bits[0] < value_2.bits[0] && result->bits[1] == 0 &&
             result->bits[2] > 0) {
    --(result->bits[2]);
    result->bits[1] = UMAX;
    result->bits[0] = UMAX - (value_2.bits[0] - 1 - value_1.bits[0]);
  } else if (value_1.bits[0] < value_2.bits[0] && result->bits[1] == 0 &&
             result->bits[2] == 0 && result->bits[3] > 0) {
    --(result->bits[3]);
    result->bits[2] = result->bits[1] = UMAX;
    result->bits[0] = UMAX - (value_2.bits[0] - 1 - value_1.bits[0]);
  }
}