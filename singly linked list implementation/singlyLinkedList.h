
#ifndef INC_12___SINGLY_LINKED_LIST_SINGLYLINKEDLIST_H
#define INC_12___SINGLY_LINKED_LIST_SINGLYLINKEDLIST_H

#include "Node.h"

class singlyLinkedList {
public:
    Node *head;

    singlyLinkedList();

    explicit singlyLinkedList(Node*);

    Node *nodeExists(int); //traverse the linked list to check if a key is unique or not
                           //returns the node if key passed matches, else returns nullptr

    void appendNode(Node *);

    void prependNode(Node *);

    void insertNode(int, Node *);

    void deleteNode(int);

    void updateNode(int, int);

    void printList(); //print the linked list
};


#endif //INC_12___SINGLY_LINKED_LIST_SINGLYLINKEDLIST_H
