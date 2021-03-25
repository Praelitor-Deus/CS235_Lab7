#include "Node.h"

Node::Node() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    height = 1;
}

Node::Node(int initialData) {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    height = 1;
    item = initialData;
}

Node::~Node() {
    delete left;
    delete right;
}

int Node::getData() const {
    return item;
}

void Node::setData(int newData) {
    item = newData;
}

Node * Node::getParent() const {
    return parent;
}

Node *& Node::getParentRaw() {
    return parent;
}

void Node::setParent(Node * newParent) {
    parent = newParent;
}

Node * Node::getLeftChild() const {
    return left;
}

Node *& Node::getLeftRaw() {
    return left;
}

void Node::setLeftChild(Node *& newLeft) {
    left = newLeft;
    if (left != nullptr) {
        left->setParent(this);
    }
}

Node * Node::getRightChild() const {
    return right;
}

Node *& Node::getRightRaw() { 
    return right;
}

void Node::setRightChild(Node *& newRight) {
    right = newRight;
    if (right != nullptr) {
        right->setParent(this);
    }
}

int Node::getHeight() {
    return height;
}

void Node::setHeight(int newHeight) {
    height = newHeight;
}

int Node::getHeightDiff() const {
    int heightDiff = 0;
    if (getRightChild() != nullptr) {
        heightDiff += getRightChild()->getHeight();
    }
    if (getLeftChild() != nullptr) {
        heightDiff -= getLeftChild()->getHeight();
    }
    return heightDiff;
}

int Node::refreshHeight() {
    if (left == nullptr) {
        if (right == nullptr) {
            height = 1;
        }
        else {
            height = right->getHeight() + 1;
        }
    }
    else {
        if (right == nullptr) {
            height = left->getHeight() + 1;
        }
        else {
            int a = left->getHeight() + 1;
            int b = right->getHeight() + 1;
            if (a > b) {
                height = a;
            }
            else {
                height = b;
            }
        }
    }
    return height;
}
