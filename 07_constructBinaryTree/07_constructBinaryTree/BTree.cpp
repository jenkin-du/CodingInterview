#include "BTree.h"

//ǰ�����
void preorderTraversal(BTreeNode *root) {

	if (root != nullptr) {
		
		cout << root->value << ",";
		//ǰ���������
		preorderTraversal(root->leftChild);
		//ǰ������Һ���
		preorderTraversal(root->rightChild);
	}
}