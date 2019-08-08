#include <iostream>
#include "queue.hpp"
#include <queue>

int main(void) {
    lib::Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << q << std::endl;
    q.pop();
    std::cout << q << std::endl;
    q.pop();
    std::cout << q << std::endl;
    q.pop();
    std::cout << q << std::endl;
    // q.pop();
    // q.pop();
    // q.pop();
    // delete q.tail;
    // std::cout << q << std::endl;
    // std::cout << q.front() << std::endl;
    // std::cout << q.back() << std::endl;
    // std::cout << q1.front() << std::endl;
    // std::cout << q1 << std::endl;
    // q1.reverse();
    // q1.swap(q);
    // q = q1;
    // std::cout << q << std::endl;
    // std::cout << q1 << std::endl;
    // for (int i = 0; i < 10000000; i++) {
    //     q.push(i);
    //     q1.push(i+1);
    // }
    // std::cout << "end" << std::endl;
    // std::cout << "size = " <<  q.size() << std::endl;
    // std::cout << q.front() << std::endl;
    // std::cout << q.back() << std::endl;
    // std::cout << "size = " << q1.size() << std::endl;
    // q.pop();
    // q.pop();
    // q.pop();
    // std::cout << q.empty() << std::endl;
    // q.pop();
    // std::cout << q.size() << std::endl;
}