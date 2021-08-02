
#ifndef INC_69___BST_IMPLEMENTATION_BST_H
#define INC_69___BST_IMPLEMENTATION_BST_H

#include "Node.h"

class BST {
public:
    Node *root;

    BST();

    bool isEmpty() const;

    void insert(Node *);

    void preorder(Node *) const;

    void inorder(Node *) const;

    void postorder(Node *) const;
};


#endif //INC_69___BST_IMPLEMENTATION_BST_H
