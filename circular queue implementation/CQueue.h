#ifndef _CQUEUE_H
#define _CQUEUE_H


class CQueue {
private:
    int size;
    int *q; //queue
    int front, rear;
    int itemcount;
public:
    CQueue();

    void enq(int);

    int deq();

    bool is_empty();

    bool is_full();

    int count();

    void display();

    ~CQueue();
};


#endif //_CQUEUE_H