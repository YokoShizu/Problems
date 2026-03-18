#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  bool result{true};
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j)
        if (dabs(matrix_[i][j] - other.matrix_[i][j]) > EPS) {
          result = false;
          break;
        }
      if (result == false) break;
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument(
        "The matrices have different numbers of rows or columns");
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] += other.matrix_[i][j];
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument(
        "The matrices have different numbers of rows or columns");
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] -= other.matrix_[i][j];
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] *= num;
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_)
    throw std::invalid_argument(
        "The columns number of the first matrix and the rows number of the "
        "second matrix are not the same.");

  double **result{new double *[rows_]};
  for (int i = 0; i < rows_; ++i) result[i] = new double[other.cols_]{0};

  for (int i = 0; i < rows_; ++i) {
    double *result_ptr = result[i];

    for (int k = 0; k < other.rows_; ++k) {
      const double *other_ptr = other.matrix_[k];

      for (int j = 0; j < other.cols_; ++j)
        result_ptr[j] += matrix_[i][k] * other_ptr[j];
    }
  }

  this->Mutator(rows_, other.cols_);

  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < other.cols_; ++j) matrix_[i][j] = result[i][j];

  for (int i = 0; i < rows_; ++i) delete[] result[i];
  delete[] result;
}

S21Matrix& S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    this->Mutator(other.rows_, other.cols_);
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j) matrix_[i][j] = other.matrix_[i][j];
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix &&other) {
  if (this != &other) {
    for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
    delete[] matrix_;

    matrix_ = other.matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;

    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix &other) { SumMatrix(other); return *this;}

S21Matrix& S21Matrix::operator-=(const S21Matrix &other) { SubMatrix(other); return *this;}

S21Matrix& S21Matrix::operator*=(const double num) { MulNumber(num); return *this;}

S21Matrix& S21Matrix::operator*=(const S21Matrix &other) { MulMatrix(other); return *this;}

double &S21Matrix::operator()(int i, int j) {
  if (i >= rows_ || j >= cols_)
    throw std::out_of_range("The index of element is out of range.");
  return matrix_[i][j];
}

const double &S21Matrix::operator()(int i, int j) const {
  if (i >= rows_ || j >= cols_)
    throw std::out_of_range("The index of element is out of range.");
  return matrix_[i][j];
}

S21Matrix operator+(const S21Matrix &other1, const S21Matrix &other2) {
  S21Matrix result(other1);
  result.SumMatrix(other2);
  return result;
}

S21Matrix operator-(const S21Matrix &other1, const S21Matrix &other2) {
  S21Matrix result(other1);
  result.SubMatrix(other2);
  return result;
}

S21Matrix operator*(const S21Matrix &other1, const S21Matrix &other2) {
  S21Matrix result(other1);
  result.MulMatrix(other2);
  return result;
}

S21Matrix operator*(const S21Matrix &other, const double num) {
  S21Matrix result(other);
  result.MulNumber(num);
  return result;
}

S21Matrix operator*(const double num, const S21Matrix &other) {
  S21Matrix result(other);
  result.MulNumber(num);
  return result;
}

bool operator==(const S21Matrix &other1, const S21Matrix &other2) {
  return other1.EqMatrix(other2);
}

S21Matrix Transpose(const S21Matrix &other) {
  int M = other.AccessorRows(), N = other.AccessorCols();

  S21Matrix result(N, M);
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) result(i, j) = other(j, i);
  return result;
}

S21Matrix CalcComplements(const S21Matrix &other) {
  if (other.AccessorRows() != other.AccessorCols())
    throw std::invalid_argument("The matrix is not square.");
  S21Matrix result(Transpose(Determinant(other) * InverseMatrix(other)));
  return result;
}

double Determinant(const S21Matrix &other) {
  int N = other.AccessorRows(), M = other.AccessorCols();

  if (N != M) throw std::invalid_argument("The matrix is not square.");

  double det{other(0, 0)};
  S21Matrix copy(other);

  if (N > 1) {
    det = 1.0;
    for (int j = 0; j < N - 1; ++j) {
      int pivot_index{j};
      double pivot{copy(j, j)};
      find_pivot(copy, j, pivot, pivot_index, N);

      if (dabs(pivot) < EPS) {
        det = 0.0;
        break;
      }

      if (pivot_index != j) {
        det *= -1;
        swap_rows(copy, j, pivot_index, N);
      }

      det *= pivot;
      elim_rows_top_down(copy, j, N);
    }

    det *= copy(N - 1, N - 1);
  }
  return det;
}

S21Matrix InverseMatrix(const S21Matrix &other) {
  if (dabs(Determinant(other)) < EPS)
    throw std::invalid_argument("The determinant is 0.");

  int N = other.AccessorRows();
  S21Matrix copy(other), result(N, N);

  result(0, 0) = 1.0 / Determinant(other);

  if (N > 1) {
    for (int i = 0; i < N; ++i) result(i, i) = 1.0;

    for (int j = 0; j < N - 1; ++j) {
      int pivot_index{j};
      double pivot{copy(j, j)};
      find_pivot(copy, j, pivot, pivot_index, N);

      if (pivot_index != j) {
        swap_rows(copy, j, pivot_index, N);
        swap_rows(result, j, pivot_index, N);
      }

      elim_rows_extended_td(copy, result, j, N);
    }

    elim_rows_extended_bt(copy, result, N);
  }

  return result;
}

// Additional

double dabs(const double &a) {
  double result{a};
  if (a < 0) result *= -1.0;
  return result;
}

void find_pivot(const S21Matrix &matrix, int diag, double &pivot,
                int &pivot_index, int rank) {
  for (int i = diag + 1; i < rank; ++i)
    if (dabs(matrix(i, diag)) - dabs(pivot) > EPS) {
      pivot = matrix(i, diag);
      pivot_index = i;
    }
}

void swap_rows(S21Matrix &matrix, int diag, int pivot_index, int rank) {
  double temp{};
  for (int i = 0; i < rank; ++i) {
    temp = matrix(diag, i);
    matrix(diag, i) = matrix(pivot_index, i);
    matrix(pivot_index, i) = temp;
  }
}

void elim_rows_top_down(S21Matrix &matrix, int diag, int rank) {
  for (int i = diag + 1; i < rank; ++i)
    if (dabs(matrix(i, diag)) > EPS) {
      double del = matrix(i, diag) / matrix(diag, diag);
      for (int k = diag; k < rank; ++k) matrix(i, k) -= del * matrix(diag, k);
    }
}

void elim_rows_extended_td(S21Matrix &matrix, S21Matrix &result, int diag,
                           int rank) {
  for (int i = diag + 1; i < rank; ++i)
    if (dabs(matrix(i, diag)) > EPS) {
      double del = matrix(i, diag) / matrix(diag, diag);
      for (int k = 0; k < rank; ++k) {
        matrix(i, k) -= del * matrix(diag, k);
        result(i, k) -= del * result(diag, k);
      }
    }
}

void elim_rows_extended_bt(S21Matrix &matrix, S21Matrix &result, int rank) {
  for (int i = rank - 1; i > 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      double del = matrix(j, i) / matrix(i, i);
      for (int k = 0; k < rank; ++k) result(j, k) -= del * result(i, k);
      matrix(j, i) = 0.0;
    }
    for (int k = 0; k < rank; ++k) result(i, k) /= matrix(i, i);
    matrix(i, i) = 1.0;
  }
  for (int i = 0; i < rank; ++i) result(0, i) /= matrix(0, 0);
}