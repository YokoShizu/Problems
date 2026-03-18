#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(MatrixConstAndDestr, DefaultConstructorException) {
  ASSERT_THROW(S21Matrix result(0, -1), std::invalid_argument);
}

TEST(MatrixConstAndDestr, DefaultConstructor) {
  S21Matrix result;
  ASSERT_EQ(result.AccessorRows(), 1);
  ASSERT_EQ(result.AccessorCols(), 1);
  ASSERT_DOUBLE_EQ(result(0, 0), 0.0);
}

TEST(MatrixConstAndDestr, ParametrizedConstructor) {
  S21Matrix result(2, 2);
  ASSERT_EQ(result.AccessorRows(), 2);
  ASSERT_EQ(result.AccessorCols(), 2);
  ASSERT_DOUBLE_EQ(result(0, 0), 0.0);
  ASSERT_DOUBLE_EQ(result(0, 1), 0.0);
  ASSERT_DOUBLE_EQ(result(1, 0), 0.0);
  ASSERT_DOUBLE_EQ(result(1, 1), 0.0);
}

TEST(MatrixConstAndDestr, CopyConstructor) {
  S21Matrix matrix(3, 3);

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) matrix(i, j) = i + j;

  S21Matrix result(matrix);

  ASSERT_EQ(result.AccessorRows(), matrix.AccessorRows());
  ASSERT_EQ(result.AccessorCols(), matrix.AccessorCols());

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) ASSERT_DOUBLE_EQ(result(i, j), matrix(i, j));
}

TEST(MatrixConstAndDestr, MoveConstructor) {
  S21Matrix result(S21Matrix(2, 2));
  ASSERT_EQ(result.AccessorRows(), 2);
  ASSERT_EQ(result.AccessorCols(), 2);
  ASSERT_DOUBLE_EQ(result(0, 0), 0.0);
  ASSERT_DOUBLE_EQ(result(0, 1), 0.0);
  ASSERT_DOUBLE_EQ(result(1, 0), 0.0);
  ASSERT_DOUBLE_EQ(result(1, 1), 0.0);
}

TEST(MatrixMutator, MoreRows) {
  S21Matrix result(2, 2);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) result(i, j) = i + j + 1;

  result.Mutator(3, 2);

  ASSERT_EQ(result.AccessorRows(), 3);
  ASSERT_EQ(result.AccessorCols(), 2);
  ASSERT_DOUBLE_EQ(result(0, 0), 1.0);
  ASSERT_DOUBLE_EQ(result(0, 1), 2.0);
  ASSERT_DOUBLE_EQ(result(1, 0), 2.0);
  ASSERT_DOUBLE_EQ(result(1, 1), 3.0);
  ASSERT_DOUBLE_EQ(result(2, 0), 0.0);
  ASSERT_DOUBLE_EQ(result(2, 1), 0.0);
}

TEST(MatrixMutator, MoreCols) {
  S21Matrix result(2, 2);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) result(i, j) = i + j + 1;

  result.Mutator(2, 3);

  ASSERT_EQ(result.AccessorRows(), 2);
  ASSERT_EQ(result.AccessorCols(), 3);
  ASSERT_DOUBLE_EQ(result(0, 0), 1.0);
  ASSERT_DOUBLE_EQ(result(0, 1), 2.0);
  ASSERT_DOUBLE_EQ(result(0, 2), 0.0);
  ASSERT_DOUBLE_EQ(result(1, 0), 2.0);
  ASSERT_DOUBLE_EQ(result(1, 1), 3.0);
  ASSERT_DOUBLE_EQ(result(1, 2), 0.0);
}

TEST(MatrixMutator, LessRows) {
  S21Matrix result(2, 2);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) result(i, j) = i + j + 1;

  result.Mutator(1, 2);

  ASSERT_EQ(result.AccessorRows(), 1);
  ASSERT_EQ(result.AccessorCols(), 2);
  ASSERT_DOUBLE_EQ(result(0, 0), 1.0);
  ASSERT_DOUBLE_EQ(result(0, 1), 2.0);
}

TEST(MatrixMutator, LessCols) {
  S21Matrix result(2, 2);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) result(i, j) = i + j + 1;

  result.Mutator(2, 1);

  ASSERT_EQ(result.AccessorRows(), 2);
  ASSERT_EQ(result.AccessorCols(), 1);
  ASSERT_DOUBLE_EQ(result(0, 0), 1.0);
  ASSERT_DOUBLE_EQ(result(1, 0), 2.0);
}

TEST(MatrixMutator, LessRowsAndCols) {
  S21Matrix result(2, 2);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) result(i, j) = i + j + 1;

  result.Mutator(1, 1);

  ASSERT_EQ(result.AccessorRows(), 1);
  ASSERT_EQ(result.AccessorCols(), 1);
  ASSERT_DOUBLE_EQ(result(0, 0), 1.0);
}

TEST(MatrixMutator, MoreRowsAndCols) {
  S21Matrix result(2, 2);
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) result(i, j) = i + j + 1;

  result.Mutator(3, 3);

  ASSERT_EQ(result.AccessorRows(), 3);
  ASSERT_EQ(result.AccessorCols(), 3);
  ASSERT_DOUBLE_EQ(result(0, 0), 1.0);
  ASSERT_DOUBLE_EQ(result(0, 1), 2.0);
  ASSERT_DOUBLE_EQ(result(0, 2), 0.0);
  ASSERT_DOUBLE_EQ(result(1, 0), 2.0);
  ASSERT_DOUBLE_EQ(result(1, 1), 3.0);
  ASSERT_DOUBLE_EQ(result(1, 2), 0.0);
}

TEST(MatrixLogical, EqualMatrices) {
  S21Matrix mat1(2, 2), mat2(2, 2);

  mat1(0, 0) = 1.5;
  mat1(0, 1) = -2.3;
  mat1(1, 0) = 4.1;
  mat1(1, 1) = 0.7;

  mat2(0, 0) = 1.5;
  mat2(0, 1) = -2.3;
  mat2(1, 0) = 4.1;
  mat2(1, 1) = 0.7;

  ASSERT_TRUE(mat1.EqMatrix(mat2));
}

TEST(MatrixLogical, NotEqualMatrices1) {
  S21Matrix mat1(2, 2), mat2(2, 2);

  mat1(0, 0) = 1.5;
  mat1(0, 1) = -2.3;
  mat1(1, 0) = 4.1;
  mat1(1, 1) = 0.7;

  mat2(0, 0) = 1.5;
  mat2(0, 1) = 2.3;
  mat2(1, 0) = 4.1;
  mat2(1, 1) = 0.7;

  ASSERT_FALSE(mat1.EqMatrix(mat2));
}

TEST(MatrixLogical, NotEqualMatrices2) {
  S21Matrix mat1(2, 2), mat2(2, 2);

  mat1(0, 0) = 1.5;
  mat1(0, 1) = -2.3;
  mat1(1, 0) = 4.1;
  mat1(1, 1) = 0.7;

  mat2(0, 0) = 3.2;
  mat2(0, 1) = 1.3;
  mat2(1, 0) = -0.9;
  mat2(1, 1) = 2.8;

  ASSERT_FALSE(mat1.EqMatrix(mat2));
}

TEST(MatrixBasicOperations, SumExceptrion1) {
  S21Matrix mat1(2, 1), mat2(2, 2);
  ASSERT_THROW(mat1 += mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SumMExceptrion2) {
  S21Matrix mat1(2, 2), mat2(1, 2);
  ASSERT_THROW(mat1 += mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SumExceptrion3) {
  S21Matrix mat1(2, 2), mat2(3, 3);
  ASSERT_THROW(mat1 += mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SumExceptrion4) {
  S21Matrix mat1(2, 1), mat2(2, 2);
  ASSERT_THROW(mat1 + mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SumMExceptrion5) {
  S21Matrix mat1(2, 2), mat2(1, 2);
  ASSERT_THROW(mat1 + mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SumExceptrion6) {
  S21Matrix mat1(2, 2), mat2(3, 3);
  ASSERT_THROW(mat1 + mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SumCorrectAsMethod) {
  S21Matrix mat1(2, 2), mat2(2, 2), result(2, 2);

  mat1(0, 0) = 1.23456789;
  mat1(0, 1) = 2.34567891;
  mat1(1, 0) = -3.45678912;
  mat1(1, 1) = 4.56789123;

  mat2(0, 0) = 5.67891234;
  mat2(0, 1) = -1.23456789;
  mat2(1, 0) = 0.12345678;
  mat2(1, 1) = -4.56789123;

  result(0, 0) = 6.9134802300;
  result(0, 1) = 1.1111110200;
  result(1, 0) = -3.3333323400;
  result(1, 1) = 0.0000000000;

  mat1.SumMatrix(mat2);

  ASSERT_EQ(mat1.AccessorRows(), result.AccessorRows());
  ASSERT_EQ(mat1.AccessorCols(), result.AccessorRows());

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(mat1(i, j), result(i, j));
}

TEST(MatrixBasicOperations, SumCorrectAsCompAssign) {
  S21Matrix mat1(2, 2), mat2(2, 2), result(2, 2);

  mat1(0, 0) = 1.23456789;
  mat1(0, 1) = 2.34567891;
  mat1(1, 0) = -3.45678912;
  mat1(1, 1) = 4.56789123;

  mat2(0, 0) = 5.67891234;
  mat2(0, 1) = -1.23456789;
  mat2(1, 0) = 0.12345678;
  mat2(1, 1) = -4.56789123;

  result(0, 0) = 6.9134802300;
  result(0, 1) = 1.1111110200;
  result(1, 0) = -3.3333323400;
  result(1, 1) = 0.0000000000;

  mat1 += mat2;

  ASSERT_EQ(mat1.AccessorRows(), result.AccessorRows());
  ASSERT_EQ(mat1.AccessorCols(), result.AccessorRows());

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(mat1(i, j), result(i, j));
}

TEST(MatrixBasicOperations, SumCorrectAsFunction) {
  S21Matrix mat1(2, 2), mat2(2, 2), result(2, 2);

  mat1(0, 0) = 1.23456789;
  mat1(0, 1) = 2.34567891;
  mat1(1, 0) = -3.45678912;
  mat1(1, 1) = 4.56789123;

  mat2(0, 0) = 5.67891234;
  mat2(0, 1) = -1.23456789;
  mat2(1, 0) = 0.12345678;
  mat2(1, 1) = -4.56789123;

  result(0, 0) = 6.9134802300;
  result(0, 1) = 1.1111110200;
  result(1, 0) = -3.3333323400;
  result(1, 1) = 0.0000000000;

  S21Matrix matrix(mat1 + mat2);

  ASSERT_EQ(matrix.AccessorRows(), result.AccessorRows());
  ASSERT_EQ(matrix.AccessorCols(), result.AccessorRows());

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

TEST(MatrixBasicOperations, SubExceptrion1) {
  S21Matrix mat1(2, 1), mat2(2, 2);
  ASSERT_THROW(mat1 -= mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SubExceptrion2) {
  S21Matrix mat1(2, 2), mat2(1, 2);
  ASSERT_THROW(mat1 -= mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SubExceptrion3) {
  S21Matrix mat1(2, 2), mat2(3, 3);
  ASSERT_THROW(mat1 -= mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SubExceptrion4) {
  S21Matrix mat1(2, 1), mat2(2, 2);
  ASSERT_THROW(mat1 - mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SubExceptrion5) {
  S21Matrix mat1(2, 2), mat2(1, 2);
  ASSERT_THROW(mat1 - mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SubExceptrion6) {
  S21Matrix mat1(2, 2), mat2(3, 3);
  ASSERT_THROW(mat1 - mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, SubCorrectAsMethod) {
  S21Matrix mat1(2, 2), mat2(2, 2), result(2, 2);

  mat1(0, 0) = 1.23456789;
  mat1(0, 1) = 2.34567891;
  mat1(1, 0) = -3.45678912;
  mat1(1, 1) = 4.56789123;

  mat2(0, 0) = 5.67891234;
  mat2(0, 1) = -1.23456789;
  mat2(1, 0) = 0.12345678;
  mat2(1, 1) = -4.56789123;

  result(0, 0) = -4.44434445;
  result(0, 1) = 3.58024680;
  result(1, 0) = -3.58024590;
  result(1, 1) = 9.13578246;

  mat1.SubMatrix(mat2);

  ASSERT_EQ(mat1.AccessorRows(), result.AccessorRows());
  ASSERT_EQ(mat1.AccessorCols(), result.AccessorRows());

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(mat1(i, j), result(i, j));
}

TEST(MatrixBasicOperations, SubCorrectAsCompAssign) {
  S21Matrix mat1(2, 2), mat2(2, 2), result(2, 2);

  mat1(0, 0) = 1.23456789;
  mat1(0, 1) = 2.34567891;
  mat1(1, 0) = -3.45678912;
  mat1(1, 1) = 4.56789123;

  mat2(0, 0) = 5.67891234;
  mat2(0, 1) = -1.23456789;
  mat2(1, 0) = 0.12345678;
  mat2(1, 1) = -4.56789123;

  result(0, 0) = -4.44434445;
  result(0, 1) = 3.58024680;
  result(1, 0) = -3.58024590;
  result(1, 1) = 9.13578246;

  mat1 -= mat2;

  ASSERT_EQ(mat1.AccessorRows(), result.AccessorRows());
  ASSERT_EQ(mat1.AccessorCols(), result.AccessorRows());

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(mat1(i, j), result(i, j));
}

TEST(MatrixBasicOperations, SubCorrectAsFunction) {
  S21Matrix mat1(2, 2), mat2(2, 2), result(2, 2);

  mat1(0, 0) = 1.23456789;
  mat1(0, 1) = 2.34567891;
  mat1(1, 0) = -3.45678912;
  mat1(1, 1) = 4.56789123;

  mat2(0, 0) = 5.67891234;
  mat2(0, 1) = -1.23456789;
  mat2(1, 0) = 0.12345678;
  mat2(1, 1) = -4.56789123;

  result(0, 0) = -4.44434445;
  result(0, 1) = 3.58024680;
  result(1, 0) = -3.58024590;
  result(1, 1) = 9.13578246;

  S21Matrix matrix(mat1 - mat2);

  ASSERT_EQ(matrix.AccessorRows(), result.AccessorRows());
  ASSERT_EQ(matrix.AccessorCols(), result.AccessorRows());

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

TEST(MatrixBasicOperations, MulNumberAsMethod) {
  S21Matrix matrix(2, 2), result(2, 2);

  matrix(0, 0) = 1.23456789;
  matrix(0, 1) = 2.34567891;
  matrix(1, 0) = -3.45678912;
  matrix(1, 1) = 4.56789123;

  result(0, 0) = 1.23456789 * 2.0;
  result(0, 1) = 2.34567891 * 2.0;
  result(1, 0) = -3.45678912 * 2.0;
  result(1, 1) = 4.56789123 * 2.0;

  matrix.MulNumber(2.0);

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

TEST(MatrixBasicOperations, MulNumberAsCompAssign) {
  S21Matrix matrix(2, 2), result(2, 2);

  matrix(0, 0) = 1.23456789;
  matrix(0, 1) = 2.34567891;
  matrix(1, 0) = -3.45678912;
  matrix(1, 1) = 4.56789123;

  result(0, 0) = 1.23456789 * 2.0;
  result(0, 1) = 2.34567891 * 2.0;
  result(1, 0) = -3.45678912 * 2.0;
  result(1, 1) = 4.56789123 * 2.0;

  matrix *= 2.0;

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

TEST(MatrixBasicOperations, MulNumberAsFunction1) {
  S21Matrix mat(2, 2), result(2, 2);

  mat(0, 0) = 1.23456789;
  mat(0, 1) = 2.34567891;
  mat(1, 0) = -3.45678912;
  mat(1, 1) = 4.56789123;

  result(0, 0) = 1.23456789 * 2.0;
  result(0, 1) = 2.34567891 * 2.0;
  result(1, 0) = -3.45678912 * 2.0;
  result(1, 1) = 4.56789123 * 2.0;

  S21Matrix matrix = mat * 2.0;

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

TEST(MatrixBasicOperations, MulNumberAsFunction2) {
  S21Matrix mat(2, 2), result(2, 2);

  mat(0, 0) = 1.23456789;
  mat(0, 1) = 2.34567891;
  mat(1, 0) = -3.45678912;
  mat(1, 1) = 4.56789123;

  result(0, 0) = 1.23456789 * 2.0;
  result(0, 1) = 2.34567891 * 2.0;
  result(1, 0) = -3.45678912 * 2.0;
  result(1, 1) = 4.56789123 * 2.0;

  S21Matrix matrix = 2.0 * mat;

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

TEST(MatrixBasicOperations, MulMatrixException) {
  S21Matrix mat1(2, 3), mat2(2, 2);
  ASSERT_THROW(mat1 * mat2, std::invalid_argument);
}

TEST(MatrixBasicOperations, MulMatrixAsCompAssign) {
  S21Matrix mat1(2, 3), mat2(3, 2), result(2, 2);

  mat1(0, 0) = 1.23456789;
  mat1(0, 1) = 2.34567891;
  mat1(0, 2) = -0.98765432;
  mat1(1, 0) = -3.45678912;
  mat1(1, 1) = 4.56789123;
  mat1(1, 2) = 1.11111111;

  mat2(0, 0) = 5.67891234;
  mat2(0, 1) = -1.23456789;
  mat2(1, 0) = 0.12345678;
  mat2(1, 1) = -4.56789123;
  mat2(2, 0) = 2.22222222;
  mat2(2, 1) = 3.33333333;

  result(0, 0) = 5.1058054146482820;
  result(0, 1) = -15.5311450597784970;
  result(1, 0) = -16.5977294501688372;
  result(1, 1) = -12.8942857427612598;

  mat1 *= mat2;

  ASSERT_EQ(mat1.AccessorRows(), result.AccessorRows());
  ASSERT_EQ(mat1.AccessorCols(), result.AccessorRows());

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(mat1(i, j), result(i, j));
}

TEST(MatrixBasicOperations, MulMatrixAsMethod) {
  S21Matrix mat1(2, 3), mat2(3, 2), result(2, 2);

  mat1(0, 0) = 1.23456789;
  mat1(0, 1) = 2.34567891;
  mat1(0, 2) = -0.98765432;
  mat1(1, 0) = -3.45678912;
  mat1(1, 1) = 4.56789123;
  mat1(1, 2) = 1.11111111;

  mat2(0, 0) = 5.67891234;
  mat2(0, 1) = -1.23456789;
  mat2(1, 0) = 0.12345678;
  mat2(1, 1) = -4.56789123;
  mat2(2, 0) = 2.22222222;
  mat2(2, 1) = 3.33333333;

  result(0, 0) = 5.1058054146482820;
  result(0, 1) = -15.5311450597784970;
  result(1, 0) = -16.5977294501688372;
  result(1, 1) = -12.8942857427612598;

  S21Matrix matrix(mat1 * mat2);

  ASSERT_EQ(matrix.AccessorRows(), result.AccessorRows());
  ASSERT_EQ(matrix.AccessorCols(), result.AccessorRows());

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

TEST(MatrixOperatorsOverload, CopyAssignment) {
  S21Matrix matrix(3, 3), result;

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) matrix(i, j) = i + j;

  result = matrix;

  ASSERT_EQ(result.AccessorRows(), matrix.AccessorRows());
  ASSERT_EQ(result.AccessorCols(), matrix.AccessorRows());

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) ASSERT_DOUBLE_EQ(result(i, j), matrix(i, j));
}

TEST(MatrixOperatorsOverload, ChainAssignment) {
  S21Matrix matrix(3, 3), aux, result;

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) matrix(i, j) = i + j;

  result = aux = matrix;

  ASSERT_EQ(result.AccessorRows(), matrix.AccessorRows());
  ASSERT_EQ(result.AccessorCols(), matrix.AccessorRows());

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) ASSERT_DOUBLE_EQ(result(i, j), matrix(i, j));

}

TEST(MatrixOperatorsOverload, MoveAssignment) {
  S21Matrix result(2, 2), matrix(3, 3);

  result = S21Matrix(3, 3);

  ASSERT_EQ(result.AccessorRows(), matrix.AccessorRows());
  ASSERT_EQ(result.AccessorCols(), matrix.AccessorRows());

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) ASSERT_DOUBLE_EQ(result(i, j), matrix(i, j));
}

TEST(MatrixOperatorsOverload, ElementIndexNonConstException) {
  S21Matrix result(2, 2);

  ASSERT_THROW(result(1, 2), std::out_of_range);
}

TEST(MatrixOperatorsOverload, ElementIndexConstException) {
  const S21Matrix result(2, 2);

  ASSERT_THROW(result(1, 2), std::out_of_range);
}

TEST(MatrixOperatorsOverload, ElementIndexConstCorrect) {
  const S21Matrix result(2, 2);

  ASSERT_DOUBLE_EQ(result(1, 1), 0.0);
}

TEST(MatrixLinearAlgebra, TransposeMatrix) {
  S21Matrix mat(2, 3), result(3, 2);

  mat(0, 0) = 1.23456789;
  mat(0, 1) = 2.34567891;
  mat(0, 2) = -0.98765432;
  mat(1, 0) = -3.45678912;
  mat(1, 1) = 4.56789123;
  mat(1, 2) = 1.11111111;

  result(0, 0) = 1.23456789;
  result(0, 1) = -3.45678912;
  result(1, 0) = 2.34567891;
  result(1, 1) = 4.56789123;
  result(2, 0) = -0.98765432;
  result(2, 1) = 1.11111111;

  S21Matrix matrix{Transpose(mat)};

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

TEST(MatrixLinearAlgebra, DeterminantException) {
  S21Matrix matrix(2, 3);

  ASSERT_THROW(Determinant(matrix), std::invalid_argument);
}

TEST(MatrixLinearAlgebra, DeterminantCorrectZero) {
  S21Matrix matrix(3, 3);

  ASSERT_DOUBLE_EQ(Determinant(matrix), 0.0);
}

TEST(MatrixLinearAlgebra, DeterminantCorrect2x2) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 5.10581;
  matrix(0, 1) = -16.5977;
  matrix(1, 0) = -15.5311;
  matrix(1, 1) = -12.68943;

  ASSERT_DOUBLE_EQ(Determinant(matrix), -322.5703570583);
}

TEST(MatrixLinearAlgebra, DeterminantCorrect3x3) {
  S21Matrix matrix(3, 3);

  matrix(0, 0) = -0.6;
  matrix(0, 1) = 16.09;
  matrix(0, 2) = -5.95;
  matrix(1, 0) = 0.8;
  matrix(1, 1) = -4.65;
  matrix(1, 2) = 2.55;
  matrix(2, 0) = -5.64;
  matrix(2, 1) = -0.66;
  matrix(2, 2) = 6.45;

  ASSERT_DOUBLE_EQ(Determinant(matrix), -138.25878000);
}

TEST(MatrixLinearAlgebra, InverseMatrixException) {
  S21Matrix matrix(2, 2);

  ASSERT_THROW(InverseMatrix(matrix), std::invalid_argument);
}

TEST(MatrixLinearAlgebra, InverseMatrixCorrect2x2) {
  S21Matrix mat(2, 2), result(2, 2);

  mat(0, 0) = 5.10581;
  mat(0, 1) = -16.5977;
  mat(1, 0) = -15.5311;
  mat(1, 1) = -12.8943;

  result(0, 0) = 0.039844397945979544;
  result(0, 1) = -0.051288194301977206;
  result(1, 0) = -0.047992316677819106;
  result(1, 1) = -0.015777353208515532;

  S21Matrix matrix{InverseMatrix(mat)};

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

TEST(MatrixLinearAlgebra, InverseMatrixCorrect3x3) {
  S21Matrix mat(3, 3), result(3, 3);

  mat(0, 0) = -0.6;
  mat(0, 1) = 16.09;
  mat(0, 2) = -5.95;
  mat(1, 0) = 0.8;
  mat(1, 1) = -4.65;
  mat(1, 2) = 2.55;
  mat(2, 0) = -5.64;
  mat(2, 1) = -0.66;
  mat(2, 2) = 6.45;

  result(0, 0) = 0.204757339823192422;
  result(0, 1) = 0.722221764144020365;
  result(0, 2) = -0.096644856840194887;
  result(1, 0) = 0.141343645589813537;
  result(1, 1) = 0.270709751670020522;
  result(1, 2) = 0.023361988294703599;
  result(2, 0) = 0.193506698091795689;
  result(2, 1) = 0.659224679980540838;
  result(2, 2) = 0.072921227859814762;

  S21Matrix matrix{InverseMatrix(mat)};

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

TEST(MatrixLinearAlgebra, CofactorMatrixExctention) {
  S21Matrix matrix(2, 3);

  ASSERT_THROW(CalcComplements(matrix), std::invalid_argument);
}

TEST(MatrixLinearAlgebra, CofactorMatrixCorrect2x2) {
  S21Matrix mat(2, 2), result(2, 2);

  mat(0, 0) = 5.10581;
  mat(0, 1) = -16.5977;
  mat(1, 0) = -15.5311;
  mat(1, 1) = -12.8943;

  result(0, 0) = -12.8943;
  result(0, 1) = 15.5311;
  result(1, 0) = 16.5977;
  result(1, 1) = 5.10581;

  S21Matrix matrix{CalcComplements(mat)};

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

TEST(MatrixLinearAlgebra, CofactorMatrixCorrect3x3) {
  S21Matrix mat(3, 3), result(3, 3);

  mat(0, 0) = -0.6;
  mat(0, 1) = 16.09;
  mat(0, 2) = -5.95;
  mat(1, 0) = 0.8;
  mat(1, 1) = -4.65;
  mat(1, 2) = 2.55;
  mat(2, 0) = -5.64;
  mat(2, 1) = -0.66;
  mat(2, 2) = 6.45;

  result(0, 0) = -28.3095;
  result(0, 1) = -19.542;
  result(0, 2) = -26.754;
  result(1, 0) = -99.8535;
  result(1, 1) = -37.428;
  result(1, 2) = -91.1436;
  result(2, 0) = 13.362;
  result(2, 1) = -3.23;
  result(2, 2) = -10.082;

  S21Matrix matrix{CalcComplements(mat)};

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) ASSERT_DOUBLE_EQ(matrix(i, j), result(i, j));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}