#ifndef _FILE_B_TREE_NODE_H_
#define _FILE_B_TREE_NODE_H_

typedef struct BTreeNode {
	int value;
	struct BTreeNode* leftChild;
	struct BTreeNode* rightChild;
	struct BTreeNode* parent;
}BTreeNode;


//���node,����-1�����ӣ�1���Һ���
BTreeNode* addNode(BTreeNode* node, int value, int direction);

#endif // !_B_TREE_NODE_H_
