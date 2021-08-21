
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

Node *BST::insertRecursive(Node *r, Node *n) {
    if (r == nullptr) {
        r = n;
        return r;
    } else if (n->val < r->val) {
        r->left = insertRecursive(r->left, n);
    } else if (n->val > r->val) {
        r->right = insertRecursive(r->right, n);
    } else {
        cout << "Duplicates not allowed" << endl;
        return r;
    }
    return r;
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

void BST::printLevelOrderBFS(Node *n) {
    int h = height(n);
    for (int i{}; i <= h; ++i)
        printGivenLevelBFS(n, i);
}

void BST::printGivenLevelBFS(Node *n, int level) {
    if (n == nullptr)
        return;
    else if (level == 0)
        cout << n->val << "\t";
    else {
        printGivenLevelBFS(n->left, level - 1);
        printGivenLevelBFS(n->right, level - 1);
    }
}

Node *BST::nMin(Node *n) {
    Node *temp = n;
    while (temp->left != nullptr)
        temp = temp->left;
    return temp;
}

Node *BST::deleteNode(Node *n, int v) {
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
    return n;
}