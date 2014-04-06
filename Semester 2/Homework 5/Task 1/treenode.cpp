#include "treenode.h"

TreeNode::TreeNode() : left(nullptr), right(nullptr)
{
}

TreeNode::~TreeNode()
{
    delete left;
    delete right;
}
