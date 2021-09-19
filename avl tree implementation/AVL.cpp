#include "AVL.h"
#include <iostream>

#define SPACE 10

using namespace std;

AVL::AVL() : root{nullptr} {

}

bool AVL::isEmpty() const {
    if (root == nullptr)
        return true;
    else
        return false;
}

int AVL::height(Node *n) {
    if (n == nullptr)
        return -1;
    else {
        int left_height = height(n->left);
        int right_height = height(n->right);
        if (left_height > right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

int AVL::balanceFactor(Node *n) {
    if (n == nullptr)
        return -1;
    else
        return (height(n->left) - height(n->right));
}

Node *AVL::search(Node *n, int v) {
    if (n == nullptr || n->val == v)
        return n;
    else if (n->val > v)
        return search(n->left, v);
    else
        return search(n->right, v);
}

void AVL::print(Node *n, int space) {
    if (n == nullptr)
        return;
    space += SPACE;
    print(n->right, space);
    cout << endl;
    for (int i{}; i < space - SPACE; ++i)
        cout << " ";
    cout << n->val << endl;
    print(n->left, space);
}

Node *AVL::insert(Node *r, Node *n) {
    if (r == nullptr) {
        r = n;
        return r;
    } else {
        if (n->val < r->val)
            r->left = insert(r->left, n);
        else if (n->val > r->val)
            r->right = insert(r->right, n);
        else {
            cout << "Duplicates not allowed" << endl;
            return r;
        }
    }
    int bf = balanceFactor(r);
    if (bf > 1) {
        //LL imbalance
        if (n->val < r->left->val)
            return rightR(r);

            //LR imbalance
        else {
            r->left = leftR(r->left);
            return rightR(r);
        }
    } else if (bf < -1) {
        //RR imbalance
        if (n->val > r->right->val)
            return leftR(r);

            //RL imbalance
        else {
            r->right = rightR(r->right);
            return leftR(r);
        }
    }
    return r;
}

Node *AVL::leftR(Node *x) {
    Node *y = x->right;
    Node *temp = y->left;
    y->left = x;
    x->right = temp;
    return y;
}

Node *AVL::rightR(Node *y) {
    Node *x = y->left;
    Node *temp = x->right;
    x->right = y;
    y->left = temp;
    return x;
}

Node *AVL::nMin(Node *n) {
    Node *temp = n;
    while (temp->left != nullptr)
        temp = temp->left;
    return temp;
}

Node *AVL::deleteNode(Node *n, int v) {
    if (n == nullptr)
        return n;
    else if (v < n->val)
        n->left = deleteNode(n->left, v);
    else if (v > n->val)
        n->right = deleteNode(n->right, v);
    else {
        if (n->left == nullptr) {
            Node *temp = n->right;
            delete n;
            return temp;
        } else if (n->right == nullptr) {
            Node *temp = n->left;
            delete n;
            return temp;
        } else {
            Node *temp = nMin(n->right);
            n->val = temp->val;
            n->right = deleteNode(n->right, temp->val);
        }
    }
    int bf = balanceFactor(n);
    if (bf == 2) {
        if (balanceFactor(n->left) >= 0)
            return rightR(n);
        else { //balanceFactor(n->left) == -1
            n->left = leftR(n->left);
            return rightR(n);
        }
    } else if (bf == -2) {
        if (balanceFactor(n->right) <= 0)
            return leftR(n);
        else { //balanceFactor(n->left) == 1
            n->right = rightR(n->right);
            return leftR(n);
        }
    }
    return n;
}