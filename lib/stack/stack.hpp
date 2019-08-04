#ifndef STACK_HPP
#define STACK_HPP

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
class Stack {
public:
    Stack();
    ~Stack();
    void push(T data);
    T pop();
    size_t size();
    T& top();
    bool empty();
    void reverse();
    void swap(Stack& other);
    Stack<T>& operator=(Stack<T>& other);
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, Stack<U>& queue);

private:
    size_t stack_size;
    Node<T>* head;
};

}  // namespace lib
// CONSTRUCTORS

template <typename T>
lib::Node<T>::Node(T data, Node<T>* ptr) {
    item = data;
    next = ptr;
}

template <typename T>
lib::Stack<T>::Stack() {
    stack_size = 0;
    head = nullptr;
}

// DESTRUCTOR
template <typename T>
lib::Stack<T>::~Stack() {
    while (!empty()) {
        pop();
    }
}

// METHODS

template <typename T>
void lib::Stack<T>::push(T data) {
    head = new Node<T>(data, head);
    if (!head) return;
    stack_size++;
}

template <typename T>
size_t lib::Stack<T>::size() {
    return stack_size;
}

template <typename T>
bool lib::Stack<T>::empty() {
    if (!stack_size && !head)
        return true;
    else
        return false;
}

template <typename T>
T lib::Stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Pop from empty stack");
    }
    Node<T>* temp = head->next;
    T popped_item = head->item;
    delete head;
    head = temp;
    stack_size--;
    return popped_item;
}

template <typename T>
T& lib::Stack<T>::top() {
    if (empty()) {
        throw std::out_of_range("Access to the top element of empty stack");
    }
    return head->item;
}

template <typename T>
lib::Stack<T>& lib::Stack<T>::operator=(lib::Stack<T>& other) {
    while (!empty()) {
        pop();
    }
    for (Node<T>* temp = other.head; temp; temp = temp->next) {
        push(temp->item);
    }
    reverse();
    return *this;
}

namespace lib {
template <typename T>
std::ostream& operator<<(std::ostream& out, lib::Stack<T>& stack) {
    out << "[";
    for (lib::Node<T>* temp = stack.head; temp; temp = temp->next) {
        out << temp->item;
        if (temp->next) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}
}  // namespace for friend function

template <typename T>
void lib::Stack<T>::reverse() {
    Node<T>* curr = head;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template <typename T>
void lib::Stack<T>::swap(Stack<T>& other) {
    if (empty() && other.empty()) {
        return;
    }
    T temp1;
    T temp2;
    bool flag1 = 0;
    bool flag2 = 0;
    if (!empty()) {
        temp1 = pop();
        flag1 = 1;
    }
    if (!other.empty()) {
        temp2 = other.pop();
        flag2 = 1;
    }
    swap(other);
    if (flag2 == 1) push(temp2);
    if (flag1 == 1) other.push(temp1);
}

#endif