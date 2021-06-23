
#ifndef INC_14___DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
#define INC_14___DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H

#include "Node.h"

class doublyLinkedList {
public:
    Node *head;

    doublyLinkedList();

    explicit doublyLinkedList(Node *);

    Node *is_exists(int);

    void append_node(Node *);

    void prepend_node(Node *);

    void insert_node(Node *, int);

    void delete_node(int);

    void update_by_key(int, int);

    void print();
};


#endif //INC_14___DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
