#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <math.h> 
#include <string>

struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	struct TreeNode* line;
	int element; // head of node
	int number; // number of node
	int level; //level of node
};

class tree
{
	private:
		int size; // size of tree
		int nodeToDel; // index of Null element in tree,  which used in deleting node function 
		int maxLevel; // maximum level
		// for creating Beutifull tree
		//std::string vec;
		int vec[10];
		int count;
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
		void elementInLevel(struct TreeNode*& node, int lev)
		{
			if (node != NULL && node->number <= size)
			{
				if (node->level == lev)
				{
					vec[count] = node->element;
					count++;
				}
				elementInLevel(node->left, lev);
				elementInLevel(node->right, lev);
			}
		};
		void findLevel(struct TreeNode*& node, int inL)
		{
			if (node != NULL)
			{
				node->level = inL;
				if (node->left != NULL)
					node->left->level = inL + 1;
				if (node->right != NULL)
					node->right->level = inL + 1;
				if (node->level > maxLevel)
					maxLevel = node->level;
				findLevel(node->right, inL + 1);
				findLevel(node->left, inL + 1);
			}
		};
	public:
		tree()
		{
			size = 0;
			maxLevel = 0;
			count = 0;
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
					findLevel(node, 1);
				}
				std::cout << node->element << " (" << node->level << ") ";
				printTree(node->left);
				printTree(node->right);
			}
			if(node != NULL && node->number == this-> size - 1)
				std::cout << std::endl;
		};
		void printVec(struct TreeNode*& node)
		{
			for (int i = 1; i <= maxLevel; i++)
			{
				elementInLevel(node, i);
				for (int k = 0; k < count; k++)
				{
					for (int j = 0; j < pow(2.0, maxLevel - i) - 1; j++)
						std::cout << " ";
					std::cout << vec[k];
					for (int j = 0; j < pow(2.0, maxLevel - i) - 1; j++)
						std::cout << " ";
					vec[k] = NULL;
				}
				count = 0;
				std::cout << std::endl;
			}
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