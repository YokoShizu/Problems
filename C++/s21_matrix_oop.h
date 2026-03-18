#pragma once

#include <iostream>

#define EPS 1e-10

class S21Matrix {
 private:
  int rows_{1}, cols_{1};
  double **matrix_{nullptr};

 public:
  S21Matrix(int rows = 1, int cols = 1) {
    if (rows <= 0 || cols <= 0)
      throw std::invalid_argument(
          "Rows number and columns number of the matrix must be natural");
    rows_ = rows;
    cols_ = cols;
    matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; ++i) matrix_[i] = new double[cols_]{};
  }

  S21Matrix(const S21Matrix &other) : S21Matrix(other.rows_, other.cols_) {
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j) matrix_[i][j] = other.matrix_[i][j];
  }

  S21Matrix(S21Matrix &&other) noexcept
      : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
  }

  ~S21Matrix() {
    for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
  }

  int AccessorRows() const { return rows_; }

  int AccessorCols() const { return cols_; }

  void Mutator(int rows = 1, int cols = 1) {
    if ((rows > 0 && cols > 0) && (rows != rows_ || cols != cols_)) {
      double **new_ptr{};

      new_ptr = new double *[rows];

      for (int i = 0; i < rows; ++i) new_ptr[i] = new double[cols]{};

      for (int i = 0; i < rows_ && i < rows; ++i)
        for (int j = 0; j < cols_ && j < cols; ++j)
          new_ptr[i][j] = matrix_[i][j];

      for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
      delete[] matrix_;

      matrix_ = new_ptr;
      rows_ = rows;
      cols_ = cols;
    }
  }

  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);

  S21Matrix& operator=(const S21Matrix &other);
  S21Matrix& operator=(S21Matrix &&other);
  S21Matrix& operator+=(const S21Matrix &other);
  S21Matrix& operator-=(const S21Matrix &other);
  S21Matrix& operator*=(const double num);
  S21Matrix& operator*=(const S21Matrix &other);
  double &operator()(int i, int j);
  const double &operator()(int i, int j) const;
};

S21Matrix operator+(const S21Matrix &other1, const S21Matrix &other2);
S21Matrix operator-(const S21Matrix &other1, const S21Matrix &other2);
S21Matrix operator*(const S21Matrix &other1, const S21Matrix &other2);
S21Matrix operator*(const S21Matrix &other, const double num);
S21Matrix operator*(const double num, const S21Matrix &other);
bool operator==(const S21Matrix &other1, const S21Matrix &other2);

S21Matrix Transpose(const S21Matrix &other);
S21Matrix CalcComplements(const S21Matrix &other);
double Determinant(const S21Matrix &other);
S21Matrix InverseMatrix(const S21Matrix &other);

// Additional

double dabs(const double &a);
void find_pivot(const S21Matrix &matrix, int diag, double &pivot,
                int &pivot_index, int rank);
void swap_rows(S21Matrix &matrix, int diag, int pivot_index, int rank);
void elim_rows_top_down(S21Matrix &matrix, int diag, int rank);
void elim_rows_extended_td(S21Matrix &matrix, S21Matrix &result, int diag,
                           int rank);
void elim_rows_extended_bt(S21Matrix &matrix, S21Matrix &result, int rank);