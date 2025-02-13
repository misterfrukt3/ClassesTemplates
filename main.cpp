#include <iostream>
#include "mymath/mymath.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout<<"Вот произведение: "<<std::endl;
    std::cout<< mymath::Sum(5, 7)<<std::endl;
    return 0;
}
