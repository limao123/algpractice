//
//  BinaryTree.hpp
//  String
//
//  Created by 林涛 on 16/6/13.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"

static int maxDepth(TreeNode *root);
static bool isBalanced(TreeNode *root);
static TreeNode* insertNode(TreeNode* root, TreeNode* node);
static vector<int> preorderTraversal(TreeNode *root);
static bool isValidBST(TreeNode *root);
#endif /* BinaryTree_hpp */
