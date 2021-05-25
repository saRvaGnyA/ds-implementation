
#include "CQueue.h"
#include <iostream>

using namespace std;

CQueue::CQueue()
        : size{0}, front{-1}, rear{-1}, itemcount{0} {
    cout << "Enter size of the circular queue: ";
    cin >> size;
    q = new int[size];
    for (int count{0}; count < size; ++count)
        q[count] = 0;
}

bool CQueue::is_empty() {
    if (rear == -1 && front == -1) //remains same for both circular and simple queue
        return true;
    else
        return false;
}

bool CQueue::is_full() {
    //if(rear == (size-1)) - for a simple queue
    if ((rear + 1) % size == front) //for a circular queue - if rear is just behind front
        return true;
    else
        return false;
}

int CQueue::count() {
    return itemcount;
}

void CQueue::display() {
    cout << "The elements currently in the circular queue are: " << endl;
    for (int count{0}; count < size; count++)
        cout << q[count] << "\t";
    cout << endl;
}

void CQueue::enq(int value) {
    if (is_full()) {
        cout << "Circular Queue overflow error" << endl;
        return; //or else itemcount will be incremented
}
    else if (is_empty()) {
        front++;
        rear++;
        q[front] = value; //or q[rear]
    } else {
        // rear++; - for a simple queue
        rear = (rear + 1) % size; //for a circular queue
        q[rear] = value;
    }
    itemcount++;
}

int CQueue::deq() {
    if (is_empty()) {
        cout << "Circular Queue underflow error" << endl;
        return 0;
    } else if (front == rear) { //one element remaining case
        int temp;
        temp = q[rear];
        q[rear] = 0;
        rear = front = -1;
        itemcount--;
        return temp;
    } else {
        int temp;
        temp = q[front];
        q[front] = 0;
        //front++; - for a simple queue
        front = (front + 1) % size; //for a circular queue
        itemcount--;
        return temp;
    }
}

CQueue::~CQueue() {
    delete[] q;
}