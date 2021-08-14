
#ifndef INC_69___BST_IMPLEMENTATION_BST_H
#define INC_69___BST_IMPLEMENTATION_BST_H

#include "Node.h"

class BST {
public:
    Node *root;

    BST();

    bool isEmpty() const;

    Node *search(Node *, int);

    void print(Node *, int);

    void insert(Node *);

    void preorder(Node *) const;

    void inorder(Node *) const;

    void postorder(Node *) const;

    int height(Node *);

    void printLevelOrderBFS(Node *);

    void printGivenLevelBFS(Node *, int);
};


#endif //INC_69___BST_IMPLEMENTATION_BST_H
