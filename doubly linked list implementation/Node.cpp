#include "Node.h"

Node::Node()
        : key{}, data{}, previous{nullptr}, next{nullptr} {

}

Node::Node(int k, int d)
        : key{k}, data{d} {

}
