
#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int v)
        : val{v}, left{nullptr}, right{nullptr} {

}

Node::Node()
        : Node(0) {

}