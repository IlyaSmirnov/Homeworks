#pragma once

#include <iostream>
//#include <QString>
#include <QCharRef>

///node of tree of ariphmetic expression
class TreeNode
{
public:
    TreeNode();
    virtual ~TreeNode() = 0;

    ///calculate value of expression
    virtual double calculate() = 0;
    ///print tree to console
    virtual void print() = 0;

    ///left child
    TreeNode *left;
    ///right child
    TreeNode *right;
};
