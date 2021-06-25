
#ifndef INC_16___CIRCULAR_LINKED_LIST_NODE_H
#define INC_16___CIRCULAR_LINKED_LIST_NODE_H


class Node {
public:
    int key;
    int data;
    Node *next;

    Node();

    explicit Node(int, int);
};


#endif //INC_16___CIRCULAR_LINKED_LIST_NODE_H
