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
#include "LTTest.hpp"
using namespace std;

void preOrder(TreeNode *node,stringstream &result){
    if (node == NULL) {
        return;
    }
//    stringstream os;
    result << node->val << " ";
//    result.append(os.str());
    
//    valStr
//    sprintf(valStr, "%d ",node->val);
//    result.append(valStr);
    preOrder(node->left,result);
    preOrder(node->right,result);
    
}

void testPreOrder(){
    printf("test preOrder begin--------------------------------------------\n");
    stringstream result;
    string str;
    
    TreeNode *nullTree = deserialize("{}");
    preOrder(nullTree, result);
    result >> str;
    LTTestString("", str);
    
    result.clear();
    str.clear();
    
    TreeNode *oneTree = deserialize("{1}");
    preOrder(oneTree, result);
    result >> str;
    LTTestString("1 ", result.str());
    
    result.clear();
    str.clear();
    
    TreeNode *twoTree = deserialize("{1,2,3}");
    preOrder(twoTree, result);
    result >> str;
    LTTestString("2 1 3 ", str);
    printf("test preOrder end----------------------------------------------\n");
}


void inOrder(TreeNode *node){
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}

void postOrder(TreeNode *node){
    if (node == NULL) {
        return;
    }
    
    postOrder(node->left);
    postOrder(node->right);
    cout << node->val << " ";
}

/**
 * This method will be invoked first, you should design your own algorithm
 * to serialize a binary tree which denote by a root node to a string which
 * can be easily deserialized by your own "deserialize" method later.
 */
string serialize(TreeNode *root) {
    // write your code here
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
    
    while (v[v.size()-1] == NULL) {
        v.pop_back();
    }
    
    string result = "{";
    for (int i = 0; i < v.size(); i++) {
        TreeNode *temp = v[i];
        if (temp == NULL) {
            result.append(",#");
        } else {
            result.append(",");
            char val[64];
            sprintf(val, "%d",temp->val);
            result.append(val);
        }
    }
    result.append("}");
    return result;
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