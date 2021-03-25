#include "AVL.h"
#include <iostream>

AVL::AVL() {
    root = nullptr;
}

AVL::~AVL() {

}

Node * AVL::getRootNode() const {
    return root;
}

void AVL::rotateLeft(Node *& n) {
    Node* temp = n; 
    n = n->getRightChild(); // Set pointer to n to point to k
    temp->getRightRaw() = n->getLeftRaw(); // Set n's right to point to k's left
    n->getRightRaw() = temp; // Set k's left to point to n
}

void AVL::rotateRight(Node *& n) {
    Node* temp = n;
    n = temp->getLeftChild();
    temp->getLeftRaw() = n->getRightChild();
    n->getRightRaw() = temp;
  // Set pointer to n to point to k
  // Set n's left to point to k's right
  // Set k's right to point to n
}

void AVL::rebalance(Node*& n)
{
  // Check node's balance (should be -2, -1, 0, 1, or 2)
    int balance = n->getHeightDiff();
    if (balance == -2) {
        // (LR or LL tree)
        if (n->getLeftRaw()->getHeightDiff() == 1) {
            // LR Tree (we must rotate left around n->left first)
            rotateLeft(n->getLeftRaw());
        }
        // Now rotate right around n either way.
        rotateRight(n);
    }
  // Case: balance == -2 (LL or LR tree)
    // Case: LL tree (left balance is -1 or 0, so rotate right around n)
    // Case: LR tree (left balance is 1, so rotate left around n->left, then rotate right around n)
  // Case: balance == 2 (RR or RL tree)
    // Case: RR tree (right balance is 1 or 0, so rotate left around n)
    // Case: RL tree (right balance is -1, so rotate right around n->right, then rotate left around n)
  // Case: else (do nothing, not unbalanced)
}

bool AVL::add(int data) {
    cout << "Starting ADD" << endl;
    if (root == nullptr) {
        root = new Node(data);
        return true;
    }
    return addAt(data, root);
}

bool AVL::addAt(int data, Node *& at) {
    if (at == nullptr) {
        at = new Node(data);
        return true;
    }
    if (at->getData() == data) {
        return false;
    }
    if (data > at->getData()) {
        bool result = addAt(data, at->getRightRaw());
        if (result) {
            rebalance(at);
        }
        return result;
    }
    else {
        bool result = addAt(data, at->getLeftRaw());
        if (result) {
            rebalance(at);
        }
        return result;
    }
}

bool AVL::remove(int data) {
    cout << "Starting REMOVE" << endl;
    return false;
}

void AVL::clear() {
    delete root;
    root = nullptr;
}

/*
void AVL::balanceAt(Node * at, int heightChange) {
    if (at == nullptr) {
        return;
    }
    at->setHeight(at->getHeight() + heightChange);

    // Check if we have to balance here.
    int thisDiff = at->getHeightDiff();
    if (thisDiff <= 1 and thisDiff >= -1) {
        // We don't have to balance here. Move on to parent.
        balanceAt(at->getParent(), heightChange);
        return;
    }
    if (thisDiff < -1) {
        // The left's height difference must be -1 or 1
        Node * leftTMP = at->getLeftChild();
        if (leftTMP->getHeightDiff() < 0) {
            // Scenario LEFT-LEFT
            cout << "Balance type LEFT LEFT" << endl;
            at->setLeftChild(leftTMP->getRightChild());
            leftTMP->setParent(at->getParent());
        }
    }

    // Run through the various balancing options.
    
}
*/