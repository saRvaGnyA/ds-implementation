#ifndef INC_90___HEAP_MINHEAP_H
#define INC_90___HEAP_MINHEAP_H


class MinHeap {
public:
    int *arr;
    int capacity; //max size
    int heap_size; //current size

    explicit MinHeap(int);

    void linear_search(int) const;

    void print() const;

    int height() const;

    void insert(int);

    static int parent(int);
};


#endif //INC_90___HEAP_MINHEAP_H