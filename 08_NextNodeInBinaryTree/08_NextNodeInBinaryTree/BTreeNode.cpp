#include "BTreeNode.h"

//添加node,方向，-1：左孩子，1：右孩子
BTreeNode* addNode(BTreeNode* node, int value, int direction) {

	BTreeNode* newNode = new BTreeNode();
	newNode->value = value;
	newNode->parent = node;
	newNode->leftChild = newNode->rightChild = nullptr;

	if (direction == 1) {
		node->rightChild = newNode;
	}
	if (direction == -1) {
		node->leftChild = newNode;
	}

	return newNode;
}