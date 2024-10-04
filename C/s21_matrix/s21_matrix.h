#include <stdio.h>
#include <stdlib.h>

#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define OK 0
#define INCORRECT_MATRIX 1
#define COMPUTATION_FAIL 2

#define SUCCESS 1
#define FAILURE 0

/*
0 — OK;
1 — Ошибка, некорректная матрица;
2 — Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя
провести вычисления и т. д.).
*/

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);     //	+
void s21_remove_matrix(matrix_t *A);                                //	+
int s21_eq_matrix(matrix_t *A, matrix_t *B);                        //	+
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     //	+
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     //	+
int s21_mult_number(matrix_t *A, double number, matrix_t *result);  //	+
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);    //	+
int s21_transpose(matrix_t *A, matrix_t *result);                   //	+
int s21_calc_complements(matrix_t *A, matrix_t *result);            //	+
int s21_determinant(matrix_t *A, double *result);                   //	+
int s21_inverse_matrix(matrix_t *A, matrix_t *result);              //	+

// Auxiliary functions

int check_correctness_of_matrix(matrix_t *A);                    //	+
int check_equivalence_of_sizes(matrix_t *A, matrix_t *B);        //	+
int minus_one(int i, int j);                                     //	+
void calc_minor(matrix_t *A, int i1, int j1, matrix_t *result);  //	+

#endif