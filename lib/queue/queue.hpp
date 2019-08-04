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
    // void swap(Queue<T>& other);

public:
    Node<T>* head;
    Node<T>* tail;
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

// DESTRUCTOR

template <typename T>
lib::Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

// METHODS

template <typename T>
void lib::Queue<T>::push(T data) {
    Node<T> *temp = new Node<T>(data, nullptr);
    if (empty()) {
        tail = temp;
        head = tail;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    queue_size++;
}

template <typename T>
T lib::Queue<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Pop from empty queue");
    }
    T popped_item = head->item;
    Node<T>* temp = head->next;
    delete head;
    head = temp;
    queue_size--;
    return popped_item;
}

template <typename T>
size_t lib::Queue<T>::size() {
    return queue_size;
}

template <typename T>
bool lib::Queue<T>::empty() {
    if (!queue_size && !head) return true;
    else return false;
}

template <typename T>
T& lib::Queue<T>::front() {
    if (empty()) {
        throw std::out_of_range("Access to the front element of empty queue");
    }
    return head->item;
}

template <typename T>
T& lib::Queue<T>::back() {
        if (empty()) {
        throw std::out_of_range("Access to the back element of empty queue");
    }
    return tail->item;
}

#endif