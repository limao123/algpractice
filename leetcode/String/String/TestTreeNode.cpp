//
//  TestTreeNode.cpp
//  String
//
//  Created by bmob-LT on 16/6/28.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "TestTreeNode.hpp"
#include "LTTest.hpp"
#include <iostream>
#include <sstream>
using namespace std;

void testPreOrder(){
    printf("test preOrder begin--------------------------------------------\n");
    stringstream result;
    string str;
    
    TreeNode *nullTree = deserialize("{}");
    preOrder(nullTree, result);
    LTTestString("", str);
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    preOrder(oneTree, result);
    LTTestString("1 ", result.str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    preOrder(twoTree, result);
    LTTestString("1 2 3 ", result.str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    preOrder(leftTree, result);
    LTTestString("1 2 3 4 ", result.str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    preOrder(rightTree, result);
    LTTestString("1 2 3 4 ", result.str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    preOrder(threeTree, result);
    LTTestString("1 2 4 5 3 6 7 ", result.str());
    printf("test preOrder end----------------------------------------------\n");
}

void testPreOrderNonrecursive(){
    printf("test preOrderNonrecursive begin--------------------------------\n");
    stringstream result;
    string str;
    
    TreeNode *nullTree = deserialize("{}");
    preOrderNonrecursive(nullTree, result);
    LTTestString("", str);
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    preOrderNonrecursive(oneTree, result);
    LTTestString("1 ", result.str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    preOrderNonrecursive(twoTree, result);
    LTTestString("1 2 3 ", result.str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    preOrderNonrecursive(leftTree, result);
    LTTestString("1 2 3 4 ", result.str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    preOrderNonrecursive(rightTree, result);
    LTTestString("1 2 3 4 ", result.str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    preOrderNonrecursive(threeTree, result);
    LTTestString("1 2 4 5 3 6 7 ", result.str());
    printf("test preOrderNonrecursive end----------------------------------\n");
}

void testInOrder(){
    printf("test inOrder begin---------------------------------------------\n");
    stringstream result;
    string str;
    
    TreeNode *nullTree = deserialize("{}");
    inOrder(nullTree, result);
    LTTestString("", str);
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    inOrder(oneTree, result);
    LTTestString("1 ", result.str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    inOrder(twoTree, result);
    LTTestString("2 1 3 ", result.str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    inOrder(leftTree, result);
    LTTestString("4 3 2 1 ", result.str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    inOrder(rightTree, result);
    LTTestString("1 2 3 4 ", result.str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    inOrder(threeTree, result);
    LTTestString("4 2 5 1 6 3 7 ", result.str());
    printf("test inOrder end-----------------------------------------------\n");
}

void testInOrderNonrecursive(){
    printf("test inOrderNonrecursive begin---------------------------------\n");
    stringstream result;
    string str;
    
    TreeNode *nullTree = deserialize("{}");
    inOrderNonrecursive(nullTree, result);
    LTTestString("", str);
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    inOrderNonrecursive(oneTree, result);
    LTTestString("1 ", result.str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    inOrderNonrecursive(twoTree, result);
    LTTestString("2 1 3 ", result.str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    inOrderNonrecursive(leftTree, result);
    LTTestString("4 3 2 1 ", result.str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    inOrderNonrecursive(rightTree, result);
    LTTestString("1 2 3 4 ", result.str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    inOrderNonrecursive(threeTree, result);
    LTTestString("4 2 5 1 6 3 7 ", result.str());
    printf("test inOrderNonrecursive end-----------------------------------\n");
}

void testPostOrder(){
    printf("test postOrder begin-------------------------------------------\n");
    stringstream result;
    string str;
    
    TreeNode *nullTree = deserialize("{}");
    postOrder(nullTree, result);
    LTTestString("1", str);
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    postOrder(oneTree, result);
    LTTestString("1 ", result.str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    postOrder(twoTree, result);
    LTTestString("2 3 1 ", result.str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    postOrder(leftTree, result);
    LTTestString("4 3 2 1 ", result.str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    postOrder(rightTree, result);
    LTTestString("4 3 2 1 ", result.str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    postOrder(threeTree, result);
    LTTestString("4 5 2 6 7 3 1 ", result.str());
    printf("test postOrder end---------------------------------------------\n");
}

void testPostOrderNonrecursive(){
    printf("test postOrderNonrecursive begin-------------------------------\n");
    stringstream result;
    string str;
    
    TreeNode *nullTree = deserialize("{}");
    postOrderNonrecursive(nullTree, result);
    LTTestString("", str);
    
    result.str("");
    TreeNode *oneTree = deserialize("{1}");
    postOrderNonrecursive(oneTree, result);
    LTTestString("1 ", result.str());
    
    result.str("");
    TreeNode *twoTree = deserialize("{1,2,3}");
    postOrderNonrecursive(twoTree, result);
    LTTestString("2 3 1 ", result.str());
    
    result.str("");
    TreeNode *leftTree = deserialize("{1,2,#,3,#,4}");
    postOrderNonrecursive(leftTree, result);
    LTTestString("4 3 2 1 ", result.str());
    
    result.str("");
    TreeNode *rightTree = deserialize("{1,#,2,#,3,#,4}");
    postOrderNonrecursive(rightTree, result);
    LTTestString("4 3 2 1 ", result.str());
    
    result.str("");
    TreeNode *threeTree = deserialize("{1,2,3,4,5,6,7}");
    postOrderNonrecursive(threeTree, result);
    LTTestString("4 5 2 6 7 3 1 ", result.str());
    printf("test postOrderNonrecursive end---------------------------------\n");
}

void testHierarchyOrder(){
    printf("test hierarchyOrder begin--------------------------------------\n");
    
    TreeNode *root1 = NULL;
    string str1 = hierarchyOrder(root1);
    LTTestString("{}", str1);
    
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
    LTTestString("{1,2,3,4,#,#,5}", str2);
    
    printf("test hierarchyOrder end----------------------------------------\n");
}

void testSerialize() {
    printf("test serialize begin-------------------------------------------\n");
    
    TreeNode *root1 = NULL;
    string str1 = serialize(root1);
    LTTestString("{}", str1);
    
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
    LTTestString("{1,2,3,4,#,#,5}", str2);
    
    printf("test serialize end---------------------------------------------\n");
}
