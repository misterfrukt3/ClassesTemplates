#include <iostream>
#include <cstring>
#include "mymath/mymath.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout<<"Вот произведение: "<<std::endl;
    std::cout<< mymath::Func(5, 7)<<std::endl;
    return 0;
}
