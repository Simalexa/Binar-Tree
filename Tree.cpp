#include <iostream>
#include "TreeNode.h"

int main()
{
	struct TreeNode* n;
	n = NULL;
	tree t;
    t.addNode(n, 8);
	t.addNode(n, 3);
	t.addNode(n, 6);
	t.addNode(n, 1);
	t.addNode(n, 10);
	t.addNode(n, 14);
	t.addNode(n, 5);
    t.printTree(n);
	t.dellNode(n, 5);
	t.printTree(n);
	//t.delTree(n);
	//t.printTree(n);
    return 0;
}
