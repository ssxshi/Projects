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
    Matrix();

    std::optional<double> valueAt(int row, int col);
    void setValue(int row, int col, double val);
    std::string tellMe();
    int getRows();
    int getCols();
    std::vector<Vector> getData();

    std::optional<Matrix> add(Matrix other);
    std::optional<Matrix> subtract(Matrix other);
    void scale(double scalar);
    std::optional<Matrix> multVector(Vector v);
    std::optional<Matrix> multMatrix(Matrix m);
};

#endif