#include "mymath/mymath.h"
#include "myCalculate/myCalculate.h"
#include <iomanip>
#include <iostream>

namespace {
enum class OperationChoose {
  Summ = 1,
  Derivation = 2,
  Difference = 3,
  Partial = 4,
};

}
void OperationRelease(int operationType) {
  switch (static_cast<OperationChoose>(operationType)) {
  case OperationChoose::Summ:
    std::cout << "Вот Сумма: " << std::endl;
    std::cout << myCalculate::Sum(10, 2) << std::endl;
    break;
  case OperationChoose::Derivation:
    std::cout << "Вот произведение: " << std::endl;
    std::cout << myCalculate::Deriv(10, 2) << std::endl;
    break;
  case OperationChoose::Difference:
    std::cout << "Вот Разность: " << std::endl;
    std::cout << myCalculate::Diff(10, 2) << std::endl;
    break;
  case OperationChoose::Partial:
    std::cout << "Вот Частное: " << std::endl;
    std::cout << myCalculate::Del(10, 2) << std::endl;
    break;
  default:
    std::cout << "Введен неверный номер Типа операции." << std::endl;
    break;
  }
}
void SelectOperationType() {
  int operationType = 0;
  std::cout << "Выберите тип операции, над числами: \n";
  std::cout << "[1] Сумма" << std::setw(30) << "[3] Разность\n";
  std::cout << "[2] Произведение" << std::setw(20) << "[4] Частное"
            << std::endl;
  std::cin >> operationType;
  OperationRelease(operationType);
}

int main() {
  SelectOperationType();
  return 0;
}
