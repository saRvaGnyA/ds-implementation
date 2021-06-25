
#include "cll.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

cll::cll()
        : head{nullptr} {


}

//Remember, this is a circular linked list! The loop continues in links. Some implementations differ due to the looping nature of the list.

Node *cll::is_exists(int k) {
    Node *temp{nullptr};
    Node *ptr{head};
    if (ptr == nullptr) //empty list
        return temp;
    else {
        //do while is used, not while, because we're checking for head node condition. For the first iteration, ptr points to head node. Hence, we iterate once and then check for the condition --> do while used
        do {
            if (ptr->key == k) {
                temp = ptr;
                break;
            }
            ptr = ptr->next;
        } while (ptr != head); //loop of links ends when the ptr returns back to the first node
        return temp;
    }
}

void cll::append_node(Node *n) {
    if (is_exists(n->key) != nullptr)
        cout << "Node with supplied key already exists" << endl;
    else {
        if (head == nullptr) {
            head = n;
            n->next = n;
            cout << "First node added" << endl;
        } else {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = n;
            n->next = head;
            cout << "Node appended" << endl;
        }
    }
}

void cll::prepend_node(Node *n) {
    if (is_exists(n->key) != nullptr)
        cout << "Node with supplied key already exists" << endl;
    else {
        if (head == nullptr)
            append_node(n);
        else {
            //CATCH! The final node must ALSO be updated to point to the prepended node. Values of head, when assigned to them, are different since a copy is stored(assigned)
            //The sequence of steps is important, since the head node changes at every step
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = n;
            n->next = head;
            head = n; //change the head at the end, since the old head is needed to update the final node
            cout << "Node prepended" << endl;
        }
    }
}

//Insert node has many cases here - at the end or in b/w
void cll::insert_node(int k, Node *n) {
    Node *ptr = is_exists(k);
    if (ptr == nullptr)
        cout << "No such node exists" << endl;
    else {
        if (is_exists(n->key) != nullptr)
            cout << "Node with supplied key already exists" << endl;
        else {
            if (ptr->next == head) // inserted after the last node, i.e. appended
                append_node(n);
            else {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node inserted" << endl;
            }
        }
    }
}

//Deleting always has been tricky, it has many operations
void cll::delete_node(int k) {
    Node *ptr{is_exists(k)};
    if (ptr == nullptr)
        cout << "No such node exists" << endl;
    else {
        if (head == nullptr)
            cout << "Linked list is already empty" << endl;
        else if (ptr == head) {
            if (ptr->next == head) {
                head = nullptr;
                cout << "head node unlinked, list now empty" << endl;
            } else {
                head = ptr->next;
                ptr->next = nullptr;
                Node *temp = head;
                while (temp->next != ptr)
                    temp = temp->next;
                temp->next = head;
                cout << "Node unlinked" << endl;
            }
        } else {
            Node *temp{head};
            while (temp->next != ptr)
                temp = temp->next;
            temp->next = ptr->next;
            ptr->next = nullptr;
        }
    }
}

void cll::update_node(int k, int d) {
    Node *ptr{is_exists(k)};
    if (ptr == nullptr)
        cout << "No such node exists" << endl;
    else {
        ptr->data = d;
        cout << "Node updated" << endl;
    }
}

void cll::print() {
    if (head == nullptr)
        cout << "List is empty" << endl;
    else {
        Node *temp{head};
        int size{};
        cout << endl << "!-------------------->" << endl;
        do {
            size++;
            cout << "(" << temp->key << "," << temp->data << ")" << "-->";
            temp=temp->next;
        } while (temp != head);
        cout << endl << "Size of the list is " << size << endl;
    }
}