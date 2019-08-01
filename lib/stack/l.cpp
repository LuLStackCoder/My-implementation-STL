#include <iostream>
#include <stack>
#include <unistd.h>
#include "stack.hpp"

int main(void) {
    lib::Stack<int> st;
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    lib::Stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    std::cout << st.top() << std::endl;
    std::cout << st1.top() << std::endl;
    st.swap(st1);
    std::cout << st.top() << std::endl;
    std::cout << st1.top() << std::endl;
    // std::cout << st1.top() << std::endl;
}