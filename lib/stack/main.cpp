#include <iostream>
#include <stack>
#include "stack.hpp"

using namespace std;
int main() {
    lib::Stack<std::string> st;
    for (int i = 0; i <= 10000000; i++) {
        st.push("asdfas");
    }
    
    
    return 0;
}