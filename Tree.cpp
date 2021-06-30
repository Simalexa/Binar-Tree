#include <iostream>
#include "TreeNode.h"

int main()
{
	struct TreeNode* n; //create node
	n = NULL;
	tree t; //create tree
    t.addNode(n, 8); // add Node
	t.addNode(n, 3);
	t.addNode(n, 6);
	t.addNode(n, 1);
	t.addNode(n, 10);
	t.addNode(n, 14);
	t.addNode(n, 5);
    t.printTree(n); // print Tree
	int NodeNumber = t.findElement(n, 8); // find element in the tree
	t.dellNode(n, NodeNumber); // delete node with element 8
	t.printTree(n);
    return 0;
}
