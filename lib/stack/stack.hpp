#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>

namespace lib {
template <typename T>
class Node {
    public:
        Node(T data, Node* ptr);
        T item;
        Node* next;
};

template<typename T>
class Stack {
    public:
        Stack();
        void push(T value);
        T pop();
        size_t size();
        T& top();
        bool empty();
        void swap(Stack& other);
    private:
        size_t stack_size;
        Node<T>* head;
};

// CONSTRUCTORS

template <typename T>
Node<T>::Node(T data, Node<T>* ptr) {
    item = data;
    next = ptr;
}

template <typename T>
Stack<T>::Stack() {
    stack_size = 0;
    head = nullptr;
}

// METHODS

template <typename T>
void Stack<T>::push(T data) {
    head = new Node<T>(data, head);
    if (!head)
        return ;
    stack_size++;
}

template <typename T>
size_t Stack<T>::size() {
    return stack_size;
}

template <typename T>
bool Stack<T>::empty() {
    if (stack_size == 0 && head == nullptr) {
        return true;
    }
    return false;
}

template <typename T>
T Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Pop from empty stack");
    }
    Node<T> *temp = head->next;
    T popped_data = head->item;
    delete (head);
    head = temp;
    stack_size--;
    return popped_data;
}

template <typename T>
T& Stack<T>::top() {
    if (empty()) {
        throw std::out_of_range("Return reference to the top element from empty stack");
    }
    return head->item;
}

template <typename T>
void Stack<T>::swap(Stack<T>& other) {
    Stack<T> temp;
    while (!empty()) {
        temp.push(pop());
    }
    while (!other.empty()) {
        push(other.pop());
    }
    other = temp;
}
}

#endif