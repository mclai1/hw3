#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

using namespace std;

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

// constructor
template <typename T>
Stack<T>::Stack(){

}

// destructor
template <typename T>
Stack<T>::~Stack() {
    vector<T>::clear();
}

// return if the stack is empty
template <typename T>
bool Stack<T>::empty() const {
    return vector<T>::empty();
}

// return the size of the stack
template <typename T>
size_t Stack<T>::size() const {
    return vector<T>::size();
}

// push an item to the stack
template <typename T>
void Stack<T>::push(const T& item) {
    vector<T>::push_back(item);
}

// pop an item from the stack
template <typename T>
void Stack<T>::pop() {
    if (empty()){
        throw std::underflow_error("Stack is empty");
    }
    vector<T>::pop_back();
}

// return the top item of the stack
template <typename T>
const T& Stack<T>::top() const {
    if (empty()){
        throw std::underflow_error("Stack is empty");
    }
    return vector<T>::back();
}

#endif