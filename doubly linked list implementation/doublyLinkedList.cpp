

#include "doublyLinkedList.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

doublyLinkedList::doublyLinkedList()
        : head{nullptr} {

}

doublyLinkedList::doublyLinkedList(Node *n)
        : head{n} {

}

Node *doublyLinkedList::is_exists(int k) {
    Node *temp{nullptr};  //return this
    Node *ptr{head};  //traversal ptr
    while (ptr != nullptr) {
        if (ptr->key == k) {
            temp = ptr;
            break;
        }
        ptr = ptr->next;
    }
    return temp;
}

void doublyLinkedList::append_node(Node *n) {
    //first check if node with given key already exists or not
    if (is_exists(n->key) != nullptr)
        cout << "A node with the supplied key " << n->key << "already exists" << endl;
    else {
        //if the list is empty
        if (head == nullptr)
            head = n;
        else {
            //first traverse till the end, then append
            Node *ptr{head};
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = n;
            n->previous = ptr;
        }
        cout << "Node appended" << endl;
    }
}

void doublyLinkedList::prepend_node(Node *n) {
    if (is_exists(n->key) != nullptr)
        cout << "A node with the supplied key " << n->key << "already exists" << endl;
    else {
        if (head == nullptr)
            append_node(n);
        else {
            n->next = head;
            head->previous = n;
            head = n;
        }
        cout << "Node prepended" << endl;
    }
}

//Inserting node has many cases to consider
void doublyLinkedList::insert_node(Node *n, int k) {
    if (is_exists(k) != nullptr) {
        if (is_exists(n->key) != nullptr)
            cout << "A node with the supplied key " << n->key << "already exists" << endl;
        else {
            if (head == nullptr)
                append_node(n);
            else {
                Node *ptr{is_exists(k)};
                //Insert at end
                if (ptr->next == nullptr) {
                    ptr->next = n;
                    n->previous = ptr;
                    n->next = nullptr;
                }
                    //Insert in b/w
                else {
                    n->next = ptr->next;
                    ptr->next = n;
                    n->previous = ptr;
                    n->next->previous = n;
                }
            }
            cout << "Node inserted" << endl;
        }
    } else {
        cout << "No such node with the entered key exists" << endl;
    }
}

//Deleting the node always has been tricky
void doublyLinkedList::delete_node(int k) {
    if (head == nullptr)
        cout << "The list is already empty" << endl;
    else {
        Node *ptr = is_exists(k);
        if (ptr == nullptr)
            cout << "No such node with the entered key exists" << endl;
        else {
            //Check if the node is the head node
            if (head == ptr) {
                //Just club all of them together
                head = ptr->next;
//                if (ptr->next != nullptr) {  //head node and list has elements ahead
//                    head = ptr->next;
//                    head->previous = nullptr;
//                    ptr->next = nullptr;
//                } else {   //head node and it is the only element in the list currently
//                    head = nullptr;
//                }

            } else {
                if (ptr->next == nullptr) { //last node is being unlinked
                    ptr->previous->next = nullptr;
                    ptr->previous = nullptr;
                } else {  //middle node
                    ptr->previous->next = ptr->next;
                    ptr->next->previous = ptr->previous;
                    ptr->previous = nullptr;
                    ptr->next = nullptr;
                }
            }
            cout << "Node unlinked" << endl;
        }
    }
}

void doublyLinkedList::update_by_key(int ok, int nd) {
    Node *ptr = is_exists(ok);
    if (ptr == nullptr)
        cout << "No such node with the entered key exists" << endl;
    else {
        ptr->data = nd;
        cout << "The node data is now updated" << endl;
    }
}

void doublyLinkedList::print() {
    int count{};
    if (head == nullptr)
        cout << "List is empty" << endl;
    else {
        Node *ptr = head;
        while (ptr != nullptr) {
            count++;
            cout << "(" << ptr->key << ", " << ptr->data << ") ---> ";
            ptr = ptr->next;
        }
        cout << endl;
    }
    cout << "Size of the linked list is " << count << endl;
}