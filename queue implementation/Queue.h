#pragma once
class Queue
{
private:
	int size;
	int* q; //queue
	int front, rear;
public:
	Queue();
	void enq(int);
	int deq();
	bool is_empty();
	bool is_full();
	int count();
	void display();
	~Queue();
};

