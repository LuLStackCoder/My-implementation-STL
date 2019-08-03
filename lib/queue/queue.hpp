#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>

namespace lib {
// INTERFACE

template <typename T>
class Node {
public:
    Node(T data, Node* ptr);
    T item;
    Node* next;
};

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();
    void push(T data);
    T pop();
    T& front();
    T& back();
    size_t size();
    bool empty();
    void swap(Queue<T>& other);

private:
    Node<T> head;
    Node<T> tail;
    size_t queue_size;
};

}  // namespace lib

// CONSTRUCTORS

template <typename T>
lib::Node<T>::Node(T data, Node* ptr) {
    item = data;
    next = ptr;
}

template <typename T>
lib::Queue<T>::Queue() {
    queue_size = 0;
    head = nullptr;
    tail = nullptr;
}

#endif