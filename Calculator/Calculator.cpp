#include <iostream>
#include <map>
#include <functional>
#include <math.h>

std::string state {"Idle"};
std::string op;
double a, b, result;

const std::map<std::string, std::function<double(double, double)>> opFuncs = {
  {
    "+", [](double a, double b){
      return a + b;
    }
  },
  {
    "-", [](double a, double b){
      return a - b;
    }
  },
  {
    "/", [](double a, double b){
      return a / b;
    }
  },
  {
    "*", [](double a, double b){
      return a * b;
    }
  },
  {
    "pow", [](double a, double b){
      return pow(a, b);
    }
  },
};
const std::map<std::string, std::function<void()>> stateFunctions = {
  {
    "Idle", [](){
      std::cout << "(Enter an operator: [+, -, /, *, pow]) ";
      std::cin >> op;
      std::cout << "Enter two values" << std::endl;
      std::cin >> a;
      std::cin >> b;

      state = "Operate";
      stateFunctions.at(state)();
    },
  },
  {
    "Operate", [](){
      result = opFuncs.at(op)(a, b);

      std::cout << "Result: " << result << std::endl;

      state = "Idle";
      stateFunctions.at(state)();
    }
  }
};

int main(){
  stateFunctions.at(state)();

  return 0;
}