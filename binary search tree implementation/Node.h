#ifndef INC_69___BST_IMPLEMENTATION_NODE_H
#define INC_69___BST_IMPLEMENTATION_NODE_H


class Node {
public:
    int val;    // key or data
    Node *left;
    Node *right;

    Node();

    explicit Node(int);
};


#endif //INC_69___BST_IMPLEMENTATION_NODE_H
