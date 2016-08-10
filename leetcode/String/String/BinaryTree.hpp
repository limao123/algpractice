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
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int maxDepth(TreeNode *root);


int minDepth(TreeNode *root);


bool isBalanced(TreeNode *root);


TreeNode* insertNode(TreeNode* root, TreeNode* node);
vector<int> preorderTraversal(TreeNode *root);
bool isValidBST(TreeNode *root);
vector<vector<int>> levelOrder(TreeNode *root);
vector<int> searchRange(TreeNode* root, int k1, int k2);

#endif /* BinaryTree_hpp */
