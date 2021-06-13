#include "singlyLinkedList.h"

#include <iostream>

using namespace std;

singlyLinkedList::singlyLinkedList(Node *h)
        : head{h} {

}

singlyLinkedList::singlyLinkedList()
        : head{nullptr} {

}

Node *singlyLinkedList::nodeExists(int k) {
    Node *temp{nullptr}; //stores the address of node whose key will match(if it does)
    Node *ptr{head}; //start traversing from head node
    while (ptr != nullptr) {
        if (ptr->key == k)
            temp = ptr;
        ptr = ptr->next; //update to the address of the next node for the next iteration
    }
    return temp;
}

void singlyLinkedList::appendNode(Node *n) {
    //first traverse till the end and check for key being unique, then append
    if (nodeExists(n->key) != nullptr)
        cout << "The key isn't unique, another node having the same key already exists" << endl;
    else {
        if (head == nullptr) //the initial state, i.e. the first node is added
        {
            head = n;
            cout << "The first node has been added" << endl;
        } else //the linked list isn't empty
        {
            //traverse to the end, update the next ptr of the last node
            Node *ptr{head}; //start traversing from head node
            while (ptr->next != nullptr)
                ptr = ptr->next; //update to the address of the next node for the next iteration
            ptr->next = n;
            cout << "Node appended" << endl;
        }
    }
}

void singlyLinkedList::prependNode(Node *n) {
    //update the head node only
    if (nodeExists(n->key) != nullptr) //no duplicating of key
        cout << "The key isn't unique, another node having the same key already exists" << endl;
    else {
        if (head == nullptr) //the singly linked list is yet to be initialized
            appendNode(n);
        else {  //the linked list isn't empty
            n->next = head;
            head = n;
        }
    }
}

void singlyLinkedList::insertNode(int k, Node *n) {
    Node *ptr = nodeExists(k);
    if (ptr == nullptr)
        cout << "No node exists with the supplied key: " << k << endl;
    else {
        if (nodeExists(n->key) != nullptr) //no duplicating of key
            cout << "The key isn't unique, another node having the same key already exists" << endl;
        else {
            //here ptr has the address of the node with key 'k'
            n->next = ptr->next;
            ptr->next = n;
            cout << "Node has been inserted" << endl;
        }
    }
}

void singlyLinkedList::deleteNode(int k) {      //more like unlinked than deleted

    //TRICKY OPERATION!!

    if (head == nullptr) //empty linked list case, no scope of deleting anything
        cout << "Already empty linked list" << endl;

    else if (head != nullptr) {
        //this case checks if the first node is deleted
        if (head->key == k) {
            head = head->next;
            cout << "The head node has been updated and old head has been unliked" << endl;
        }
            //traverse till the node and unlink the node, this is TRICKY
        else {
            Node *temp = nullptr;
            Node *prev_ptr = head;
            Node *current_ptr = head->next;
            while (current_ptr != nullptr) {
                if (current_ptr->key == k) {
                    temp = current_ptr;
                    current_ptr = nullptr;
                } else {
                    prev_ptr = prev_ptr->next;
                    current_ptr = current_ptr->next;
                }
            }
            if (temp != nullptr) {
                prev_ptr->next = temp->next;
                cout << "The node has been unlinked" << endl;
            } else {
                cout << "Node doesn't exist with the given key value" << endl;
            }
        }
    }

}


void singlyLinkedList::updateNode(int k, int d) { //Update node by key
    Node *ptr = nodeExists(k);
    if(ptr== nullptr)
        cout << "No such node with the supplied key value exists" << endl;
    else {
        ptr->data = d;
        cout << "Node updated" << endl;
    }
}

void singlyLinkedList::printList() {
    if(head==nullptr) //empty list
        cout << "The list is empty" << endl;
    else {
        //traverse and print
        cout << "<------------------ Current state of the list -------------------->" << endl;
        int size {};
        Node *temp = head;
        while(temp!=nullptr) {
            size++;
            cout << "Element " << size << ":" << endl;
            cout << "Key is: " << temp->key << endl;
            cout << "Data is: " << temp->data << endl;
            temp = temp->next;
        }
        cout << "Size of the linked list currently is: " << size << endl;
    }
}

