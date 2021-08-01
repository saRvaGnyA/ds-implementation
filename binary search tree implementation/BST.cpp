
#include "BST.h"
#include <iostream>

using namespace std;

bool BST::isEmpty() const {
    if (root == nullptr)
        return true;
    else
        return false;
}

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
                cout << "Node inserted" << endl;
                break;
            } else if (new_node->val < temp->val) {
                temp = temp->left;
            } else if (new_node->val > temp->val && temp->right == nullptr) {
                temp->right = new_node;
                cout << "Node inserted" << endl;
                break;
            } else { //else if (new_node->val > temp->val) {
                temp = temp->right;
            }
        }
    }
}
