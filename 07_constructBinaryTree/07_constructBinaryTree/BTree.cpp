#include "BTree.h"

//前序遍历
void preorderTraversal(BTreeNode *root) {

	if (root != nullptr) {
		
		cout << root->value << ",";
		//前序便利左孩子
		preorderTraversal(root->leftChild);
		//前序遍历右孩子
		preorderTraversal(root->rightChild);
	}
}