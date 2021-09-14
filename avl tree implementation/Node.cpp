#include "Node.h"

Node::Node(int v)
        : val{v}, left{nullptr}, right{nullptr} {

}

Node::Node()
        : Node(0) {

}