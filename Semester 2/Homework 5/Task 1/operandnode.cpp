#include "operandnode.h"

using namespace std;

OperandNode::OperandNode(int operand) : operand(operand)
{
}

OperandNode::~OperandNode()
{

}

double OperandNode::calculate()
{
    return operand;
}

void OperandNode::print()
{
    cout << operand;
}
