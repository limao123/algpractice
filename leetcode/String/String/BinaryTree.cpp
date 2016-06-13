//
//  BinaryTree.cpp
//  String
//
//  Created by 林涛 on 16/6/13.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "BinaryTree.hpp"
#include <stdlib.h>


/**
 * @param root: The root of binary tree.
 * @return: An integer
 */
static int maxDepth(TreeNode *root) {
    // write your code here
    if (root == NULL) {
        return 0;
    }
    
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    int depthOfLeft = maxDepth(root->left);
    int depthOfRight = maxDepth(root->right);
    if ( depthOfLeft > depthOfRight ) {
        return depthOfLeft + 1;
    } else {
        return depthOfRight + 1;
    }
}

static bool isBalanced(TreeNode *root) {
    if (root == NULL) {
        return true;
    }
    // write your code here
    if (abs(maxDepth(root->right)-maxDepth(root->left)) <= 1) {
        return true;
    } else {
        return false;
    }
}