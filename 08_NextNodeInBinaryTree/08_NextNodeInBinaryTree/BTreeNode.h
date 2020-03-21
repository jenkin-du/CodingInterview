#ifndef _FILE_B_TREE_NODE_H_
#define _FILE_B_TREE_NODE_H_

typedef struct BTreeNode {
	int value;
	struct BTreeNode* leftChild;
	struct BTreeNode* rightChild;
	struct BTreeNode* parent;
}BTreeNode;


//添加node,方向，-1：左孩子，1：右孩子
BTreeNode* addNode(BTreeNode* node, int value, int direction);

#endif // !_B_TREE_NODE_H_
