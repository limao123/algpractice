//
//  BinaryTree.cpp
//  String
//
//  Created by 林涛 on 16/6/13.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "BinaryTree.hpp"
#include <stdlib.h>
#include <vector>
using namespace std;


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
        return isBalanced(root->right) && isBalanced(root->left);
    } else {
        return false;
    }
}

/**
 * @param root: The root of the binary search tree.
 * @param node: insert this node into the binary search tree
 * @return: The root of the new binary search tree.
 */
static TreeNode* insertNode(TreeNode* root, TreeNode* node) {
    // write your code here
    if (root == NULL) {
        return node;
    }
    
    if (node->val < root->val) {
        if (root->left != NULL) {
            insertNode(root->left, node);
        } else {
            root->left = node;
        }
    } else {
        if (root->right != NULL) {
            insertNode(root->right, node);
        } else {
            root->right = node;
        }
    }
    return root;
}

void preorderTraversal(TreeNode *root,vector<int> &vector){
    if (root == NULL) {
        return;
    }
    
    vector.push_back(root->val);
    preorderTraversal(root->left, vector);
    preorderTraversal(root->right, vector);
}

/**
 * @param root: The root of binary tree.
 * @return: Preorder in vector which contains node values.
 */
static vector<int> preorderTraversal(TreeNode *root) {
    // write your code here
    vector<int> result;
    preorderTraversal(root, result);
    return result;
}


/**
 * @param root: The root of binary tree.
 * @return: True if the binary tree is BST, or false
 */
static bool isValidBST(TreeNode *root) {
    // write your code here
//    if ((root == NULL) ||
//        ((root->left == NULL) && (root->right == NULL))) {
//        return true;
//    }
//    
//    if ((root->left == NULL) && (root->val < root->right->val)) {
//        return isValidBST(root->right);
//    } else if (root->right == NULL && root->val > root->left->val){
//        return isValidBST(root->left);
//    } else if (root->val > root->left->val && root->val < root->right->val){
//        return isValidBST(root->left) && isValidBST(root->right);
//    } else {
//        return false;
//    }
}


