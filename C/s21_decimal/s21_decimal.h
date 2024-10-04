#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef s21_DECIMAL_H
#define s21_DECIMAL_H

#define ULLMAX 18446744073709551615ULL
#define ULMAX 4294967295ULL
#define UMAX 4294967295U
#define DIGIT_MAX160 49
#define DIGIT_MAX128 39
#define DIGIT_MAX96 29
#define DIGIT_MAX64 20
#define DIGIT_MAX32 10
#define SHIFT 2147483648LL
#define POWER 65536

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  unsigned bits[3];
  int sign;
} unsigned_decimal;

typedef struct {
  unsigned bits[6];
  int sign;
} aux;

// Convertors and parsers

int s21_from_int_to_decimal(int src, s21_decimal *dst);      //	+
int s21_from_decimal_to_int(s21_decimal src, int *dst);      //	+
int s21_from_float_to_decimal(float src, s21_decimal *dst);  //  +
int s21_from_decimal_to_float(s21_decimal src, float *dst);  //  +

// Comparison operators

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);      //	+
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);  //	+
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);    //	+
int s21_is_greater_or_equal(s21_decimal value_1,
                            s21_decimal value_2);                    //	+
int s21_is_less(s21_decimal value_1, s21_decimal value_2);           //	+
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);  //	+

// Arithmetic operators

int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  //	+
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  //	+
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  //  +
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result);  //  +

// Other functions

int s21_floor(s21_decimal value, s21_decimal *result);     //	+
int s21_round(s21_decimal value, s21_decimal *result);     //	+
int s21_truncate(s21_decimal value, s21_decimal *result);  //	+
int s21_negate(s21_decimal value, s21_decimal *result);    //	+

// Auxiliary

void converter(s21_decimal value, unsigned_decimal *val);
void vice_versa(unsigned_decimal val, s21_decimal *value);

void equalization(unsigned_decimal *value_ptr, int frac_difference);
void aux_equalization(aux *value, int frac_difference);

void from_unsigned_to_string(unsigned_decimal value, char *str);
unsigned_decimal from_string_to_unsigned(char *source);
void from_aux_to_string(aux value, char *str);
aux from_string_to_aux(char *source);
void from_exp_to_string(char *str);
int get_precision(float value);
int get_bit_from_dec(unsigned_decimal src, int i);
double pow_of_two(int pow);

void get_digit_of_string(char *str, int len, int *i, unsigned_decimal *num,
                         int part, int sign);
void get_digit_of_string_aux(char *str, int len, int *i, aux *value, int part,
                             int sign);

void delete_dot(char *str, int dec_len, int dot_pos);

int digit(unsigned num, int place);

int count_digits_in_bits(unsigned num);
void reverse_string(char *str, int len);
void delete_fractial(char *str);

unsigned long long power(int n, int p);
float pow_of_ten(int pwr);

void delete_useless_zeros(unsigned_decimal *value);
int zeros_quantity(char *str);
int count_non_zero(char *str);
void delete_zeroes_string(char *str);
int length(char *str);
int count_digits(aux value);
unsigned_decimal get_fractial(char *str, int frac);

void bank_rounding(char *str, int frac, int num);
void round_to_float(char *str);

int sub_simple(s21_decimal value_1, s21_decimal value_2, unsigned_decimal val_1,
               int sign, int frac_1, unsigned_decimal val_2, int frac_2,
               unsigned_decimal *result);
void middle_bits_sub(unsigned_decimal value_1, unsigned_decimal value_2,
                     unsigned_decimal *result);
void low_bits_sub(unsigned_decimal value_1, unsigned_decimal value_2,
                  unsigned_decimal *result);
void sub_aux(char *str_1, int sign, int frac_1, char *str_2, int frac_2,
             unsigned_decimal *result);
void aux_bits_4_sub(aux value_1, aux value_2, aux *result);
void aux_bits_3_sub(aux value_1, aux value_2, aux *result);
void aux_bits_2_sub(aux value_1, aux value_2, aux *result);
void aux_bits_1_sub(aux value_1, aux value_2, aux *result);
void aux_bits_0_sub(aux value_1, aux value_2, aux *result);
int aux_is_greater_or_equal(aux value_1, aux value_2);

int add_aux(char *str_1, int sign, int frac_1, char *str_2, int frac_2,
            unsigned_decimal *result);
void numbers_for_add_struct(aux aux_val_1, aux aux_val_2, aux *add, int sign,
                            int frac);

void mul_simple(unsigned_decimal val_1, unsigned_decimal val_2,
                unsigned long long *bits_0, unsigned long long *bits_1,
                unsigned long long *bits_2, unsigned long long *bits_3,
                unsigned long long *bits_4);
void strLEFTshift(char *str);

#endif