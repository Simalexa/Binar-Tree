#include <iostream>
#include "TreeNode.h"

void addNode(struct TreeNode *&node, int el)
{
	if (node == NULL)
	{
		node = new TreeNode;
		node->element = el;
		node->right = NULL;
		node->left = NULL;
	}
	if (el < node->element)
	{
		addNode(node->left, el);
	}
	if (el > node->element)
	{
		addNode(node->right, el);
	}
}
void printTree(struct TreeNode* node)
{
	if (node != NULL)
	{
		std::cout << node->element << " ";
		printTree(node->left);
		printTree(node->right);
	}
}

int main()
{
	struct TreeNode* n;
	n = NULL;
    addNode(n, 8);
	addNode(n, 3);
	addNode(n, 6);
	addNode(n, 1);
	addNode(n, 10);
	addNode(n, 14);
	addNode(n, 7);
    printTree(n);
    return 0;
}
