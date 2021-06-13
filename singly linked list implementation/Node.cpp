#include "Node.h"

Node::Node(int k, int d)
        : key{k}, data{d} {

}


Node::Node()
        : key{}, data{}, next{nullptr} {

}
