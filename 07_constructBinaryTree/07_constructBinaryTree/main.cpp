#include "BTree.h"

BTreeNode* construct(int* preorder, int* inorder, int length);

BTreeNode* constrctCore(int* preStart, int* preEnd, int* inStart, int* inEnd);

int main() {

	int preorder[] = {1,2,4,7,3,5,6,8};
	int inorder[] = {4,7,2,1,5,3,8,6};

	//�ؽ�
	BTreeNode* root = construct(preorder, inorder, 8);
	//ǰ�������ӡ
	preorderTraversal(root);
	cout << endl;

	return 0;
}

//�ؽ�
BTreeNode* construct(int* preorder, int* inorder, int length) {

	if (preorder == nullptr || inorder == nullptr || length <= 0) return nullptr;
	return constrctCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

//�ؽ�����
BTreeNode* constrctCore(int* preStart, int* preEnd, int* inStart, int* inEnd) {

	int rootValue = *preStart;
	BTreeNode *root = new BTreeNode();
	
	root->value = rootValue;
	root->leftChild = nullptr;
	root->rightChild = nullptr;

	//�ҵ����������������е�λ��
	int* rootOrder = inStart;
	while (rootOrder <= inEnd&&*rootOrder != rootValue) {
		rootOrder++;
	}
	if (rootOrder == inEnd&&*rootOrder != rootValue) {
		throw exception("invalid input");
		return nullptr;
	}

	//�ҵ��˸��������������е�λ��
	//���������
	int leftLength = rootOrder - inStart;
	if (leftLength > 0) {
		int *leftPreEnd = preStart + leftLength;
		if (leftPreEnd > preEnd) {
			throw exception("invalid input");
			return nullptr;
		}
		root->leftChild = constrctCore(preStart + 1, leftPreEnd, inStart, rootOrder - 1);
	}
	//���������
	int rightLength = inEnd - rootOrder;
	if (rightLength > 0 && leftLength < preEnd - preStart) {
		int *rightPreStart = preStart + leftLength + 1;
		if (rightPreStart > preEnd) {
			throw exception("invalid input");
			return nullptr;
		}
		root->rightChild = constrctCore(rightPreStart, preEnd, rootOrder + 1, inEnd);
	}
	
	return root;
}