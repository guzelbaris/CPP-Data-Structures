#include "Matrix.h"
#include <fstream>

Matrix::Matrix() : n_(0) {}
Matrix::Matrix(int n) : n_(n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      data_[i][j] = (i == j) ? 1 : 0;
    }
  }
}

void Matrix::fillFromFile(const string& filename) {
    ifstream input_file; /* input file stream */
    input_file.open(filename);

    for(int i=0; i<n_; i++){
        for(int j=0; j<n_; j++){
            input_file >> data_[i][j];
        }
    }

    input_file.close();
}

void Matrix::display() const {
  for (int i = 0; i < n_; i++) {
    for (int j = 0; j < n_; j++) {
      std::cout << data_[i][j] << "\t";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}


Matrix& Matrix::operator=(const Matrix& other) {
  if (this != &other) {
    n_ = other.n_;
    for (int i = 0; i < n_; ++i) {
      for (int j = 0; j < n_; ++j) {
        data_[i][j] = other.data_[i][j];
      }
    }
  }
  return *this;
}

int Matrix::get(int row, int col) const {
  return data_[row][col];
}

void Matrix::set(int row, int col, int value) {
  data_[row][col] = value;
}

bool Matrix::operator==(const Matrix& other) const {
  if (n_ != other.n_) {
    return false;
  }
  for (int i = 0; i < n_; ++i) {
    for (int j = 0; j < n_; ++j) {
      if (data_[i][j] != other.data_[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool Matrix::operator<(const Matrix& other) const {
  if (n_ < other.n_) {
    return true;
  } else if (n_ > other.n_) {
    return false;
  }

  for (int i = 0; i < n_; ++i) {
    for (int j = 0; j < n_; ++j) {
      if (data_[i][j] < other.data_[i][j]) {
        return true;
      } else if (data_[i][j] > other.data_[i][j]) {
        return false;
      }
    }
  }

  return false;
}

std::size_t Matrix::hash() const {
  std::size_t h = 0;
  for (int i = 0; i < n_; ++i) {
    for (int j = 0; j < n_; ++j) {
      h = h * 31 + data_[i][j];
    }
  }
  return h;
}
