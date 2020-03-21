#include "BTreeNode.h"

//���node,����-1�����ӣ�1���Һ���
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