#include <iostream>
//#include "TreeNode.h"
//#include "TreeNode.cpp"

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int element; // Head Element
};

void addNode(struct TreeNode* node, int el)
{
	if (node == NULL)
	{
		node = new TreeNode;
		node->element = el;
		node->right = NULL;
		node->left = NULL;
	}
}
void printTree(struct TreeNode* node)
{
	if (node != NULL)
	{
		std::cout << node->element << std::endl;
		printTree(node->left);
		printTree(node->right);
	}
	else
		std::cout << "Tree is not exist" << std::endl;
}

int main()
{
    struct TreeNode* n;
	n = NULL;
    addNode(n, 10);
    printTree(n);
    return 0;
}
