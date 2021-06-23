
#ifndef INC_14___DOUBLY_LINKED_LIST_NODE_H
#define INC_14___DOUBLY_LINKED_LIST_NODE_H


class Node {
public:
    int key;
    int data;
    Node *next;
    Node *previous;

    Node();

    Node(int, int);

};


#endif //INC_14___DOUBLY_LINKED_LIST_NODE_H
