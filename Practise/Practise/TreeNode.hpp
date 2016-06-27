//
//  TreeNode.hpp
//  Practise
//
//  Created by bmob-LT on 16/6/27.
//  Copyright © 2016年 bmob-LT. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class TreeNode {

    
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

string serialize(TreeNode *root);

#endif /* TreeNode_hpp */
