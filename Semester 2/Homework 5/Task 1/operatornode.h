#pragma once

#include "treenode.h"

class OperatorNode : public TreeNode
{
public:
    OperatorNode(QCharRef operation);
    ~OperatorNode();

    double calculate();
    void print();

private:
    QCharRef operation;
};
