
#include "BST.h"
#include <iostream>

#define SPACE 10

using namespace std;

BST::BST() : root{nullptr} {

}

bool BST::isEmpty() const {
    if (root == nullptr)
        return true;
    else
        return false;
}

void BST::print(Node *n, int space) {
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

Node *BST::search(Node *n, int v) {
    if (n == nullptr || n->val == v)
        return n;
    else if (n->val > v)
        return search(n->left, v);
    else
        return search(n->right, v);
}

//Iterative search
//Node *BST::search(int v) {
//    Node *t = root;
//    while (t != nullptr) {
//        if (t->val == v)
//            break;
//        else if (t->val > v)
//            t = t->left;
//        else
//            t = t->right;
//    }
//    return t;
//}

void BST::insert(Node *new_node) {
    if (root == nullptr) {
        root = new_node;
        cout << "Root node inserted" << endl;
    } else {
        Node *temp = root;
        while (temp != nullptr) {
            if (temp->val == new_node->val) {
                cout << "No duplicates allowed" << endl;
                break;
            } else if (new_node->val < temp->val && temp->left == nullptr) {
                temp->left = new_node;
                cout << "Node inserted to left" << endl;
                break;
            } else if (new_node->val < temp->val) {
                temp = temp->left;
            } else if (new_node->val > temp->val && temp->right == nullptr) {
                temp->right = new_node;
                cout << "Node inserted to right" << endl;
                break;
            } else { //else if (new_node->val > temp->val) {
                temp = temp->right;
            }
        }
    }
}

void BST::preorder(Node *n) const {  // NLR
    if (n == nullptr)
        return;
    cout << n->val << " ";
    preorder(n->left);
    preorder(n->right);
}

void BST::inorder(Node *n) const { // LNR
    if (n == nullptr)
        return;
    inorder(n->left);
    cout << n->val << " ";
    inorder(n->right);
}

void BST::postorder(Node *n) const {  // LRN
    if (n == nullptr)
        return;
    postorder(n->left);
    postorder(n->right);
    cout << n->val << " ";
}

int BST::height(Node *n) {
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