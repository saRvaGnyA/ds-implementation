
#ifndef INC_16___CIRCULAR_LINKED_LIST_CLL_H
#define INC_16___CIRCULAR_LINKED_LIST_CLL_H

#include "Node.h"

class cll {
public:
    Node *head;

    cll();

    Node *is_exists(int);

    void append_node(Node *);

    void prepend_node(Node *);

    void insert_node(int, Node *);

    void delete_node(int);

    void update_node(int, int);

    void print();
};


#endif //INC_16___CIRCULAR_LINKED_LIST_CLL_H
