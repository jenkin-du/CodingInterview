#ifndef _FILE_B_TREE_H_
#define _FILE_B_TREE_H_

#include<iostream>

using namespace std;

typedef struct BTreeNode{

	int value;
	struct BTreeNode* leftChild;
	struct BTreeNode* rightChild;
}BTreeNode;

//Ç°Ðò±éÀú
void preorderTraversal(BTreeNode *root);

#endif 
