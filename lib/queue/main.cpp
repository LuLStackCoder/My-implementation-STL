#include <iostream>
#include "queue.hpp"

int main(void) {
    lib::Queue<int> q;
    q.push(5);
    q.push(10);
    q.push(1);
    std::cout << q.front() << std::endl;
    std::cout << q.back() << std::endl;
    // q.pop();
    // q.pop();
    // q.pop();
    // std::cout << q.empty() << std::endl;
    // q.pop();
    // std::cout << q.size() << std::endl;
}