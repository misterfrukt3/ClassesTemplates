#include "stack.h"
#include <iostream>
#include <string>

int main() {
    Stack<std::string> s;

    s.push("первый");
    s.push("второй");
    s.push("третий");

    s.display();

    std::cout << "Верх: " << s.top() << std::endl;
    s.pop();
    s.display();

    std::cout << "Размер: " << s.size() << std::endl;
    std::cout << "Пустой? " << (s.isEmpty() ? "Да" : "Нет") << std::endl;

    return 0;
}
