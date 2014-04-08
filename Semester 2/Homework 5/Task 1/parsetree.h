#pragma once

#include <QString>
#include <QCharRef>

#include "operandnode.h"
#include "operatornode.h"

///parse ariphmetic expression to tree and calculate value
class ParseTree
{
public:
    ParseTree();
    ~ParseTree();

    ///print tree to console
    void print(QString &string);
    ///calculate value of expression
    double calculate(QString &string);

private:
    ///make tree from string
    void parse(QString &string, TreeNode *&node, int &position);
    ///root
    TreeNode *root;
};
