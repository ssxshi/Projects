#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <optional>

#include "Vector.hpp"

class Matrix{
  private:
    std::vector<Vector> data;
    int rows;
    int cols;

  public:
    Matrix(std::vector<Vector> data);
    Matrix(int rows, int cols);

    std::optional<double> valueAt(int row, int col);
    std::string tellMe();
};

#endif