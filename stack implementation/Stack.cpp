//Stack class declaration/implementation

#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
        : stack_ptr{-1}, ssize{0} {
    cout << "Enter the size of the stack: ";
    cin >> ssize;

    stack = new int[ssize];

    for (int count{0}; count < ssize; ++count)
        stack[count] = 0;
}

bool Stack::is_empty() {
    if (stack_ptr == -1)
        return true;
    else
        return false;
}

bool Stack::is_full() {
    if (stack_ptr == (ssize - 1))
        return true;
    else
        return false;
}

int Stack::count() {
    return (stack_ptr + 1);
}

void Stack::push(int add) {
    if (is_full())
        cout << "Stack overflow error" << endl;
    else {
        stack_ptr++;
        stack[stack_ptr] = add;
    }
}

int Stack::pop() {
    if (is_empty()) {
        cout << "Stack underflow error" << endl;
        return 0;
    } else {
        int temp_top{stack[stack_ptr]};
        stack[stack_ptr] = 0;
        stack_ptr--;
        return temp_top;
    }
}

void Stack::peek(int posn) {
    posn++;
    if (posn >= 0 && posn < ssize)
        cout << "Element at position " << posn << " is " << stack[posn] << endl;
    else
        cout << "Enter a valid position" << endl;
}

void Stack::change(int posn, int value) {
    posn++;
    if (posn >= 0 && posn < stack_ptr) {
        stack[posn] = value;
    } else
        cout << "Enter a valid position" << endl;
}

void Stack::display() {
    if (is_full() && is_empty())
        cout << "Stack overflow or underflow error" << endl;
    else {
        for (int count{stack_ptr}; count > 0; --count)
            cout << stack[count] << endl;
    }
}