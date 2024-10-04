#include "s21_matrix.h"

// 1 == ERROR, 0 == OK
int check_correctness_of_matrix(matrix_t *A) {
  return (A == NULL || A->matrix == NULL || A->columns <= 0 || A->rows <= 0);
}

// 1 == ERROR, 0 == OK
int check_equivalence_of_sizes(matrix_t *A, matrix_t *B) {
  return (A->columns != B->columns || A->rows != B->rows);
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;
  if (rows > 0 && columns > 0 && result != NULL) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix)
      for (int i = 0; i < rows; ++i) {
        result->matrix[i] = calloc(columns, sizeof(double));
        if (!result->matrix[i]) {
          flag = COMPUTATION_FAIL;
          break;
        }
      }
    else
      flag = COMPUTATION_FAIL;
  } else
    flag = INCORRECT_MATRIX;
  return flag;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0) {
    for (int i = 0; i < A->rows; ++i) free(A->matrix[i]);
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  flag -= check_correctness_of_matrix(A) || check_correctness_of_matrix(B) ||
          check_equivalence_of_sizes(A, B);
  if (flag) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j)
        if (A->matrix[i][j] - B->matrix[i][j] >= 1e-7) {
          flag = 0;
          break;
        }
      if (!flag) break;
    }
  }
  return flag;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = (check_correctness_of_matrix(A) ||
              check_correctness_of_matrix(B) || result == NULL) > 0
                 ? 1
                 : (check_equivalence_of_sizes(A, B) ? 2 : 0);
  if (!flag) {
    flag = s21_create_matrix(A->rows, A->columns, result);
    if (!flag)
      for (int i = 0; i < result->rows; ++i)
        for (int j = 0; j < result->columns; ++j)
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
  }
  return flag;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = (check_correctness_of_matrix(A) ||
              check_correctness_of_matrix(B) || result == NULL) > 0
                 ? 1
                 : (check_equivalence_of_sizes(A, B) ? 2 : 0);
  if (!flag) {
    flag = s21_create_matrix(A->rows, A->columns, result);
    if (!flag)
      for (int i = 0; i < result->rows; ++i)
        for (int j = 0; j < result->columns; ++j)
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
  }
  return flag;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = (check_correctness_of_matrix(A) || result == NULL) > 0 ? 1 : 0;
  if (!flag) {
    flag = s21_create_matrix(A->rows, A->columns, result);
    if (!flag)
      for (int i = 0; i < result->rows; ++i)
        for (int j = 0; j < result->columns; ++j)
          result->matrix[i][j] = number * A->matrix[i][j];
  }
  return flag;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = (check_correctness_of_matrix(A) ||
              check_correctness_of_matrix(B) || result == NULL) > 0
                 ? 1
                 : (A->columns != B->rows ? 2 : 0);
  if (!flag) {
    flag = s21_create_matrix(A->rows, B->columns, result);
    if (!flag)
      for (int i = 0; i < result->rows; ++i)
        for (int j = 0; j < result->columns; ++j)
          for (int k = 0; k < A->columns; ++k)
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
  }
  return flag;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = (check_correctness_of_matrix(A) || result == NULL) > 0 ? 1 : 0;
  if (!flag) {
    flag = s21_create_matrix(A->columns, A->rows, result);
    if (!flag)
      for (int i = 0; i < result->rows; ++i)
        for (int j = 0; j < result->columns; ++j)
          result->matrix[i][j] = A->matrix[j][i];
  }
  return flag;
}

int minus_one(int i, int j) { return ((i + j) % 2 ? -1 : 1); }

void calc_minor(matrix_t *A, int i1, int j1, matrix_t *result) {
  for (int i = 0; i < A->rows; ++i) {
    if (i == i1) continue;
    for (int j = 0; j < A->columns; ++j) {
      if (j == j1) continue;
      result->matrix[i - (i > i1)][j - (j > j1)] = A->matrix[i][j];
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  int flag = (check_correctness_of_matrix(A) || result == NULL) > 0
                 ? 1
                 : (A->columns != A->rows ? 2 : 0);
  if (!flag) {
    if (A->columns == 1)
      *result = A->matrix[0][0];
    else if (A->columns == 2)
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    else {
      double auxil_det = 0.0;
      for (int j = 0; j < A->columns; ++j) {
        double auxil_number = 0.0;
        matrix_t auxil_matrix = {NULL};
        flag = s21_create_matrix(A->rows - 1, A->columns - 1, &auxil_matrix);
        if (!flag) {
          calc_minor(A, 0, j, &auxil_matrix);
          s21_determinant(&auxil_matrix, &auxil_number);
          auxil_number *= minus_one(0, j) * A->matrix[0][j];
          auxil_det += auxil_number;
          s21_remove_matrix(&auxil_matrix);
        }
      }
      *result = auxil_det;
    }
  }
  return flag;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = (check_correctness_of_matrix(A) || result == NULL) > 0
                 ? 1
                 : (A->columns != A->rows ? 2 : 0);
  if (!flag) {
    flag = s21_create_matrix(A->columns, A->rows, result);
    if (A->columns == 1)
      result->matrix[0][0] = 1;
    else {
      for (int i = 0; i < result->rows; ++i)
        for (int j = 0; j < result->columns; ++j) {
          double auxil_det = 0.0;
          matrix_t auxil_matrix;
          flag = s21_create_matrix(A->rows - 1, A->columns - 1, &auxil_matrix);
          calc_minor(A, i, j, &auxil_matrix);
          flag = s21_determinant(&auxil_matrix, &auxil_det);
          if (!flag) result->matrix[i][j] = auxil_det * minus_one(i, j);
          s21_remove_matrix(&auxil_matrix);
        }
    }
  }
  return flag;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double det = 1.0;
  int flag = (result == NULL) > 0 ? 1 : s21_determinant(A, &det);
  flag = flag > 0 ? flag : (det == 0.0) * 2;
  if (!flag && A->rows > 1) {
    matrix_t auxil_matrix = {NULL};
    flag = s21_calc_complements(A, &auxil_matrix);
    if (!flag) {
      flag = s21_transpose(&auxil_matrix, result);
      if (!flag)
        for (int i = 0; i < result->rows; ++i)
          for (int j = 0; j < result->columns; ++j) result->matrix[i][j] /= det;
    }
    s21_remove_matrix(&auxil_matrix);
  } else if (!flag && A->rows == 1) {
    flag = s21_create_matrix(1, 1, result);
    if (!flag) result->matrix[0][0] = 1.0 / det;
  }
  return flag;
}