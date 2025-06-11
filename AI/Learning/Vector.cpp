#include <iostream>
#include <vector>
#include <math.h>
#include <optional>

#include "Vector.hpp"

const double DEFAULT_VALUE = 0.0;

// CONSTRUCTORS
Vector::Vector(std::vector<double> initList) {
    this->data = initList;
    this->size = initList.size();
}

Vector::Vector(int initSize) {
    this->size = initSize;
    this->data.resize(initSize, DEFAULT_VALUE);
}

// METHODS

// STATIC
bool Vector::isBigger(std::vector<double> first, std::vector<double> second) {
    return first.size() > second.size();
}
std::vector<double> Vector::lengthen(std::vector<double> toChange, int length) {
    toChange.resize(length, DEFAULT_VALUE);
    return toChange;
}
std::string Vector::toString(std::vector<double> toPrint){
  std::string toReturn = "{";
    for (size_t i = 0; i < toPrint.size(); ++i) {
        toReturn += " " + std::to_string(toPrint[i]);
    }
    toReturn += " }";
    return toReturn;
}


// OBJECT

// ARITHMETIC
Vector Vector::add(std::vector<double> addWith) {
    std::vector<double> ours;
    Vector sum = Vector(0);

    if (isBigger(this->data, addWith)) {
        addWith = lengthen(addWith, this->data.size());
        ours = this->data;
    } else {
        ours = lengthen(this->data, addWith.size());
    }

    sum.data.resize(ours.size());
    for (size_t i = 0; i < ours.size(); ++i) {
        sum.data[i] = ours[i] + addWith[i];
    }

    return sum;
}
void Vector::mult(double scalar){
  for (int i = 0; i < this->data.size(); i++){
    this->data[i] *= scalar;
  }
}
std::optional<double> Vector::dot(std::vector<double> dotWith){
  if (this->getSize() != dotWith.size()){
    std::cout << "VECTOR SIZES DON'T MATCH!" << std::endl;
    return std::nullopt;
  }

  double sum = 0.0;
  for (int i = 0; i < this->getSize(); i++){
    sum += (this->getData()[i] * dotWith[i]);
  }

  return sum;
}

//GETTERS
std::vector<double> Vector::getData() {
    return this->data;
}
int Vector::getSize() {
    return this->data.size();
}
double Vector::magnitude(){
  double sum = 0.0;
  for (double val:this->data){
    sum += pow(val, 2);
  }

  return sqrt(sum);
}
std::vector<double> Vector::unit(){
  std::vector<double> unitV = {};
  unitV.resize(this->data.size(), DEFAULT_VALUE);
  int magnitude = this->magnitude();

  for(int i = 0; i < this->data.size(); i++){
    unitV[i] = this->getData()[i] / magnitude;
  }

  return unitV;
}

std::string Vector::tellMe() {
    return toString(this->data);
}