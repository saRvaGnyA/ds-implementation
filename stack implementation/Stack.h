/*Stack class definition/prototypes
 * #pragma once directive supported too
 */

#ifndef _STACK_IMPLEMENTATION_STACK_H
#define _STACK_IMPLEMENTATION_STACK_H

class Stack {
private:
    int stack_ptr; //Stack pointer - points at the top of the stack
    int ssize;
    int *stack;
public:
    Stack();

    void push(int);

    int pop();

    bool is_empty();

    bool is_full();

    int count();

    void peek(int);

    void change(int, int);

    void display();
};


#endif //_STACK_IMPLEMENTATION_STACK_H
