#pragma once
#include "NodeInterface.h"

class Node: public NodeInterface {

private:
    int item;
    Node * parent;
    Node * left;
    Node * right;
    int height;

public:
	Node();
	Node(int initialData);
	~Node();

	/*
	* Returns the data stored in this node
	*
	* @return the data stored in this node.
	*/
	int getData() const;
    void setData(int newData);



    void setParent(Node * newParent);
    Node * getParent() const;
    Node *& getParentRaw();
    

	/*
	* Returns the left child of this node or null if empty left child.
	*
	* @return the left child of this node or null if empty left child.
	*/

	Node * getLeftChild() const;
    Node *& getLeftRaw();

	void setLeftChild(Node *& newLeft);

	/*
	* Returns the right child of this node or null if empty right child.
	*
	* @return the right child of this node or null if empty right child.
	*/
	Node * getRightChild() const;
    Node *& getRightRaw();

	void setRightChild(Node *& newRight);

	/*
	* Returns the height of this node. The height is the number of nodes
	* along the longest path from this node to a leaf.  While a conventional
	* interface only gives information on the functionality of a class and does
	* not comment on how a class should be implemented, this function has been
	* provided to point you in the right direction for your solution.  For an
	* example on height, see page 448 of the text book.
	*
	* @return the height of this tree with this node as the local root.
	*/
	int getHeight();
    void setHeight(int newHeight);
    int getHeightDiff() const;

    int refreshHeight();
};
