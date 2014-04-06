#pragma once

#include "treenode.h"

class OperandNode : public TreeNode
{
public:
    OperandNode(int gotOperand);
    ~OperandNode();

    double calculate();
    void print();

private:
    int operand;
};
