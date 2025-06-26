#include "rational/rational.h"
#include <iostream>

void interactiveMode() {
    std::cout << "Введите дробь:\n";
    Rational z;
    try {
        std::cin >> z;
        std::cout << "z=" << z << std::endl;

std::cout << "Проверка конструкторов:"<<std::endl;
        Rational fr1(10, 14), fr2;
        std::cout << "fr2=" << fr2 << std::endl;
        std::cout << "fr1=" << fr1 << std::endl;

        Rational fr = "-1 4/8";
        std::cout << "fr=" << fr << std::endl;

        Rational x(z), y;
        std::cout << "x=" << x << std::endl;

        double dbl = -1.25;
        Rational f = dbl;
        std::cout << "f=" << f << std::endl;

        std::cout << "Проверка перегруженной операции +:"<<std::endl;
        y = x + z;
        std::cout << "y=" << y << std::endl;
        y += x;
        f += dbl / 2;
        std::cout << "f=" << f << std::endl;
        y = x + dbl;
        std::cout << "y=" << y << std::endl;
        y = dbl + y;
        std::cout << "y=" << y << std::endl;
        y += dbl;
        std::cout << "y=" << y << std::endl;

        int i = 5;
        y += i;
        std::cout << "y=" << y << std::endl;
        y = i + x;
        std::cout << "y=" << y << std::endl;
        y = x + i;
        std::cout << "y=" << y << std::endl;
        y += dbl + i + x;
        std::cout << "y=" << y << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}

void demoMode() {
    std::cout << "Проверка конструкторов:"<<std::endl;
    Rational fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;

    Rational fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;

    Rational x(fr), y;
    std::cout << "x=" << x << std::endl;

    double dbl = -1.25;
    Rational f = dbl;
    std::cout << "f=" << f << std::endl;

    std::cout << "Проверка перегруженной операции:"<<std::endl;
    y = x + fr;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;

    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "i") {
        interactiveMode();
    } else {
        demoMode();
    }
    return 0;
}
