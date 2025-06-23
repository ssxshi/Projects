#include <iostream>
#include <optional>

#include "Vector.hpp"
#include "Matrix.hpp"

int main(){
  Vector newV = Vector({5.5, 2.3, 1.4});
  std::cout << newV.tellMe() << std::endl;
  Vector anotherV = Vector({2.8, 3.0, 1.7});
  std::cout << anotherV.tellMe() << std::endl;

  /*
  std::optional<Vector> sum = newV.add(anotherV.getData());
  sum = (sum.has_value()) ? sum.value() : NULL;
  if (sum.has_value()){
    Vector vSum = sum.value();

    std::cout << "added the 2:\n" << vSum.tellMe() << std::endl;
    vSum.mult(3);
    std::cout << vSum.tellMe() << "\n" << vSum.magnitude() << std::endl;
    std::cout << "unit vector of sum:\n" << vSum.toString(vSum.unit()) << std::endl;
  }

  std::optional<double> dotProduct = newV.dot(anotherV.getData());

  std::cout << "dot product of anotherV and newV:\n" << ((dotProduct.has_value()) ? std::to_string(dotProduct.value()) : "NULL") << std::endl;
  */

  //Matrix newM = Matrix(5, 5);
  //std::cout << "\n" << newM.tellMe() << std::endl;
  return 0;
}