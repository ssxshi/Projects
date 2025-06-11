#include <iostream>
#include <optional>

#include "Vector.hpp"

int main(){
  Vector newV = Vector({5.5, 2.3, 1.4});
  std::cout << newV.tellMe() << std::endl;
  Vector anotherV = Vector({2.8, 3.0, 1.7});
  std::cout << anotherV.tellMe() << std::endl;

  Vector sum = newV.add(anotherV.getData());

  std::cout << "added the 2:\n" << sum.tellMe() << std::endl;
  sum.mult(3);
  std::cout << sum.tellMe() << "\n" << sum.magnitude() << std::endl;
  std::cout << "unit vector of sum:\n" << sum.toString(sum.unit()) << std::endl;

  std::optional<double> dotProduct = newV.dot(anotherV.getData());

  std::cout << "dot product of anotherV and newV:\n" << ((dotProduct.has_value()) ? std::to_string(dotProduct.value()) : "NULL") << std::endl;
  return 0;
}