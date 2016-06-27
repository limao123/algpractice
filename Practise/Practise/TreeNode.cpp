//
//  TreeNode.cpp
//  Practise
//
//  Created by bmob-LT on 16/6/27.
//  Copyright © 2016年 bmob-LT. All rights reserved.
//

#include "TreeNode.hpp"
string serialize(TreeNode *root){
    if (root == NULL) {
        return "{}";
    }
    
    vector<TreeNode *> v;
    v.push_back(root);
    
    for (int i = 0; i < v.size(); i++) {
        TreeNode *temp = v[i];
        if (temp == NULL) {
            continue;
        } else {
            v.push_back(temp->left);
            v.push_back(temp->right);
        }
    }
    
    while (v[v.size()-1] != NULL) {
        v.pop_back();
    }
    
    stringstream str;
    str << "{" << root->val;
    for (int i= 1; i < v.size()-1; i++) {
        TreeNode *temp = v[i];
        if (temp == NULL) {
            str << ",#";
        } else {
            str << "," << temp->val ;
        }
    }
    str << "}";
    return str.str();
}