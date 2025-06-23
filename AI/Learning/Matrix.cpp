#include <iostream>
#include <vector>
#include <optional>

#include "Matrix.hpp"

const double DEFAULT_VALUE = 0.0;

// STATICS
static bool inBounds(std::vector<Vector> data, int row, int col){
  if (row < 0 || row >= data.size()){
    std::cout << "INDEX OUT OF BOUNDS!!" << std::endl;
    return false;
  }
  if (col < 0 || col >= data[row].getSize()){
    std::cout << "INDEX OUT OF BOUNDS!!" << std::endl;
    return false;
  }
  return true;
}
static std::string toString(std::vector<Vector> toPrint){
  std::string toReturn = "";
  for (Vector vec : toPrint){
    toReturn += vec.tellMe() + "\n";
  }
  return toReturn;
}

// CONSTRUCTORS
Matrix::Matrix(std::vector<Vector> data){
  this->data = data;
  this->rows = data.size();
  this->cols = data[0].getSize();
}
Matrix::Matrix(int rows, int cols){
  this->rows = rows;
  this->cols = cols;
  this->data.resize(rows);
  for (int i = 0; i < rows; i++){
    this->data[i] = Vector(cols);
  }
}

// GETTERS
std::optional<double> Matrix::valueAt(int row, int col){
  if (not inBounds(this->data, row, col)){return std::nullopt;}

  return this->data[row].getData()[col];
}
std::string Matrix::tellMe(){
  return toString(this->data);
}