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
  rows = (rows >= 0)? rows : 0;
  cols = (cols >= 0)? cols : 0;

  this->rows = rows;
  this->cols = cols;
  this->data.resize(rows);
  for (int i = 0; i < rows; i++){
    this->data[i] = Vector(cols);
  }
}
Matrix::Matrix(){
  this->rows = 0;
  this->cols = 0;
  this->data.resize(0);
}

//OPERATIONS
std::optional<Matrix> Matrix::add(Matrix other){
  std::cout << this->rows << other.getRows() << " " << this->cols << other.getCols() << std::endl;
  if (this->rows != other.getRows() || this->cols != other.getCols())
  {return std::nullopt;}

  Matrix sum = Matrix(this->rows, this->cols);

  for (int r = 0; r < this->rows; r++){
    for (int c = 0; c < this->cols; c++){
      sum.setValue(r, c, this->data[r].getData()[c] + other.getData()[r].getData()[c]);
    }
  }

  return sum;
}
std::optional<Matrix> Matrix::subtract(Matrix other){
  std::cout << this->rows << other.getRows() << " " << this->cols << other.getCols() << std::endl;
  if (this->rows != other.getRows() || this->cols != other.getCols())
  {return std::nullopt;}

  Matrix sum = Matrix(this->rows, this->cols);

  for (int r = 0; r < this->rows; r++){
    for (int c = 0; c < this->cols; c++){
      sum.setValue(r, c, this->data[r].getData()[c] - other.getData()[r].getData()[c]);
    }
  }

  return sum;
}
void Matrix::scale(double scalar){
  for (Vector v : this->data){
    for (double d : v.getData()){
      d *= scalar;
    }
  }
}
std::optional<Matrix> Matrix::multVector(Vector v){
  if (this->cols != v.getSize()){return std::nullopt;}

  std::cout << this->tellMe() << "\n" << v.tellMe() << std::endl;

  Matrix product = Matrix(this->rows, 1);
  for (int i = 0; i < this->rows; i++){
    double currSum = 0.0;
    for (int j = 0; j < this->cols; j++){
      currSum += this->data[i].getData()[j] * v.getData()[j];
    }
    product.setValue(i, 0, currSum);
  }

  return product;
}
std::optional<Matrix> Matrix::multMatrix(Matrix m){
  if (this->cols != m.getRows()){return std::nullopt;}

  Matrix product = Matrix(this->rows, m.getCols());
  for (int i = 0; i < this->rows; i++){
    for (int j = 0; j < m.getCols(); j++){
      double currSum = 0.0;
      for (int k = 0; k < this->cols; k++){
        currSum += this->data[i].getData()[k] * m.getData()[k].getData()[j];
      }
      product.setValue(i, j, currSum);
    }
  }

  return product;
}

// GETTERS
std::optional<double> Matrix::valueAt(int row, int col){
  if (not inBounds(this->data, row, col)){return std::nullopt;}

  return this->data[row].getData()[col];
}
std::string Matrix::tellMe(){
  return toString(this->data);
}
int Matrix::getCols(){
  return this->cols;
}
int Matrix::getRows(){
  return this->rows;
}
std::vector<Vector> Matrix::getData(){
  return this->data;
}

//SETTERS
void Matrix::setValue(int row, int col, double val){
  this->data[row].setValue(col, val);
}