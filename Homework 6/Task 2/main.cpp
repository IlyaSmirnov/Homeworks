#include "treeOfOperation.h"

using namespace Tree;

int main()
{
	FILE * in;
	fopen_s(&in, "input.txt", "r");
	//FILE * in = fopen("input.txt", "r");

	if (in != nullptr)
	{
		FILE * out;
		fopen_s(&out, "output.txt", "w");
		//FILE * out = fopen("output.txt", "w");

		OperationTree tree = createAndFillTree(in);

		printTree(tree, out);

		fprintf(out, "\n");

		fprintf(out, "%d\n", calculateTree(tree));

		deleteTree(tree);
		fclose(in);
		fclose(out);
	}
	else
		printf("%s\n", "Your file is not exist");

	return 0;
}