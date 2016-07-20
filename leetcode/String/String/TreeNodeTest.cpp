//
//  TreeNodeTest.cpp
//  String
//
//  Created by bmob-LT on 16/7/20.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include <stdio.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
#include <sstream>
using namespace std;

//class TreeNodeTest:public testing::Test{
//protected:
//    virtual void SetUp(){
//        
//    }
//    virtual void TearDown(){
//        
//    }
//    
//};

TEST(TreeNodeTest, PreOrder) {
    stringstream result;
    TreeNode *nullTree = deserialize("{}");
    preOrder(nullTree, result);
    EXPECT_STREQ("", result.str().c_str());
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    preOrder(oneTree, result);
    EXPECT_STREQ("1 ", result.str().c_str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    preOrder(twoTree, result);
    EXPECT_STREQ("1 2 3 ", result.str().c_str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    preOrder(leftTree, result);
    EXPECT_STREQ("1 2 3 4 ", result.str().c_str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    preOrder(rightTree, result);
    EXPECT_STREQ("1 2 3 4 ", result.str().c_str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    preOrder(threeTree, result);
    EXPECT_STREQ("1 2 4 5 3 6 7 ", result.str().c_str());
}

TEST(TreeNodeTest, PreOrderNonrecursive){
    stringstream result;

    TreeNode *nullTree = deserialize("{}");
    preOrderNonrecursive(nullTree, result);
    EXPECT_STREQ("", result.str().c_str());
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    preOrderNonrecursive(oneTree, result);
    EXPECT_STREQ("1 ", result.str().c_str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    preOrderNonrecursive(twoTree, result);
    EXPECT_STREQ("1 2 3 ", result.str().c_str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    preOrderNonrecursive(leftTree, result);
    EXPECT_STREQ("1 2 3 4 ", result.str().c_str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    preOrderNonrecursive(rightTree, result);
    EXPECT_STREQ("1 2 3 4 ", result.str().c_str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    preOrderNonrecursive(threeTree, result);
    EXPECT_STREQ("1 2 4 5 3 6 7 ", result.str().c_str());
}

TEST(TreeNodeTest, InOrder){
    stringstream result;

    TreeNode *nullTree = deserialize("{}");
    inOrder(nullTree, result);
    EXPECT_STREQ("", result.str().c_str());
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    inOrder(oneTree, result);
    EXPECT_STREQ("1 ", result.str().c_str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    inOrder(twoTree, result);
    EXPECT_STREQ("2 1 3 ", result.str().c_str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    inOrder(leftTree, result);
    EXPECT_STREQ("4 3 2 1 ", result.str().c_str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    inOrder(rightTree, result);
    EXPECT_STREQ("1 2 3 4 ", result.str().c_str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    inOrder(threeTree, result);
    EXPECT_STREQ("4 2 5 1 6 3 7 ", result.str().c_str());
}

TEST(TreeNodeTest, InOrderNonrecursive){
    stringstream result;
    
    TreeNode *nullTree = deserialize("{}");
    inOrderNonrecursive(nullTree, result);
    EXPECT_STREQ("", result.str().c_str());
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    inOrderNonrecursive(oneTree, result);
    EXPECT_STREQ("1 ", result.str().c_str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    inOrderNonrecursive(twoTree, result);
    EXPECT_STREQ("2 1 3 ", result.str().c_str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    inOrderNonrecursive(leftTree, result);
    EXPECT_STREQ("4 3 2 1 ", result.str().c_str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    inOrderNonrecursive(rightTree, result);
    EXPECT_STREQ("1 2 3 4 ", result.str().c_str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    inOrderNonrecursive(threeTree, result);
    EXPECT_STREQ("4 2 5 1 6 3 7 ", result.str().c_str());
}


TEST(TreeNodeTest, PostOrder){
    stringstream result;
    
    TreeNode *nullTree = deserialize("{}");
    postOrder(nullTree, result);
    EXPECT_STREQ("", result.str().c_str());
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    postOrder(oneTree, result);
    EXPECT_STREQ("1 ", result.str().c_str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    postOrder(twoTree, result);
    EXPECT_STREQ("2 3 1 ", result.str().c_str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    postOrder(leftTree, result);
    EXPECT_STREQ("4 3 2 1 ", result.str().c_str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    postOrder(rightTree, result);
    EXPECT_STREQ("4 3 2 1 ", result.str().c_str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    postOrder(threeTree, result);
    EXPECT_STREQ("4 5 2 6 7 3 1 ", result.str().c_str());
}

TEST(TreeNodeTest, PostOrderNonrecursive){
    stringstream result;
    
    TreeNode *nullTree = deserialize("{}");
    postOrderNonrecursive(nullTree, result);
    EXPECT_STREQ("", result.str().c_str());
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    postOrderNonrecursive(oneTree, result);
    EXPECT_STREQ("1 ", result.str().c_str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    postOrderNonrecursive(twoTree, result);
    EXPECT_STREQ("2 3 1 ", result.str().c_str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    postOrderNonrecursive(leftTree, result);
    EXPECT_STREQ("4 3 2 1 ", result.str().c_str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    postOrderNonrecursive(rightTree, result);
    EXPECT_STREQ("4 3 2 1 ", result.str().c_str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    postOrderNonrecursive(threeTree, result);
    EXPECT_STREQ("4 5 2 6 7 3 1 ", result.str().c_str());
}

TEST(TreeNodeTest, HierarchyOrder){
    TreeNode *root1 = NULL;
    string str1 = hierarchyOrder(root1);
    EXPECT_STREQ("{}", str1.c_str());
    
    TreeNode *root2 = new TreeNode(1);
    TreeNode *second1 = new TreeNode(2);
    TreeNode *second2 = new TreeNode(3);
    root2->left = second1;
    root2->right = second2;
    TreeNode *third1 = new TreeNode(4);
    TreeNode *third2 = new TreeNode (5);
    second1->left = third1;
    second2->right = third2;
    string str2 = serialize(root2);
    EXPECT_STREQ("{1,2,3,4,#,#,5}", str2.c_str());
}

TEST(TreeNodeTest,Serialize){
    TreeNode *root1 = NULL;
    string str1 = serialize(root1);
    EXPECT_STREQ("{}", str1.c_str());
    
    TreeNode *root2 = new TreeNode(1);
    TreeNode *second1 = new TreeNode(2);
    TreeNode *second2 = new TreeNode(3);
    root2->left = second1;
    root2->right = second2;
    TreeNode *third1 = new TreeNode(4);
    TreeNode *third2 = new TreeNode (5);
    second1->left = third1;
    second2->right = third2;
    string str2 = serialize(root2);
    EXPECT_STREQ("{1,2,3,4,#,#,5}", str2.c_str());
}