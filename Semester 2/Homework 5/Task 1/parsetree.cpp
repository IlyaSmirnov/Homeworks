#include "parsetree.h"

using namespace std;

ParseTree::ParseTree()
{
}

ParseTree::~ParseTree()
{
    delete root;
}

bool isOperator(QCharRef symbol)
{
    return ((symbol == '+') || (symbol == '-') || (symbol == '*') || (symbol == '/'));
}

bool isNumber(QCharRef symbol)
{
    return ((symbol >= '0') && (symbol <= '9'));
}

void ParseTree::parse(QString &string, TreeNode *&node, int &position)
{
    const int stringLength = 255;
    QString operand;
    operand.resize(stringLength);
    operand.clear();

    while (true)
    {
        ++position;
        if ((position >= string.length()) || (string[position] == '\r') || (string[position] == '\n'))
            return;

        if (isOperator(string[position]))
        {
            node = new OperatorNode(string[position]);
            parse(string, node->left, position);
            parse(string, node->right, position);

            return;
        }

        if (isNumber(string[position]))
        {
            operand += string[position];
            continue;
        }

        if (!isNumber(string[position]) && (operand != ""))
        {
            int temp = operand.toInt();
            node = new OperandNode(temp);

            return;
        }
    }
}

void ParseTree::print(QString &string)
{
    int position = -1;
    parse(string, root, position);
    root->print();
    cout << '\n';
}

double ParseTree::calculate(QString &string)
{
    int position = -1;
    parse(string, root, position);
    return root->calculate();
}
