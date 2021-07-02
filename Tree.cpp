#include <iostream>
#include "TreeNode.h"

int main()
{
	struct TreeNode *n; //create node
	n = NULL;
	tree t; //create tree
    t.addNode(n, 8); // add Node
	t.addNode(n, 3);
	t.addNode(n, 6);
	t.addNode(n, 1);
	t.addNode(n, 10);
	t.addNode(n, 14);
	t.addNode(n, 5);
	t.addNode(n, 2);
	t.addNode(n, 17);
	t.addNode(n, 19);
	t.addNode(n, 16);
    t.printTree(n); // print Tree in line form


	t.dellAnyNode(n, t.findElement(n, 3)); // delete node with element 2
	t.printTree(n);

	t.dellAnyNode(n, t.findElement(n, 10)); // delete node with element 10
	t.printTree(n);

	//t.dellAnyNode(n, t.findElement(n, 19));
	//t.printTree(n);

    return 0;
}
