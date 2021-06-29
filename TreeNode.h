#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>

struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	int element; // head of node
	int number; // number of node
};

class tree
{
	private:
		int size;
	public:
		tree()
		{
			int size = 0;
		};
		~tree()
		{
		};
		void delTree(struct TreeNode*& node)
		{
			this->size = 0;
			if (node != NULL)
			{
				delTree(node->left);
				delTree(node->right);
				node = NULL;
			}
		};
		void printTree(struct TreeNode*& node)
		{
			if (this->size == 0)
				std::cout << std::endl << "Tree is Empty" << std::endl;
			else if (node != NULL)
			{
				std::cout << node->element << " ";
				printTree(node->left);
				printTree(node->right);
			}
		};
		void addNode(struct TreeNode*& node, int el)
		{
			this->size++;
			std::cout << this->size;
			if (node == NULL)
			{
				node = new TreeNode;
				node->element = el;
				node->right = NULL;
				node->left = NULL;
				node->number = 1;
			}
			if (el < node->element)
			{
				node->number++;
				addNode(node->left, el);
			}
			if (el > node->element)
			{
				node->number++;
				addNode(node->right, el);
			}
		};
		void dellNode(TreeNode*& node, int a)
		{
			//std::cout << this->size;
			//	if (a <= size)
			//	{
			//		if (node->number == a && a < size)
			//		{
			//			node->element = node->right->element;
			//			std::cout << "Click";
			//			dellNode(node->right, a);
			//		}
			//		if (node->number == a && a == size)
			//		{
			//			node->element = NULL;
			//			node->left = NULL;
			//			node->right = NULL;
			//			size--;
			//		}
			//	}
			//	else
			//		std::cout << "Error" << std::endl;
		};
};

#endif