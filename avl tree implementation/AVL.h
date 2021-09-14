#ifndef INC_86___AVL_TREE_AVL_H
#define INC_86___AVL_TREE_AVL_H

#include "Node.h"

class AVL {
public:

    Node *root;

    AVL();

    bool isEmpty() const;

    int height(Node *);

    int balanceFactor(Node *);

    Node *search(Node *, int);

    void print(Node *, int);

    Node *insert(Node *, Node *);

    static Node *leftR(Node *);

    static Node *rightR(Node *);
};


#endif //INC_86___AVL_TREE_AVL_H
