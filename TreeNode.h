#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	int element; // Head Element
};

#endif