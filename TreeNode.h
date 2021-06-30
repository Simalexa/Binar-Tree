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
		int size; // size of tree
		int nodeToDel; // index of Null element in tree,  which used in deleting node function 
		void moveNodeUp(TreeNode*& node) // finction to move all elements up when deleteNode is active
		{
			if (node->right != NULL)
			{
				node->element = node->right->element;
				moveNodeUp(node->right);
			}
			if (node->right == NULL)
			{
				nodeToDel = node->number;
				if (node->left != NULL)
					node->element = node->left->element;
				else
				{
					node->element = NULL;
					node->number = size + 1;
					delete node->left;
					delete node->right;
				}
			}
		}
		void rightIndex(TreeNode*& node) // function to find correct index after deleting node
		{
			if (node != NULL)
				if (node->number > nodeToDel)
				{
					node->number--;
				}
				else
				{
					rightIndex(node->left);
					rightIndex(node->right);
				}
		}
	public:
		tree()
		{
			size = 0;
		};
		~tree()
		{
		};
		void delTree(struct TreeNode*& node) // delete all tree
		{
			this->size = 0;
			if (node != NULL)
			{
				delTree(node->left);
				delTree(node->right);
				node = NULL;
			}
		};
		void printTree(struct TreeNode*& node) // print tree
		{
			if (this->size == 0)
				std::cout << "Tree is Empty" << std::endl;
			else if (node != NULL && node->number<=size)
			{
				if (node->number == 1)
				{
					std::cout << "Tree in prefics form: " << std::endl;
				}
				std::cout << node->element << " (" << node->number << ") ";
				printTree(node->left);
				printTree(node->right);
			}
			if(node != NULL && node->number == this-> size - 1)
				std::cout << std::endl;
		};
		void addNode(struct TreeNode*& node, int el) // add new node
		{
			if (node == NULL)
			{
				node = new TreeNode;
				node->element = el;
				node->right = NULL;
				node->left = NULL;
				this->size++;
				node->number = size;
			}
			if (el < node->element)
			{
				addNode(node->left, el);
			}
			if (el > node->element)
			{
				addNode(node->right, el);
			}
		};
		int findElement(struct TreeNode *&node, int a) // find node with element head number a
		{
			if (node != NULL)
			{
				if (node->element == a)
				{
					std::cout <<"For element " << a << " number of node is "<< node->number <<std::endl;
					return node->number;
				}
				if(node->element < a)
				{
					 return findElement(node->right, a);
				}
				if(node->element > a)
					return findElement(node->left, a);
			}
		}
		void dellNode(TreeNode*& node, int b) // delete node number b
		{
			if (node != NULL)
			{
				if (node->number == b)
				{
					moveNodeUp(node);
					this->size--;
				}
				else
				{
					dellNode(node->left, b);
					dellNode(node->right, b);
				}
			}
			rightIndex(node);
		};
};

#endif