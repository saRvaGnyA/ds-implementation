#ifndef INC_86___AVL_TREE_NODE_H
#define INC_86___AVL_TREE_NODE_H

class Node {
public:
    int val;    // key or data
    Node *left;
    Node *right;

    Node();

    explicit Node(int);
};


#endif //INC_86___AVL_TREE_NODE_H
