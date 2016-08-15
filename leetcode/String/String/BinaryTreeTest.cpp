//
//  BinaryTreeTest.cpp
//  String
//
//  Created by bmob-LT on 16/7/22.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include <stdio.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
#include "BinaryTree.hpp"
#include <sstream>
using namespace std;

TEST(BinaryTreeTest, maxDepth){
    TreeNode *nullTree = deserialize("{}");
    int depth1 = maxDepth(nullTree);
    EXPECT_EQ(0,depth1);
    
    TreeNode *oneTree = deserialize("{1}");
    int depth2 = maxDepth(oneTree);
    EXPECT_EQ(1, depth2);
    
    TreeNode *twoTree = deserialize("{1,2,3}");
    int depth3 = maxDepth(twoTree);
    EXPECT_EQ(2, depth3);
    
    TreeNode *leftTree = deserialize
    ("{1,2,#,3,#,4}");
    int depth4 = maxDepth(leftTree);
    EXPECT_EQ(4, depth4);
    
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    int depth5 = maxDepth(rightTree);
    EXPECT_EQ(4, depth5);
    
}

TEST(BinaryTreeTest, isBalanced){
    TreeNode *nullTree = deserialize("{}");
    EXPECT_TRUE(isBalanced(nullTree));

    
    TreeNode *oneTree = deserialize("{1}");
    EXPECT_TRUE(isBalanced(oneTree));

    
    TreeNode *oneLeftTree = deserialize("{1,2}");
    EXPECT_TRUE(isBalanced(oneLeftTree));

    
    TreeNode *oneRightTree = deserialize("{1,#,2}");
    EXPECT_TRUE(isBalanced(oneRightTree));

    
    TreeNode *leftThreeTree = deserialize("{1,2,#,3}");
    EXPECT_FALSE(isBalanced(leftThreeTree));
}

TEST(BinaryTreeTest, postorderTraversalNonrecursive){
    TreeNode *test1 = deserialize("{1,#,2,3}");
    vector<int> restul = postorderTraversalNonrecursive(test1);
}
