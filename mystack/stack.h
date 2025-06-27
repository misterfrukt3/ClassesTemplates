#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

template<typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    Stack();

    void push(const T& value);
    void pop();
    T& top();
    bool isEmpty() const;
    size_t size() const;
    void display() const;
};

#include "stack.cpp"

#endif
