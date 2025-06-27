#include <iostream>
#include <optional>

#include "Vector.hpp"
#include "Matrix.hpp"

int main(){
  Vector newV = Vector({5.5, 2.3, 1.4});
  std::cout << newV.tellMe() << std::endl;
  Vector anotherV = Vector({2.8, 3.0, 1.7});
  std::cout << anotherV.tellMe() << std::endl;

  std::optional<Vector> sum = newV.add(anotherV);
  if (sum.has_value()){
    Vector vSum = sum.value();

    std::cout << "added the 2:\n" << vSum.tellMe() << std::endl;
    vSum.mult(3);
    std::cout << vSum.tellMe() << "\n" << vSum.magnitude() << std::endl;
    std::cout << "unit vector of sum:\n" << vSum.toString(vSum.unit()) << std::endl;
  }else{
    sum = std::nullopt;
  }

  std::optional<double> dotProduct = newV.dot(anotherV.getData());

  std::cout << "dot product of anotherV and newV:\n" << ((dotProduct.has_value()) ? std::to_string(dotProduct.value()) : "NULL") << std::endl;
  

  Matrix newM = Matrix({Vector({23, 3, 5}), Vector({5, 2, 7})});
  Matrix anotherM = Matrix({Vector({23, 3, 5}), Vector({5, 2, 7})});
  std::optional<Matrix> mSum = newM.add(anotherM);
  std::cout << "\n" << newM.tellMe() << std::endl;
  std::cout << anotherM.tellMe() << std::endl;

  std::cout << "sum status: " << ((mSum.has_value())? "SUCCESS" : "FAIL") << std::endl;

  if (mSum.has_value()){
    std::cout << "sum:\n" << mSum.value().tellMe() << std::endl;
  }

  Vector v = Vector({4, 5, 6});
  std::optional<Matrix> mVProduct = newM.multVector(v);
  if (mVProduct.has_value()){
    std::cout << mVProduct.value().tellMe() << std::endl;
  }else{
    std::cout << "nothing" << std::endl;
  }

  Matrix m1 = Matrix({
    Vector({0, 3, 5}),
    Vector({5, 5, 2})
  });
  Matrix m2 = Matrix({
    Vector({3, 4}),
    Vector({3, -2}),
    Vector({4, -2}),
  });

  std::optional<Matrix> mMult = m1.multMatrix(m2);
  if (mMult.has_value()){
    std::cout << mMult.value().tellMe() << std::endl;
  }

  return 0;
}