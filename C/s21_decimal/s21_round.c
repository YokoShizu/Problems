#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (result == NULL)
    flag = 1;
  else {
    unsigned_decimal temp = {{0, 0, 0}, 0};
    converter(value, &temp);
    int frac = temp.sign << 1 >> 17;
    char innitial_str[33] = {0};
    from_unsigned_to_string(temp, innitial_str);
    unsigned_decimal temp_frac_dec = get_fractial(innitial_str, frac);
    char s[] = "0.5";
    unsigned_decimal compare_num = from_string_to_unsigned(s);
    s21_decimal decimal_temp_frac = {{0, 0, 0, 0}},
                decimal_compare_num = {{0, 0, 0, 0}};
    vice_versa(temp_frac_dec, &decimal_temp_frac);
    vice_versa(compare_num, &decimal_compare_num);
    if (s21_is_greater_or_equal(decimal_temp_frac, decimal_compare_num)) {
      s21_truncate(value, result);
      ++result->bits[0];
    } else {
      s21_truncate(value, result);
    }
  }
  return flag;
}
