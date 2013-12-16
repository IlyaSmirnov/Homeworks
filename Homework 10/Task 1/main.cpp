#include "binaryTree.h"
#include <stdlib.h>

#include "sortedList.h"

using namespace sortedListNS;
using namespace binaryTreeNS;
using namespace std;

int main()
{
	fstream input("input.txt");

	if (input.is_open())
	{
		SortedList list = createSortedList();
		fstream output("output.txt");

		while (!input.eof())
		{
			char symbol = '0';
			input >> symbol;

			BinaryTree tempTree = createTree();

			tempTree.root = new BinaryTreeNode;
			tempTree.root->leftChild = nullptr;
			tempTree.root->rightChild = nullptr;
			tempTree.root->symbol = symbol;

			addValueToSortedList(list, tempTree, 1);
		}

		makeTree(list);
		
		printTreeSomeOrder(list.head->tree, output);
		
		deleteTree(list.head->tree);
		deleteSortedList(list);
		output.close();
	}
	
	input.close();
	
	return 0;
}