
#ifndef INC_69___BST_IMPLEMENTATION_BST_H
#define INC_69___BST_IMPLEMENTATION_BST_H

#include "Node.h"

class BST {
public:
    Node *root;

    bool isEmpty() const;

    void insert(Node *);
};


#endif //INC_69___BST_IMPLEMENTATION_BST_H
