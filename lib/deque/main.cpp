#include <deque>
#include <iostream>
#include "deque.hpp"

using namespace std;
int main() {
    lib::Deque<int> d;
    d.push_back(10);
    d.push_back(15);
    d.push_back(25);
    d.push_back(30);
    // lib::Deque<int> d1;
    // d1.push_back(1);
    // d1.push_back(1);
    // d1.push_back(2);
    // d1.push_back(3);
    // d.pop_back();
    cout << d << endl;
    d.pop_back();
    cout << d << endl;
    d.pop_back();
    cout << d << endl;
    d.pop_back();
    cout << d << endl;
    d.pop_back();
    cout << d << endl;
    // d.reverse();
    // // d.push_back(54);
    // d.push_front(69);
    // d.swap(d1);
    // cout << d1 << endl;
    // d = d1;
    // cout << d << endl;
    // d.reverse();
    // // d.push_back(54);
    // d.push_front(69);
    // d.swap(d1);
    // cout << d1 << endl;
    // d.pop_front();
    // cout << d << endl;
    // d.pop_front();
    // cout << d << endl;
    // d.pop_front();
    // cout << d << endl;
    // d.pop_front();
    // cout << d << endl;

    // cout << d1 << endl;
    // cout << "head->item    " << d.head->item << endl;
    // cout << "head    " << d.front() << endl;
    // cout << "head->next    " << d.head->next << endl;
    // cout << "head->prev    " << d.head->prev << endl;
    // cout << "tail->item   " << d.tail->item << endl;
    // cout << "tail   " << d.back() << endl;
    // cout << "tail->next    " << d.tail->next << endl;
    // cout << "tail->prev    " << d.tail->prev << endl;
    return 0;
}