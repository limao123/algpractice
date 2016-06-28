//
//  TreeNode.cpp
//  String
//
//  Created by 林涛 on 16/1/23.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "TreeNode.hpp"
#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

void preOrder(TreeNode *root,stringstream &result){
    if (root == NULL) {
        return;
    }
    result << root->val << " ";
    preOrder(root->left,result);
    preOrder(root->right,result);
    
}



void preOrderNonrecursive(TreeNode *root,stringstream &result){
    if (root == NULL) {
        return;
    }
    
    stack<TreeNode *> s;
    TreeNode *temp = root;
    while (temp != NULL || !s.empty()) {
        if (temp != NULL ) {
            result << temp->val << " ";
            s.push(temp);
            temp = temp->left;
        } else {
            temp = s.top();
            s.pop();
            temp = temp->right;
        }
    }
}


void inOrder(TreeNode *root,stringstream &result){
    if (root == NULL) {
        return;
    }
    inOrder(root->left,result);
    result << root->val << " ";
    inOrder(root->right,result);
}

void inOrderNonrecursive(TreeNode *root,stringstream &result){
    if (root == NULL) {
        return;
    }
    
    stack<TreeNode *> s;
    TreeNode *temp = root;
    while (temp != NULL || !s.empty()) {
        if (temp != NULL ) {
            s.push(temp);
            temp = temp->left;
        } else {
            temp = s.top();
            s.pop();
            result << temp->val << " ";
            temp = temp->right;
        }
    }
}

void postOrder(TreeNode *root,stringstream &result){
    if (root == NULL) {
        return;
    }
    
    postOrder(root->left,result);
    postOrder(root->right,result);
    cout << root->val << " ";
}


string hierarchyOrder(TreeNode *root){
    if (root == NULL) {
        return "{}";
    }
    
    vector<TreeNode *> v;
    v.push_back(root);
    
     //将所有节点放入vector中
    for (int i = 0; i < v.size(); i++) {
        TreeNode *temp = v[i];
        if (temp == NULL) {
            continue;
        } else {
            v.push_back(temp->left);
            v.push_back(temp->right);
        }
    }
    
    //移除掉放叶子节点进vector时放入的大量空节点
    while (v[v.size()-1] == NULL) {
        v.pop_back();
    }
    
    //遍历vector打印节点值
    stringstream result;
    result << "{" << root->val;
    for (int i = 1; i < v.size(); i++) {
        TreeNode *temp = v[i];
        if (temp == NULL) {
            result << ",#";
        } else {
            result << "," << temp->val;
        }
    }
    result << "}";
    return result.str();
}



/**
 *  层次遍历序列化二叉树
 *
 *  @param root 需要序列化的二叉树的根节点
 *
 *  @return 序列化后的结果
 */
string serialize(TreeNode *root) {
    // write your code here
    if (root == NULL) {
        return "{}";
    }
    

    vector<TreeNode *> v;
    v.push_back(root);
    
    //将所有节点放入vector中
    for (int i = 0; i < v.size(); i++) {
        TreeNode *temp = v[i];
        if (temp == NULL) {
            continue;
        } else {
            v.push_back(temp->left);
            v.push_back(temp->right);
        }
    }
    
    //移除掉放叶子节点进vector时放入的大量空节点
    while (v[v.size()-1] == NULL) {
        v.pop_back();
    }
    
    //遍历vector打印节点值
    stringstream str;
    str << "{" << root->val;
    for (int i= 1; i < v.size(); i++) {
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


int split(const string& str, vector<string>& ret_, string sep = ",")
{
    if (str.empty())
    {
        return 0;
    }
    
    string tmp;
    string::size_type pos_begin = str.find_first_not_of(sep);
    string::size_type comma_pos = 0;
    
    while (pos_begin != string::npos)
    {
        comma_pos = str.find(sep, pos_begin);
        if (comma_pos != string::npos)
        {
            tmp = str.substr(pos_begin, comma_pos - pos_begin);
            pos_begin = comma_pos + sep.length();
        }
        else
        {
            tmp = str.substr(pos_begin);
            pos_begin = comma_pos;
        }
        
        if (!tmp.empty())
        {
            ret_.push_back(tmp);
            tmp.clear();
        }
    }
    return 0;
}

/**
 * This method will be invoked second, the argument data is what exactly
 * you serialized at method "serialize", that means the data is not given by
 * system, it's given by your own serialize method. So the format of data is
 * designed by yourself, and deserialize it here as you serialize it in
 * "serialize" method.
 */
TreeNode * deserialize(string data) {
    // write your code here
    if (data.compare("{}") == 0) {
        return NULL;
    }
    
    vector<TreeNode *> vNode;
    vector<string> vStr;
    split(data.substr(1,data.size()-1), vStr,",");
    TreeNode *root = new TreeNode(atoi(vStr[0].c_str()));
    vNode.push_back(root);
    int indexOfNode = 0;
    bool isLeft = true;
    for (int i = 1; i < vStr.size(); i++) {
        if (vStr[i].compare("#") != 0) {
            TreeNode *node = new TreeNode(atoi(vStr[i].c_str()));
            if (isLeft) {
                vNode[indexOfNode]->left= node;
            } else {
                vNode[indexOfNode]->right = node;
            }
            vNode.push_back(node);
        }
        
        if (!isLeft) {
            indexOfNode++;
        }
        
        isLeft = !isLeft;
    }
    
    return root;
}