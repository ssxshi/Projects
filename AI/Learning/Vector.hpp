#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <vector>
#include <iostream>
#include <optional>

class Vector{
  private:
    std::vector<double> data;
    int size;

    static bool isBigger(std::vector<double> first, std::vector<double> second);
    static std::vector<double> lengthen(std::vector<double> toChange, int length);

  public:
    Vector(std::vector<double> initList);
    Vector(int initSize);
    Vector();

    static std::string toString(std::vector<double> toPrint);

    std::optional<Vector> add(Vector addWith);
    std::optional<Vector> subtract(Vector subWith);
    void mult(double scalar);
    void setValue(int pos, double val);
    std::optional<double> dot(Vector dotWith);

    std::string tellMe();
    std::vector<double> getData();
    int getSize();
    double magnitude();
    std::vector<double> unit();
    std::optional<double> valueAt(int index);
};

#endif