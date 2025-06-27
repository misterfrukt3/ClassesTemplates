#include <stdexcept>

template<typename T>
Stack<T>::Stack() {}

template<typename T>
void Stack<T>::push(const T& value) {
    elements.push_back(value);
}

template<typename T>
void Stack<T>::pop() {
    if (elements.empty()) {
        throw std::underflow_error("Стек пуст, нельзя удалить элемент.");
    }
    elements.pop_back();
}

template<typename T>
T& Stack<T>::top() {
    if (elements.empty()) {
        throw std::underflow_error("Стек пуст, верхнего элемента нет.");
    }
    return elements.back();
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return elements.empty();
}

template<typename T>
size_t Stack<T>::size() const {
    return elements.size();
}

template<typename T>
void Stack<T>::display() const {
    std::cout << "Стек: ";
    for (const T& el : elements) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}
