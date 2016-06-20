//
//  BinaryTree.cpp
//  String
//
//  Created by 林涛 on 16/6/13.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "BinaryTree.hpp"
#include "LTTest.hpp"

int minDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    int minDepthOfLeft = minDepth(root->left);
    if (minDepthOfLeft == 0) {
        minDepthOfLeft = INT_MAX;
    }
    
    int minDepthOfRight = minDepth(root->right);
    if (minDepthOfRight == 0) {
        minDepthOfRight = INT_MAX;
    }
    
    if (minDepthOfLeft < minDepthOfRight) {
        return minDepthOfLeft + 1;
    } else {
        return minDepthOfRight + 1;
    }
}

void testMinDepth() {
    printf("test minDepth begin--------------------------------------------\n");
    TreeNode *nullTree = TreeNode::deserialize("{}");
    int depth1 = minDepth(nullTree);
    LTTest(0, depth1);
    
    TreeNode *oneTree = TreeNode::deserialize("{1}");
    int depth2 = minDepth(oneTree);
    LTTest(1, depth2);
    
    TreeNode *twoTree = TreeNode::deserialize("{1,2,3}");
    int depth3 = minDepth(twoTree);
    LTTest(2, depth3);
    
    TreeNode *leftTree = TreeNode::deserialize("{1,2,3,4,#,#,#,5}");
    int depth4 = minDepth(leftTree);
    LTTest(2, depth4);
    
    TreeNode *rightTree = TreeNode::deserialize("{1,2,3,#,#,#,4,#,5}");
    int depth5 = minDepth(rightTree);
    LTTest(2, depth5);
    printf("test minDepth end----------------------------------------------\n");
}

/**
 * @param root: The root of binary tree.
 * @return: An integer
 */
int maxDepth(TreeNode *root) {
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

void testMaxDepth(){
    printf("test maxDepth begin--------------------------------------------\n");
    TreeNode *nullTree = TreeNode::deserialize("{}");
    int depth1 = maxDepth(nullTree);
    LTTest(0, depth1);
    
    TreeNode *oneTree = TreeNode::deserialize("{1}");
    int depth2 = maxDepth(oneTree);
    LTTest(1, depth2);
    
    TreeNode *twoTree = TreeNode::deserialize("{1,2,3}");
    int depth3 = maxDepth(twoTree);
    LTTest(2, depth3);
    
    TreeNode *leftTree = TreeNode::deserialize("{1,2,#,3,#,4}");
    int depth4 = maxDepth(leftTree);
    LTTest(4, depth4);
    
    TreeNode *rightTree = TreeNode::deserialize("{1,#,2,#,3,#,4}");
    int depth5 = maxDepth(rightTree);
    LTTest(4, depth5);
    
    printf("test maxDepth end----------------------------------------------\n");
}


bool isBalanced(TreeNode *root) {
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
TreeNode* insertNode(TreeNode* root, TreeNode* node) {
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
vector<int> preorderTraversal(TreeNode *root) {
    // write your code here
    vector<int> result;
    preorderTraversal(root, result);
    return result;
}

bool isValidBST(TreeNode *root, long long min, long long max){
    if (root == NULL) {
        return true;
    }
    
    if (root->val <= min || root->val >= max) {
        return false;
    }
    
    return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
}

/**
 * @param root: The root of binary tree.
 * @return: True if the binary tree is BST, or false
 */
bool isValidBST(TreeNode *root) {
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
    return isValidBST(root, LONG_LONG_MIN, LONG_LONG_MAX);
    
}

vector<vector<int>> levelOrder(TreeNode *root) {
    // write your code here

    
    vector<vector<int>> results;
    if (root == NULL) {
        return results;
    }
    
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    q1.push(root);
    while (!q1.empty()) {
        vector<int> levelResult;
        while (!q1.empty()) {
            TreeNode *temp = q1.front();
            levelResult.push_back(temp->val);
            if (temp->left != NULL) {
                q2.push(temp->left);
            }
            if (temp->right != NULL) {
                q2.push(temp->right);
            }
            q1.pop();
        }
        results.push_back(levelResult);
        q1.swap(q2);
    }
    

    
    return results;
}

void searchRange(TreeNode* root, int k1, int k2,vector<int> &result){
    if (root == NULL) {
        return;
    }
    
    searchRange(root->left, k1, k2,result);
    if (root->val >= k1 && root->val <= k2) {
        result.push_back(root->val);
    }
    searchRange(root->right, k1, k2,result);
}

vector<int> searchRange(TreeNode* root, int k1, int k2) {
    // write your code here
    vector<int> result;
    searchRange(root, k1, k2,result);
    return result;
}

TreeNode* removeNode(TreeNode* root, int value) {
    // write your code here
    if (root == NULL) {
        return root;
    }
    
    if (value == root->val) {
        //处理节点
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        } else if (root->left != NULL && root->right == NULL){
            TreeNode *tmp = root;
            root = tmp->left;
            free(tmp);
        } else if (root->left == NULL && root->right != NULL){
            TreeNode *tmp = root;
            root = tmp->right;
            free(tmp);
        } else {
            //这种情况返回左右都可以
            //返回左，则把右节点放在左节点最下一层的最右
            TreeNode *tmp = root;
            root = tmp->left;
            TreeNode *p_newRight = root;
            while (p_newRight->right != NULL) {
                p_newRight = p_newRight->right;
            }
            p_newRight->right = tmp->right;
            free(tmp);
            
            //返回右，则把左节点放在右节点最下一层的最左
        }
        
    } else if (value < root-> val){
        root->left = removeNode(root->left, value);
    } else if (value > root-> val) {
        root->right = removeNode(root->right, value);
    }
    return root;
}





