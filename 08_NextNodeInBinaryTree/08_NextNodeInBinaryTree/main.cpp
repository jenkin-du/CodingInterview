#include "BTreeNode.h"
#include<iostream>

using namespace std;

//在中序遍历中找到下一个节点值
BTreeNode* findNextNodeInOrder(BTreeNode* node);


int main() {

	//构造二叉树
	BTreeNode* root = new BTreeNode();
	root->parent = root->leftChild = root->rightChild = nullptr;
	root->value = 1;

	BTreeNode* s1 = addNode(root, 2, -1);
	BTreeNode* s2 = addNode(root, 3, 1);

	BTreeNode* t1 = addNode(s1, 4, -1);
	BTreeNode* t2 = addNode(s1, 5, 1);
	BTreeNode* t3 = addNode(s2, 6, -1);
	BTreeNode* t4 = addNode(s2, 7, 1);

	BTreeNode* f1 = addNode(t2, 8, -1);
	BTreeNode* f2 = addNode(t2, 9, 1);


	//找到中序遍历中的下一个结点
	BTreeNode *next = findNextNodeInOrder(t1);
	cout << "next node value: " << next->value << endl;

	return 0;
}

//在中序遍历中找到下一个节点值
BTreeNode* findNextNodeInOrder(BTreeNode* node) {

	if (node == nullptr) {
		return nullptr;
	}

	BTreeNode* next = nullptr;
	if (node->rightChild != nullptr) {
		next = node->rightChild;
		while (next->leftChild != nullptr) {
			next = next->leftChild;
		}

		return next;
	}

	if (node->parent != nullptr&&node->rightChild == nullptr) {
		BTreeNode* current = node;
		next = node->parent;
		while (next->rightChild == current) {
			current = next;
			next = next->parent;
		}

		return next;
	}
}