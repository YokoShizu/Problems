#include "s21_matrix.h"

#include <check.h>

START_TEST(create_unexisting) {
  matrix_t *A = NULL;
  int res = s21_create_matrix(1, 1, A);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(create_empty) {
  matrix_t A = {NULL};
  int res = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_incorrect_matrix1) {
  matrix_t A = {NULL};
  int res = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_incorrect_matrix2) {
  matrix_t A = {NULL};
  int res = s21_create_matrix(1, 0, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_incorrect_matrix3) {
  matrix_t A = {NULL};
  int res = s21_create_matrix(-1, -1, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(equal_correct) {
  matrix_t A = {NULL}, B = {NULL};

  s21_create_matrix(2, 3, &A);
  for (int i = 0; i < A.rows; ++i)
    for (int j = 0; j < A.columns; ++j) A.matrix[i][j] = i + j;

  s21_create_matrix(2, 3, &B);
  for (int i = 0; i < B.rows; ++i)
    for (int j = 0; j < B.columns; ++j) B.matrix[i][j] = i + j;

  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(not_equal1) {
  matrix_t A = {NULL}, B = {NULL};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);

  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(not_equal2) {
  matrix_t A = {NULL}, B = {NULL};

  s21_create_matrix(2, 3, &A);
  for (int i = 0; i < A.rows; ++i)
    for (int j = 0; j < A.columns; ++j) A.matrix[i][j] = j;

  s21_create_matrix(2, 3, &B);
  for (int i = 0; i < B.rows; ++i)
    for (int j = 0; j < B.columns; ++j) B.matrix[i][j] = i;

  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(not_equal_incorrectA1) {
  matrix_t A = {NULL}, B = {NULL};

  s21_create_matrix(0, 3, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(not_equal_incorrectA2) {
  matrix_t *A = NULL, B = {NULL};

  s21_create_matrix(0, 0, A);
  s21_create_matrix(3, 3, &B);

  int res = s21_eq_matrix(A, &B);
  ck_assert_int_eq(res, 0);

  s21_remove_matrix(A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(not_equal_incorrectB) {
  matrix_t A = {NULL}, B = {NULL};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(0, 3, &B);

  int res = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(res, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_correct) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};
  matrix_t REF = {NULL};

  s21_create_matrix(2, 3, &A);
  for (int i = 0; i < A.rows; ++i)
    for (int j = 0; j < A.columns; ++j) A.matrix[i][j] = j + 1;

  s21_create_matrix(2, 3, &B);
  for (int i = 0; i < B.rows; ++i)
    for (int j = 0; j < B.columns; ++j) B.matrix[i][j] = i + 1;

  int res = s21_sum_matrix(&A, &B, &C);

  s21_create_matrix(2, 3, &REF);
  for (int i = 0; i < REF.rows; ++i)
    for (int j = 0; j < REF.columns; ++j) REF.matrix[i][j] = i + j + 2;

  ck_assert_int_eq(res, 0);
  for (int i = 0; i < REF.rows; ++i)
    for (int j = 0; j < REF.columns; ++j)
      ck_assert_double_eq(C.matrix[i][j], REF.matrix[i][j]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&REF);
}
END_TEST

START_TEST(sum_of_nonequiv1) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_of_nonequiv2) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);

  int res = s21_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_of_incorrectA) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};

  s21_create_matrix(0, 3, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_of_incorrectB) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 0, &B);

  int res = s21_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_of_incorrectC) {
  matrix_t A = {NULL}, B = {NULL}, *C = NULL;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_sum_matrix(&A, &B, C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_correct) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};
  matrix_t REF = {NULL};

  s21_create_matrix(2, 3, &A);
  for (int i = 0; i < A.rows; ++i)
    for (int j = 0; j < A.columns; ++j) A.matrix[i][j] = i + 1;

  s21_create_matrix(2, 3, &B);
  for (int i = 0; i < B.rows; ++i)
    for (int j = 0; j < B.columns; ++j) B.matrix[i][j] = j + 1;

  int res = s21_sub_matrix(&A, &B, &C);

  s21_create_matrix(2, 3, &REF);
  for (int i = 0; i < REF.rows; ++i)
    for (int j = 0; j < REF.columns; ++j) REF.matrix[i][j] = i - j;

  ck_assert_int_eq(res, 0);
  for (int i = 0; i < REF.rows; ++i)
    for (int j = 0; j < REF.columns; ++j)
      ck_assert_double_eq(C.matrix[i][j], REF.matrix[i][j]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&REF);
}
END_TEST

START_TEST(sub_of_nonequiv1) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_sub_matrix(&A, &B, &C);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_of_nonequiv2) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);

  int res = s21_sub_matrix(&A, &B, &C);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_of_incorrectA) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};

  s21_create_matrix(0, 3, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_sub_matrix(&A, &B, &C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_of_incorrectB) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};

  s21_create_matrix(3, 3, &A);

  s21_create_matrix(3, 0, &B);

  int res = s21_sub_matrix(&A, &B, &C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_of_incorrectC) {
  matrix_t A = {NULL}, B = {NULL}, *C = NULL;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_sub_matrix(&A, &B, C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_number_correct) {
  double number = -1.0;
  matrix_t A = {NULL}, C = {NULL};
  matrix_t REF = {NULL};

  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < A.rows; ++i)
    for (int j = 0; j < A.columns; ++j) A.matrix[i][j] = i;

  int res = s21_mult_number(&A, number, &C);

  s21_create_matrix(3, 3, &REF);
  for (int i = 0; i < REF.rows; ++i)
    for (int j = 0; j < REF.columns; ++j) REF.matrix[i][j] = (-1) * i;

  ck_assert_int_eq(res, 0);
  for (int i = 0; i < REF.rows; ++i)
    for (int j = 0; j < REF.columns; ++j)
      ck_assert_double_eq(C.matrix[i][j], REF.matrix[i][j]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&REF);
}
END_TEST

START_TEST(mult_number_incorrectA) {
  double number = 1.0;
  matrix_t A = {NULL}, C = {NULL};

  s21_create_matrix(3, 0, &A);

  int res = s21_mult_number(&A, number, &C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_incorrectC) {
  double number = 1.0;
  matrix_t A = {NULL}, *C = NULL;

  s21_create_matrix(3, 3, &A);

  int res = s21_mult_number(&A, number, C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_matrix_correct) {
  double count = 0.0;
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};
  matrix_t REF = {NULL};

  s21_create_matrix(3, 2, &A);
  for (int i = 0; i < A.rows; ++i)
    for (int j = 0; j < A.columns; ++j) A.matrix[i][j] = ++count;

  s21_create_matrix(2, 3, &B);
  for (int i = 0; i < B.rows; ++i)
    for (int j = 0; j < B.columns; ++j) B.matrix[i][j] = count--;

  int res = s21_mult_matrix(&A, &B, &C);

  s21_create_matrix(3, 3, &REF);
  REF.matrix[0][0] = 12.0;
  REF.matrix[0][1] = 9.0;
  REF.matrix[0][2] = 6.0;
  REF.matrix[1][0] = 30.0;
  REF.matrix[1][1] = 23.0;
  REF.matrix[1][2] = 16.0;
  REF.matrix[2][0] = 48.0;
  REF.matrix[2][1] = 37.0;
  REF.matrix[2][2] = 26.0;

  ck_assert_int_eq(res, 0);
  for (int i = 0; i < REF.rows; ++i)
    for (int j = 0; j < REF.columns; ++j)
      ck_assert_double_eq(C.matrix[i][j], REF.matrix[i][j]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&REF);
}
END_TEST

START_TEST(mult_matrix_incorrectA) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};

  s21_create_matrix(3, 0, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_incorrectB) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(0, 3, &B);

  int res = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_incorrectC) {
  matrix_t A = {NULL}, B = {NULL}, *C = NULL;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  int res = s21_mult_matrix(&A, &B, C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_unequal_sizes) {
  matrix_t A = {NULL}, B = {NULL}, C = {NULL};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 3, &B);

  int res = s21_mult_matrix(&A, &B, &C);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(transpose_correct) {
  matrix_t A = {NULL}, C = {NULL};

  s21_create_matrix(3, 2, &A);
  for (int i = 0; i < A.rows; ++i)
    for (int j = 0; j < A.columns; ++j) A.matrix[i][j] = i + j;

  int res = s21_transpose(&A, &C);

  ck_assert_int_eq(res, 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(transpose_incorrectA) {
  matrix_t A = {NULL}, C = {NULL};

  s21_create_matrix(3, 0, &A);

  int res = s21_transpose(&A, &C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_incorrectC) {
  matrix_t A = {NULL}, *C = NULL;

  s21_create_matrix(3, 3, &A);

  int res = s21_transpose(&A, C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_correct1) {
  double number = 0.0;
  matrix_t A = {NULL};

  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) A.matrix[i][j] = i == j;

  int res = s21_determinant(&A, &number);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number, 1.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_correct2) {
  double number = 0.0;
  matrix_t A = {NULL};

  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) A.matrix[i][j] = i == 2 - j;

  int res = s21_determinant(&A, &number);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number, -1.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_correct3) {
  double number = 0.0;
  matrix_t A = {NULL};

  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) A.matrix[i][j] = 1;

  int res = s21_determinant(&A, &number);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number, 0.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_correct4) {
  double number = 0.0;
  matrix_t A = {NULL};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[1][1] = 2.0;
  A.matrix[2][2] = 3.0;

  int res = s21_determinant(&A, &number);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number, 6.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_correct5) {
  double number = 0.0;
  matrix_t A = {NULL};

  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < A.rows; ++i)
    for (int j = 0; j < A.columns; ++j) A.matrix[i][j] = 1;

  int res = s21_determinant(&A, &number);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number, 0.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_correct6) {
  double number = 0.0;
  matrix_t A = {NULL};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = 4.0;

  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[1][3] = 1.0;

  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 4.0;
  A.matrix[2][2] = 1.0;
  A.matrix[2][3] = 2.0;

  A.matrix[3][0] = 4.0;
  A.matrix[3][1] = 1.0;
  A.matrix[3][2] = 2.0;
  A.matrix[3][3] = 3.0;

  int res = s21_determinant(&A, &number);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number, 160.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_correct7) {
  double number = 5.0;
  matrix_t A = {NULL};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 2.0;
  A.matrix[1][2] = 1.0;
  A.matrix[2][0] = 2.0;
  A.matrix[2][1] = 1.0;
  A.matrix[2][2] = 3.0;

  int res = s21_determinant(&A, &number);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number, -12.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_correct8) {
  double number = 5.0;
  matrix_t A = {NULL};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 10.0;

  int res = s21_determinant(&A, &number);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number, 10.0);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_incorrectA1) {
  double number = 0.0;

  matrix_t A = {NULL};

  s21_create_matrix(3, 2, &A);

  int res = s21_determinant(&A, &number);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_incorrectA2) {
  double number = 0.0;

  matrix_t A = {NULL};

  s21_create_matrix(3, 0, &A);

  int res = s21_determinant(&A, &number);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_incorrectNum) {
  double *number = NULL;

  matrix_t A = {NULL};

  s21_create_matrix(3, 3, &A);

  int res = s21_determinant(&A, number);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(comp_correct1) {
  matrix_t A = {NULL}, C = {NULL};
  matrix_t REF = {NULL};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;

  int res = s21_calc_complements(&A, &C);

  s21_create_matrix(3, 3, &REF);
  REF.matrix[0][0] = 0.0;
  REF.matrix[0][1] = 10.0;
  REF.matrix[0][2] = -20.0;
  REF.matrix[1][0] = 4.0;
  REF.matrix[1][1] = -14.0;
  REF.matrix[1][2] = 8.0;
  REF.matrix[2][0] = -8.0;
  REF.matrix[2][1] = -2.0;
  REF.matrix[2][2] = 4.0;

  ck_assert_int_eq(res, 0);
  for (int i = 0; i < REF.rows; ++i)
    for (int j = 0; j < REF.columns; ++j)
      ck_assert_double_eq(C.matrix[i][j], REF.matrix[i][j]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&REF);
}
END_TEST

START_TEST(comp_correct2) {
  matrix_t A = {NULL}, C = {NULL};
  matrix_t REF = {NULL};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5.0;

  int res = s21_calc_complements(&A, &C);

  s21_create_matrix(1, 1, &REF);
  REF.matrix[0][0] = 1.0;

  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(C.matrix[0][0], REF.matrix[0][0]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&REF);
}
END_TEST

START_TEST(comp_incorrectA1) {
  matrix_t A = {NULL}, C = {NULL};

  s21_create_matrix(0, 3, &A);

  int res = s21_calc_complements(&A, &C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(comp_incorrectA2) {
  matrix_t A = {NULL}, C = {NULL};

  s21_create_matrix(2, 3, &A);

  int res = s21_calc_complements(&A, &C);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(comp_incorrectA3) {
  matrix_t A = {NULL}, *C = NULL;

  s21_create_matrix(3, 3, &A);

  int res = s21_calc_complements(&A, C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_correct1) {
  matrix_t A = {NULL}, C = {NULL};
  matrix_t REF = {NULL};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int res = s21_inverse_matrix(&A, &C);

  s21_create_matrix(3, 3, &REF);
  REF.matrix[0][0] = 1;
  REF.matrix[0][1] = -1;
  REF.matrix[0][2] = 1;
  REF.matrix[1][0] = -38;
  REF.matrix[1][1] = 41;
  REF.matrix[1][2] = -34;
  REF.matrix[2][0] = 27;
  REF.matrix[2][1] = -29;
  REF.matrix[2][2] = 24;

  ck_assert_int_eq(res, 0);
  for (int i = 0; i < REF.rows; ++i)
    for (int j = 0; j < REF.columns; ++j)
      ck_assert_double_eq(C.matrix[i][j], REF.matrix[i][j]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&REF);
}
END_TEST

START_TEST(inverse_correct2) {
  matrix_t A = {NULL}, C = {NULL};
  matrix_t REF = {NULL};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5.0;

  int res = s21_inverse_matrix(&A, &C);

  s21_create_matrix(1, 1, &REF);
  REF.matrix[0][0] = 0.2;

  ck_assert_int_eq(res, 0);
  ck_assert_double_eq(C.matrix[0][0], REF.matrix[0][0]);

  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&REF);
}
END_TEST

START_TEST(inverse_zero_det) {
  double det = 5.6;
  matrix_t A = {NULL}, C = {NULL};

  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < A.rows; ++i)
    for (int j = 0; j < A.columns; ++j) A.matrix[i][j] = 1;

  int res = s21_inverse_matrix(&A, &C);
  s21_determinant(&A, &det);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_incorrectA1) {
  matrix_t A = {NULL}, C = {NULL};

  s21_create_matrix(0, 3, &A);

  int res = s21_inverse_matrix(&A, &C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_incorrectA2) {
  matrix_t A = {NULL}, C = {NULL};

  s21_create_matrix(2, 3, &A);

  int res = s21_inverse_matrix(&A, &C);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_incorrectA3) {
  matrix_t A = {NULL}, *C = NULL;

  s21_create_matrix(3, 3, &A);

  int res = s21_inverse_matrix(&A, C);

  ck_assert_int_eq(res, 1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_incorrectA4) {
  matrix_t A = {NULL}, C = {NULL};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 0.0;

  int res = s21_inverse_matrix(&A, &C);

  ck_assert_int_eq(res, 2);

  s21_remove_matrix(&A);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc);
  tcase_add_test(tc, create_unexisting);
  tcase_add_test(tc, create_empty);
  tcase_add_test(tc, create_incorrect_matrix1);
  tcase_add_test(tc, create_incorrect_matrix2);
  tcase_add_test(tc, create_incorrect_matrix3);
  tcase_add_test(tc, equal_correct);
  tcase_add_test(tc, not_equal1);
  tcase_add_test(tc, not_equal2);
  tcase_add_test(tc, not_equal_incorrectA1);
  tcase_add_test(tc, not_equal_incorrectA2);
  tcase_add_test(tc, not_equal_incorrectB);
  tcase_add_test(tc, sum_correct);
  tcase_add_test(tc, sum_of_nonequiv1);
  tcase_add_test(tc, sum_of_nonequiv2);
  tcase_add_test(tc, sum_of_incorrectA);
  tcase_add_test(tc, sum_of_incorrectB);
  tcase_add_test(tc, sum_of_incorrectC);
  tcase_add_test(tc, sub_correct);
  tcase_add_test(tc, sub_of_nonequiv1);
  tcase_add_test(tc, sub_of_nonequiv2);
  tcase_add_test(tc, sub_of_incorrectA);
  tcase_add_test(tc, sub_of_incorrectB);
  tcase_add_test(tc, sub_of_incorrectC);
  tcase_add_test(tc, mult_number_correct);
  tcase_add_test(tc, mult_number_incorrectA);
  tcase_add_test(tc, mult_number_incorrectC);
  tcase_add_test(tc, mult_matrix_incorrectA);
  tcase_add_test(tc, mult_matrix_incorrectB);
  tcase_add_test(tc, mult_matrix_incorrectC);
  tcase_add_test(tc, mult_matrix_unequal_sizes);
  tcase_add_test(tc, mult_matrix_correct);
  tcase_add_test(tc, transpose_correct);
  tcase_add_test(tc, transpose_incorrectA);
  tcase_add_test(tc, transpose_incorrectC);
  tcase_add_test(tc, det_correct1);
  tcase_add_test(tc, det_correct2);
  tcase_add_test(tc, det_correct3);
  tcase_add_test(tc, det_correct4);
  tcase_add_test(tc, det_correct5);
  tcase_add_test(tc, det_correct6);
  tcase_add_test(tc, det_correct7);
  tcase_add_test(tc, det_correct8);
  tcase_add_test(tc, det_incorrectA1);
  tcase_add_test(tc, det_incorrectA2);
  tcase_add_test(tc, det_incorrectNum);
  tcase_add_test(tc, comp_correct1);
  tcase_add_test(tc, comp_correct2);
  tcase_add_test(tc, comp_incorrectA1);
  tcase_add_test(tc, comp_incorrectA2);
  tcase_add_test(tc, comp_incorrectA3);
  tcase_add_test(tc, inverse_correct1);
  tcase_add_test(tc, inverse_correct2);
  tcase_add_test(tc, inverse_zero_det);
  tcase_add_test(tc, inverse_incorrectA1);
  tcase_add_test(tc, inverse_incorrectA2);
  tcase_add_test(tc, inverse_incorrectA3);
  tcase_add_test(tc, inverse_incorrectA4);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
