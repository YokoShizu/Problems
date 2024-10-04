#include "s21_decimal.h"

void bank_rounding(char *str, int frac, int num) {
  int len = length(str) > 0 ? length(str) : 1;
  int sign = 0, j = 0, dot = 0;
  sign = (str[0] == '-' ? 1 : 0);
  if ((len - frac - sign - (frac > 0) < 29) + (frac > 0)) {
    if (num == 0) dot = 1;
    int index = len - 1 - frac + num - dot;
    if ((str[index + 1 + dot] == '5' && str[index + 2 + dot] != '\0') ||
        str[index + 1 + dot] >= '6' ||
        ((str[index] - '0') % 2 && str[index + 1 + dot] >= '5' &&
         str[index + 1 + dot] <= '9')) {
      while (str[index - j + 1 + dot] == '9' &&
             str[index - j + 1 + dot] != '.') {
        str[index - j + 1 + dot] = '0';
        ++j;
        if (str[index - j + 1 + dot] == '.') ++j;
      }
      if (j) j -= 1 + dot;
      if (str[index - j] == '9') {
        while (str[index - j] == '9') {
          str[index - j] = '0';
          ++j;
        }
        ++str[index - j];
      } else
        ++str[index - j];
    }
    int len = length(str) > 0 ? length(str) : 1;
    if (index - j)
      for (int i = len; i > index; --i) str[i] = '\0';
  }
}

void converter(s21_decimal value, unsigned_decimal *val) {
  val->sign = (int)value.bits[3];
  val->bits[0] = (int)value.bits[0];
  val->bits[1] = (int)value.bits[1];
  val->bits[2] = (int)value.bits[2];
}

void vice_versa(unsigned_decimal val, s21_decimal *value) {
  value->bits[3] = (unsigned)val.sign;
  value->bits[0] = (unsigned)val.bits[0];
  value->bits[1] = (unsigned)val.bits[1];
  value->bits[2] = (unsigned)val.bits[2];
}

int count_digits(aux value) {
  int frac = value.sign << 1 >> 17;
  int quantity = count_digits_in_bits(value.bits[0]);
  if (value.bits[5])
    quantity = count_digits_in_bits(value.bits[5]) + DIGIT_MAX160;
  else if (value.bits[4])
    quantity = count_digits_in_bits(value.bits[4]) + DIGIT_MAX128;
  else if (value.bits[3])
    quantity = count_digits_in_bits(value.bits[3]) + DIGIT_MAX96;
  else if (value.bits[2]) {
    quantity = count_digits_in_bits(value.bits[2]) + DIGIT_MAX64;
    quantity = quantity > DIGIT_MAX96 ? DIGIT_MAX96 : quantity;
  } else if (value.bits[1])
    quantity = count_digits_in_bits(value.bits[1]) + DIGIT_MAX32;
  quantity = quantity > frac ? quantity : frac + 1;
  return quantity;
}

void delete_dot(char *str, int len, int dot_pos) {
  for (int i = dot_pos; i < len; ++i) str[i] = str[i + 1];
}

int digit(unsigned num, int place) {
  int dgt = 0;
  if (place <= 10) {
    for (int i = 1; i < place; ++i) num /= 10;
    dgt = num % 10;
  }
  return dgt;
}

void equalization(unsigned_decimal *value, int frac_difference) {
  char str[33] = {0};
  from_unsigned_to_string(*value, str);
  int len = length(str) > 0 ? length(str) : 1;
  if ((value->sign << 1 >> 17) == 0) str[len++] = '.';
  for (int i = 0; i < frac_difference; ++i) str[len + i] = '0';
  str[len + frac_difference] = '\0';
  *value = from_string_to_unsigned(str);
}

void aux_equalization(aux *value, int frac_difference) {
  char str[65] = {0};
  from_aux_to_string(*value, str);
  int len = length(str) > 0 ? length(str) : 1;
  if ((value->sign << 1 >> 17) == 0) str[len++] = '.';
  for (int i = 0; i < frac_difference + 1; ++i) str[len + i] = '0';
  str[len + frac_difference] = '\0';
  *value = from_string_to_aux(str);
}

unsigned_decimal get_fractial(char *str, int frac) {
  char frac_str[33] = "0.";
  for (int i = 0; i < frac; ++i) {
    frac_str[i + 2] = str[strlen(str) - frac + i];
  }
  frac_str[frac + 2] = '\0';
  return from_string_to_unsigned(frac_str);
}

void from_aux_to_string(aux value, char *str) {
  int i = 0, dot = 0, product = 0, remainder = 0;
  char max_32[] = "69276949240000000000000000000000000000000000000000000000000";
  char max_64[] = "61615590737044764481000000000000000000000000000000000000000";
  char max_96[] = "63305934539573346241526182297000000000000000000000000000000";
  char max_128[] =
      "65411286713470647336436483902966328204300000000000000000000";
  char max_160[] =
      "67924523955691038261723848630281920903373610516410000000000";
  int sign = (value.sign < 0);
  int frac = value.sign << 1 >> 17;
  int quantity_of_digits = count_digits(value);
  do {
    if (i == frac && frac > 0) {
      str[i] = '.';
      dot = 1;
    }
    for (int j = 1; j <= (i == quantity_of_digits - 1 ? i : i + 1); ++j)
      product += digit(value.bits[5], j) * (max_160[i + 1 - j] - '0') +
                 digit(value.bits[4], j) * (max_128[i + 1 - j] - '0') +
                 digit(value.bits[3], j) * (max_96[i + 1 - j] - '0') +
                 digit(value.bits[2], j) * (max_64[i + 1 - j] - '0') +
                 digit(value.bits[1], j) * (max_32[i + 1 - j] - '0');
    remainder += product % 10 + digit(value.bits[0], i + 1);
    str[dot + i++] = remainder % 10 + '0';
    remainder /= 10;
    product /= 10;
  } while (i < quantity_of_digits);
  if (str[i + dot] == '0' && str[i + dot - 1] != '.')
    --i;
  else if (str[i + dot - 1] == '0' && str[i + dot - 2] != '.')
    --i;
  if (sign) str[i + dot] = '-';
  reverse_string(str, i + dot + sign);
  str[i + dot + sign] = '\0';
}

unsigned_decimal from_string_to_unsigned(char *source) {  // string to decimal
  unsigned_decimal value = {{0, 0, 0}, 0};
  char auxil_str[33] = {0};
  int len = length(source) > 0 ? length(source) : 1;
  int bits = 0, i = 0, sign = 0, dot_pos = 0;
  if (source[0] == '-') {
    value.sign |= (1 << 31);
    sign = 1;
  }
  for (int k = 0; k < len; ++k) auxil_str[k] = source[k];
  auxil_str[len] = '\0';
  for (int j = 0; j < len; ++j)
    if (auxil_str[j] == '.') {
      dot_pos = j;
      value.sign |= (len - dot_pos - 1) << 16;
      delete_dot(auxil_str, len, dot_pos);
      --len;
      break;
    }
  while (i + sign < len) {
    while (auxil_str[i + sign] - '0') {
      if (bits >= 64 && bits < 96)
        get_digit_of_string(auxil_str, len, &bits, &value, 2, sign);
      else if (bits >= 32 && bits < 64)
        get_digit_of_string(auxil_str, len, &bits, &value, 1, sign);
      else
        get_digit_of_string(auxil_str, len, &bits, &value, 0, sign);
    }
    ++i;
  }
  return value;
}

void from_unsigned_to_string(unsigned_decimal value, char *str) {
  int i = 0, dot = 0, product = 0, remainder = 0;
  int sign = (value.sign < 0);
  int frac = (value.sign << 1) >> 17;
  char max_32[] = "69276949240000000000000000000";
  char max_64[] = "61615590737044764481000000000";
  int quantity_of_digits = count_digits_in_bits(value.bits[0]);
  if (value.bits[2])
    quantity_of_digits = count_digits_in_bits(value.bits[2]) + DIGIT_MAX64;
  else if (value.bits[1])
    quantity_of_digits = count_digits_in_bits(value.bits[1]) + DIGIT_MAX32;
  quantity_of_digits =
      quantity_of_digits > DIGIT_MAX96 ? DIGIT_MAX96 : quantity_of_digits;
  quantity_of_digits =
      quantity_of_digits > frac ? quantity_of_digits : frac + 1;
  do {
    if (i == frac && frac > 0) {
      str[i] = '.';
      dot = 1;
    }
    for (int j = 1; j <= (i == quantity_of_digits - 1 ? i : i + 1); ++j)
      product += digit(value.bits[2], j) * (max_64[i + 1 - j] - '0') +
                 digit(value.bits[1], j) * (max_32[i + 1 - j] - '0');
    remainder += product % 10 + digit(value.bits[0], i + 1);
    str[dot + i++] = remainder % 10 + '0';
    remainder /= 10;
    product /= 10;
  } while (i < quantity_of_digits);
  if (str[i + dot] == '0' && str[i + dot - 1] != '.')
    --i;
  else if (str[i + dot - 1] == '0' && str[i + dot - 2] != '.')
    --i;
  if (sign) str[i + dot] = '-';
  reverse_string(str, i + dot + sign);
  str[i + dot + sign] = '\0';
}

aux from_string_to_aux(char *source) {  // string to decimal
  aux value = {{0, 0, 0, 0, 0, 0}, 0};
  char auxil_str[60] = {0};
  int len = length(source) > 0 ? length(source) : 1;
  int bits = 0, sign = 0, dot_pos = 0;
  if (source[0] == '-') {
    value.sign |= (1 << 31);
    sign = 1;
  }
  int i = sign;
  for (int k = 0; k < len; ++k) auxil_str[k] = source[k];
  auxil_str[len] = '\0';
  for (int j = 0; j < len; ++j)
    if (auxil_str[j] == '.') {
      dot_pos = j;
      value.sign |= (len - dot_pos - 1) << 16;
      delete_dot(auxil_str, len, dot_pos);
      --len;
      break;
    }
  while (i < len) {
    while (auxil_str[i] - '0') {
      if (bits >= 160 && bits < 192)
        get_digit_of_string_aux(auxil_str, len, &bits, &value, 5, sign);
      else if (bits >= 128 && bits < 160)
        get_digit_of_string_aux(auxil_str, len, &bits, &value, 4, sign);
      else if (bits >= 96 && bits < 128)
        get_digit_of_string_aux(auxil_str, len, &bits, &value, 3, sign);
      else if (bits >= 64 && bits < 96)
        get_digit_of_string_aux(auxil_str, len, &bits, &value, 2, sign);
      else if (bits >= 32 && bits < 64)
        get_digit_of_string_aux(auxil_str, len, &bits, &value, 1, sign);
      else
        get_digit_of_string_aux(auxil_str, len, &bits, &value, 0, sign);
    }
    ++i;
  }
  return value;
}

void get_digit_of_string(char *str, int len, int *i, unsigned_decimal *value,
                         int part, int sign) {
  value->bits[part] |= ((str[len - 1] - '0') & 1) << (*i - part * 32);
  ++(*i);
  for (int j = 1 + sign; j <= len; ++j) {
    if (j < len) str[j] += (str[j - 1] - '0') % 2 * 10;
    str[j - 1] = ((str[j - 1] - '0') >> 1) + '0';
  }
}

void get_digit_of_string_aux(char *str, int len, int *i, aux *value, int part,
                             int sign) {
  value->bits[part] |= ((str[len - 1] - '0') & 1) << (*i - part * 32);
  ++(*i);
  for (int j = 1 + sign; j <= len; ++j) {
    if (j < len) str[j] += (str[j - 1] - '0') % 2 * 10;
    str[j - 1] = ((str[j - 1] - '0') >> 1) + '0';
  }
}

int count_digits_in_bits(unsigned num) {
  int quantity = 0;
  while (num) {
    ++quantity;
    num /= 10;
  }
  return quantity;
}

void reverse_string(char *str, int length) {
  for (int i = 0; i < length / 2; ++i) {
    str[i] += str[length - i - 1];
    str[length - i - 1] = str[i] - str[length - i - 1];
    str[i] -= str[length - i - 1];
  }
}

void delete_zeroes_string(char *str) {
  int i = length(str) > 0 ? length(str) - 1 : 1;
  int dot_flag = 0;
  while (i > 0) {
    if (str[i] == '.') {
      dot_flag = 1;
      break;
    }
    --i;
  }
  i = length(str) - 1;
  if (dot_flag == 1) {
    while (str[i] == '0') {
      str[i] = '\0';
      --i;
    }
  }
  if (str[i] == '.') str[i] = '\0';
}

void delete_useless_zeros(unsigned_decimal *value) {
  char str[60] = {0};
  from_unsigned_to_string(*value, str);
  delete_zeroes_string(str);
  *value = from_string_to_unsigned(str);
}

int length(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    ++i;
  }
  return i;
}

float pow_of_ten(int pwr) {
  float res = 1.0f;
  if (pwr < 0) {
    pwr *= -1.0;
    for (int i = 0; i < pwr; ++i) res /= 10.0f;
  } else if (pwr > 0) {
    for (int i = 0; i < pwr; ++i) res *= 10.0;
  }
  return res;
}

int count_non_zero(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == '0') break;
    ++i;
  }
  return i;
}