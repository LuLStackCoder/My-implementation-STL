#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <stdexcept>

namespace lib {
// INTERFACE
template <typename T>
class Node {
public:
    Node(T data, Node* ptr_next, Node* ptr_prev);
    T item;
    Node<T>* prev;
    Node<T>* next;
};

template <typename T>
class Deque {
public:
    Deque();
    ~Deque();
    void push_back(T data);
    void push_front(T data);
    T pop_back();
    T pop_front();
    bool empty();
    size_t size();
    T& front();
    T& back();
    void swap(Deque<T>& other);
    void reverse();
    Deque<T>& operator=(Deque<T>& other);
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, Deque<U>& deque);

public:
    size_t deque_size;
    Node<T>* head;
    Node<T>* tail;
};

}  // namespace lib

// CONSTRUCTORS
template <typename T>
lib::Node<T>::Node(T data, Node* ptr_next, Node* ptr_prev) {
    item = data;
    next = ptr_next;
    prev = ptr_prev;
}

template <typename T>
lib::Deque<T>::Deque() {
    deque_size = 0;
    head = nullptr;
    tail = nullptr;
}

// DESTRUCTOR
template <typename T>
lib::Deque<T>::~Deque() {
    while (!empty()) {
        pop_back();
    }
}

// METHODS

template <typename T>
bool lib::Deque<T>::empty() {
    return !deque_size;
}

template <typename T>
size_t lib::Deque<T>::size() {
    return deque_size;
}

template <typename T>
lib::Deque<T>& lib::Deque<T>::operator=(Deque<T>& other) {
    while (!empty()) {
        pop_back();
    }
    for (Node<T>* temp = other.head; temp; temp = temp->next) {
        push_back(temp->item);
    }
    return *this;
}

namespace lib {
template <typename T>
std::ostream& operator<<(std::ostream& out, Deque<T>& deque) {
    out << "[";
    for (lib::Node<T>* temp = deque.head; temp; temp = temp->next) {
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
void lib::Deque<T>::push_back(T data) {
    if (empty()) {
        head = tail = new Node<T>(data, head, tail);
    } else {
        tail = new Node<T>(data, nullptr, tail);
        tail->prev->next = tail;
    }
    deque_size++;
}

template <typename T>
void lib::Deque<T>::push_front(T data) {
    if (empty()) {
        tail = head = new Node<T>(data, head, tail);
    } else {
        head = new Node<T>(data, head, nullptr);
        head->next->prev = head;
    }
    deque_size++;
}

template <typename T>
T lib::Deque<T>::pop_back() {
    if (empty())
        throw std::overflow_error("Pop_back from empty deque");
    T popped_data = tail->item;
    if (head == tail) {
        delete tail;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T>* temp = tail;
        tail = tail->prev;
        delete temp;
        tail->next = nullptr;
    }
    deque_size--;
    return popped_data;
}

template <typename T>
T lib::Deque<T>::pop_front() {
    if (empty())
        throw std::overflow_error("Pop_front from empty deque");
    T popped_data = head->item;
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        head->prev = nullptr;
    }
    deque_size--;
    return popped_data;
}

template <typename T>
T& lib::Deque<T>::back() {
    if (empty())
        throw std::overflow_error("Access to the back element of empty deque");
    return tail->item;
}

template <typename T>
T& lib::Deque<T>::front() {
    if (empty())
        throw std::overflow_error("Access to the front element of empty deque");
    return head->item;
}

template <typename T>
void lib::Deque<T>::swap(Deque<T>& other) {
    size_t counter = size();
    while (!other.empty()) {
        push_front(other.pop_back());
    }
    while (counter) {
        other.push_front(pop_back());
        counter--;
    }
}

template <typename T>
void lib::Deque<T>::reverse() {
    Node<T>* curr = head;
    Node<T>* temp = nullptr;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp) {
        temp = temp->prev;
    }
    temp = head;
    head = tail;
    tail = temp;
}

#endif