#include "MinHeap.h"
#include <iostream>
#include <cmath>

using namespace std;

MinHeap::MinHeap(int c) : capacity{c}, heap_size{} {
    arr = new int[capacity];
}

void MinHeap::linear_search(int v) const {
    for (int i{}; i < capacity; ++i) {
        if (arr[i] == v) {
            cout << v << " is present in the heap" << endl;
            return;
        }
    }
    cout << v << " not found in the heap" << endl;
}

void MinHeap::print() const {
    for (int i{}; i < capacity; ++i) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int MinHeap::height() const {
    return ceil(log2(heap_size + 1) - 1);
}