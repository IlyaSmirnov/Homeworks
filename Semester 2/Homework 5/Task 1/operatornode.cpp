#include "operatornode.h"

using namespace std;

OperatorNode::OperatorNode(QCharRef operation) : operation(operation)
{
}

OperatorNode::~OperatorNode()
{

}

double OperatorNode::calculate()
{
    if (operation == '+')
        return left->calculate() + right->calculate();
    if (operation == '-')
        return left->calculate() - right->calculate();
    if (operation == '*')
        return left->calculate() * right->calculate();
    if (operation == '/')
        return left->calculate() / right->calculate();
}

void OperatorNode::print()
{
    cout << "( " << operation.toLatin1() << " ";

    left->print();

    cout << " ";

    right->print();

    cout << " )";

}
