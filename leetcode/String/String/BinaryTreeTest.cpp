//
//  BinaryTreeTest.cpp
//  String
//
//  Created by bmob-LT on 16/7/22.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "BinaryTreeTest.hpp"


void testMaxDepth(){
    printf("test maxDepth begin--------------------------------------------\n");
    TreeNode *nullTree = deserialize("{}");
    int depth1 = maxDepth(nullTree);
    LTTest(0, depth1);
    
    TreeNode *oneTree = deserialize("{1}");
    int depth2 = maxDepth(oneTree);
    LTTest(1, depth2);
    
    TreeNode *twoTree = deserialize("{1,2,3}");
    int depth3 = maxDepth(twoTree);
    LTTest(2, depth3);
    
    TreeNode *leftTree = deserialize
    ("{1,2,#,3,#,4}");
    int depth4 = maxDepth(leftTree);
    LTTest(4, depth4);
    
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    int depth5 = maxDepth(rightTree);
    LTTest(4, depth5);
    
    printf("test maxDepth end----------------------------------------------\n");
}
