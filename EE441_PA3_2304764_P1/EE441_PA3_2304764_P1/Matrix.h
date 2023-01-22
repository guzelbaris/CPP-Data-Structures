#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "math.h"

using namespace std;

class Matrix {
 public:
  // constructors
  Matrix();
  Matrix(int n);
  // copy assignment operator
  void display() const;
  Matrix& operator=(const Matrix& other);
  // getter and setter
  int get(int row, int col) const;
  void set(int row, int col, int value);
  void fillFromFile(const string& filename);
  // comparison operators
  bool operator==(const Matrix& other) const;
  bool operator<(const Matrix& other) const;

  // hash function
  std::size_t hash() const;

  int n_;
  int data_[20][20];
};

#endif
