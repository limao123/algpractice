//
//  TreeNode.cpp
//  String
//
//  Created by 林涛 on 16/1/23.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "TreeNode.hpp"
#include <iostream>
using namespace std;

void TreeNode::preOrder(TreeNode *node){
    if (node == NULL) {
        return;
    }
    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
    
}


void TreeNode::inOrder(TreeNode *node){
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}

void TreeNode::postOrder(TreeNode *node){
    if (node == NULL) {
        return;
    }
    
    postOrder(node->left);
    postOrder(node->right);
    cout << node->val << " ";
}