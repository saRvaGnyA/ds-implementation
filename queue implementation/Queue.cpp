#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
	:size{ 0 }, front{ -1 }, rear{ -1 } {
	cout << "Enter size of the queue: ";
	cin >> size;
	q = new int[size];
	for (int count{ 0 }; count < size; ++count)
		q[count] = 0;
}

bool Queue::is_empty() {
	if (rear == -1 && front == -1)
		return true;
	else
		return false;
}

bool Queue::is_full() {
	//if (front == 0 && rear == (size - 1)) - this is wrong as a queue is FIFO/LILO
	if(rear == (size-1))
		return true;
	else
		return false;
}

int Queue::count() {
	if (is_empty())
		return 0;
	else
		return (rear - front + 1);
}

void Queue::display() {
	cout << "The elements currently in the queue are: " << endl;
	for (int count{ 0 }; count < size; count++)
		cout << q[count] << "\t";
	cout << endl;
}

void Queue::enq(int value) {
	if (is_full())
		cout << "Queue overflow error" << endl;
	else if (is_empty()) {
		front++;
		rear++;
		q[front] = value;
	}
	else {
		rear++;
		q[rear] = value;
	}
}

int Queue::deq() {
	if (is_empty()) {
		cout << "Queue underflow error" << endl;
		return 0;
	}
	else if (front == rear) {			//only 1 element remaining case
		int temp;
		temp = q[rear];
		q[rear] = 0;
		rear = front = -1;
		return temp;
	}
	/*
	* 
	else {
		int temp;
		temp = q[rear];
		q[rear] = 0;
		rear--;
		return temp;
	}
	*
	* Flawed logic - a queue is FIFO/LILO
	*/
	else {
		int temp;
		temp = q[front];
		q[front] = 0;
		front++;
		return temp;
	}
}

Queue::~Queue() {
	delete[] q;
}
