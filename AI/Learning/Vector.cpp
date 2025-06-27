#include <iostream>
#include <vector>
#include <math.h>
#include <optional>

#include "Vector.hpp"

const double DEFAULT_VALUE = 0.0;

// CONSTRUCTORS
Vector::Vector(std::vector<double> initList)
{
  this->data = initList;
  this->size = initList.size();
}

Vector::Vector(int initSize)
{
  this->size = initSize;
  this->data.resize(initSize, DEFAULT_VALUE);
}
Vector::Vector()
{
  this->size = 0;
  this->data = {};
}

// STATIC
std::string Vector::toString(std::vector<double> toPrint)
{
  std::string toReturn = "{";
  for (size_t i = 0; i < toPrint.size(); ++i)
  {
    toReturn += " " + std::to_string(toPrint[i]);
  }
  toReturn += " }";
  return toReturn;
}

bool sizeEqual(std::vector<double> first, std::vector<double> second){
  if (first.size() != second.size())
  {
    std::cout << "VECTOR SIZES DON'T MATCH!" << std::endl;
    return false;
  }
  return true;
}

// ARITHMETIC
std::optional<Vector> Vector::add(Vector addWith)
{
  if (not sizeEqual(this->data, addWith.getData())){return std::nullopt;}
  Vector sum = Vector(this->data.size());

  for (size_t i = 0; i < this->data.size(); i++)
  {
    sum.data[i] = this->data[i] + addWith.getData()[i];
  }

  return sum;
}
std::optional<Vector> Vector::subtract(Vector subWaith){
  if (not sizeEqual(this->data, subWaith.getData())){return std::nullopt;}
  Vector diff = Vector(this->data.size());

  for (size_t i = 0; i < this->data.size(); i++)
  {
    diff.data[i] = this->data[i] - subWaith.getData()[i];
  }

  return diff;
}
void Vector::mult(double scalar)
{
  for (int i = 0; i < this->data.size(); i++)
  {
    this->data[i] *= scalar;
  }
}
std::optional<double> Vector::dot(Vector dotWith)
{
  if (not sizeEqual(this->data, dotWith.getData())){return std::nullopt; }

  double sum = 0.0;
  for (int i = 0; i < this->getSize(); i++)
  {
    sum += (this->getData()[i] * dotWith.getData()[i]);
  }

  return sum;
}
std::vector<double> Vector::unit()
{
  std::vector<double> unitV = {};
  unitV.resize(this->data.size(), DEFAULT_VALUE);
  int magnitude = this->magnitude();

  for (int i = 0; i < this->data.size(); i++)
  {
    unitV[i] = this->getData()[i] / magnitude;
  }

  return unitV;
}

// GETTERS
std::vector<double> Vector::getData()
{
  return this->data;
}
int Vector::getSize()
{
  return this->data.size();
}
double Vector::magnitude()
{
  double sum = 0.0;
  for (double val : this->data)
  {
    sum += pow(val, 2);
  }

  return sqrt(sum);
}
std::optional<double> Vector::valueAt(int index){
  if (index < 0 || index >= this->data.size()){
    std::cout << "INDEX OUT OF BOUNDS!!" << std::endl;
    return std::nullopt;
  }

  return this->data[index];
}

std::string Vector::tellMe()
{
  return toString(this->data);
}

//SETTERS
void Vector::setValue(int pos, double value){
  this->data[pos] = value;
}