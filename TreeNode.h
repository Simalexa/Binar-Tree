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
		int vec[100];
		int count;
		void moveNodeUp(TreeNode*& node) // finction to move all elements up when deleting nodes is active
		{
			if (node->right != NULL)
			{
				node->element = node->right->element;
				moveNodeUp(node->right);
			}
			if (node->right == NULL)
			{
				if (node->left != NULL)
					node->element = node->left->element;
				else
				{
					nodeToDel = node->number;
					node->element = NULL;
					node->number = size + 2;
					delete node->left;
					delete node->right;
				}
			}
		};
		void createNULLelements(struct TreeNode*& node) //for building BeautifullTree we need to create all nodes which note exist and make theri elements equal NULL
		{
			if (node->level <= maxLevel)
			{
				if (node->left != NULL)
					createNULLelements(node->left);
				if (node->right != NULL)
					createNULLelements(node->right);
				if (node->level <= maxLevel && node->left == NULL)
				{
					node->left = new TreeNode;
					node->left->element = NULL;
					node->left->level = node->level + 1;
					node->left->left = NULL;
					node->left->right = NULL;
					createNULLelements(node->left);
				}
				if (node->level <= maxLevel && node->right == NULL)
				{
					node->right = new TreeNode;
					node->right->element = NULL;
					node->right->level = node->level + 1;
					node->right->left = NULL;
					node->right->right = NULL;
					createNULLelements(node->right);
				}
			}
		};
		void cutTreeByLevel(struct TreeNode*& node, int lev) //after creating tree with all NULL elements its necessary to destroy all modes with NULL elements from memory. This function do it layer by layer.
		{
			if (node != NULL)
			{
				if (node->level == lev)
				{
					if (node->element == NULL)
					{
						delete node->left;
						delete node->right;
						node = NULL;
					}
				}
				else
				{
					cutTreeByLevel(node->left, lev);
					cutTreeByLevel(node->right, lev);
				}
			}
		};
		void cutTree(struct TreeNode*& node) // function to destroy all NULL elements from tree. Used in beautiful tree
		{
			for (int i = 0; i <= maxLevel; i++)
			{
				cutTreeByLevel(node, maxLevel - i + 1);
			}
		}
		void elementInLevel(struct TreeNode*& node, int lev) // find all elements in the current level.
		{
			if (node != NULL)
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
		void findLevel(struct TreeNode*& node, int inL) // find level position of all nodes
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
		void rightIndex(TreeNode*& node) // function to find correct index after deleting node
		{
			if (node != NULL)
			{
				if (node->number > nodeToDel)
				{
					node->number--;
				}
				rightIndex(node->left);
				rightIndex(node->right);
			}
		};
		void checkMaxLevel(struct TreeNode*& node)
		{
			elementInLevel(node, maxLevel);
			if (count == 0)
				maxLevel--;
			for (int k = 0; k < count; k++)
			{
				vec[k] = NULL;
			}
			count = 0;
			std::cout <<std::endl<< maxLevel<< std::endl;

		}
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
			if (node != NULL)
			{
				if (node->number == 1)
				{
					std::cout << "Tree in prefics form: " << std::endl;
					findLevel(node, 1);
				}
				std::cout << node->element << " (" << node->number << ") ";
				printTree(node->left);
				printTree(node->right);
			}
			if(node != NULL && node->number == size - 1)
				std::cout << std::endl;
		};
		void printBeautifullTree(struct TreeNode *&node) //print tree in TREE form =)
		{
			if (node->number == 1)
			{
				std::cout << std::endl << " Beautifull tree: "<<std::endl;
				findLevel(node, 1);
				//checkMaxLevel(node);
				createNULLelements(node); //create NULL elements in the tree
			}
			for (int i = 1; i <= maxLevel; i++)
			{
				elementInLevel(node, i);
				for (int k = 0; k < count; k++)
				{
					for (int j = 0; j < pow(2.0, maxLevel - i) - 1; j++)
						std::cout << " ";
					if (vec[k] != NULL)
						std::cout << vec[k];
					else
						std::cout << "0";
					for (int j = 0; j < pow(2.0, maxLevel - i); j++)
						std::cout << " ";
					vec[k] = NULL;
				}
				count = 0;
				std::cout << std::endl;
			}
			cutTree(node);
		};

		void addNode(struct TreeNode *&node, int el) // add new node
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
		int findElement(struct TreeNode*& node, int a) // find node with element head number a
		{
			if (node != NULL)
			{
				if (node->element == a)
				{
					std::cout << "For element " << a << " number of node is " << node->number << std::endl;
					return node->number;
				}
				if (node->element < a)
				{
					return findElement(node->right, a);
				}
				if (node->element > a)
					return findElement(node->left, a);
			}
		};
		void dellNode(TreeNode*& node, int b) // delete node number b
		{
			if (node != NULL)
			{
				if (node->number == b)
				{
					moveNodeUp(node);
					size--;
				}
					dellNode(node->left, b);
					dellNode(node->right, b);
			}
		};
		void dellAnyNode(struct TreeNode*& node, int b)
		{
			dellNode(node, b);
			rightIndex(node);
			delLastNode(node);
		};
		void delLastNode(struct TreeNode*& node)
		{
			if (node != NULL)
			{
				if (node->number == size + 2)
				{
					delete node->left;
					delete node->right;
					delete node;
					node = NULL;
				}
				else
				{
					delLastNode(node->left);
					delLastNode(node->right);
				}
			}
		};
};

#endif