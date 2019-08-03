#include <iostream>
#include "stack.hpp"
#include <stack>


using namespace lib;

int main(void) {
    Stack<int> st;
    Stack<int> st1;
    st.push(1);
    st.push(2);
    st.push(3);
    st1.push(4);
    st1.push(5);
    st1.push(6);
    st1.push(7);
    st1.push(7);
    st1.push(7);
    std::cout << st.size() << std::endl;
    std::cout << st1.size() << std::endl;
    // std::cout << st.top() << std::endl;
    // std::cout << st1.top() << std::endl;
    st.reverse();
    st.swap(st1);
    st = st1;
    // st.pop();
    // st.pop();
    // st.pop();
    // st1.pop();
    std::cout << st.size() << std::endl;
    std::cout << st1.size() << std::endl;
    // while (!st.empty())
    // {
    //     std::cout << st.top() << std::endl;
    //     st.pop();
    // }
    // std::cout << std::endl;
    // while (!st1.empty())
    // {
    //     std::cout << st1.top() << std::endl;
    //     st1.pop();
    // }
}