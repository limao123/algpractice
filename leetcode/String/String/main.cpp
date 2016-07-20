//
//  main.cpp
//  String
//
//  Created by 林涛 on 16/1/18.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include <iostream>
#include "SwapString.hpp"
#include "MyArray.hpp"
#include "BaseKnowledge.hpp"
#include "ListNode.hpp"
#include "TreeNode.hpp"
#include "BinarySearch.hpp"
#include "Greedy.hpp"
#include <string>
#include "LinkedList.hpp"
#include "BinaryTree.hpp"
#include "gtest/gtest.h"


using namespace std;

//#include "gtest/gtest.h"

int Factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

//TEST(FactorialTest, Negative) {
//    // This test is named "Negative", and belongs to the "FactorialTest"
//    // test case.
//    EXPECT_EQ(1, Factorial(-5));
//    EXPECT_EQ(1, Factorial(-1));
//    EXPECT_GT(Factorial(-10), 0);
//}

void print(int n){
    cout<<n<< endl;
}

void testLinkedList(){
    //removeNthFromEnd
//    int a[] = {1,2,3,4,5};
//    ListNode *head = ListNode::creatList(a, 5);
//    head = LinkedList::removeNthFromEnd(head, 2);
//    ListNode::printList(head);
    
    //mergeTwoLists
//    int a[] = {1,3,8,11,15};
//    int b[] = {2};
//    ListNode *l1 = ListNode::creatList(a, 5);
//    ListNode *l2 = ListNode::creatList(b, 1);
//    ListNode *result = LinkedList::mergeTwoLists(l1, l2);
//    ListNode::printList(result);
    
//    deleteDuplicates
//    int a[] = {1,1,2,3,3};
//    ListNode *head = ListNode::creatList(a, 5);
//    ListNode *result = LinkedList::deleteDuplicates(head);
//    ListNode::printList(result);
    
    //partition
//    int a[] = {3,3,1,2,4};
//    ListNode *head = ListNode::creatList(a, 5);
//    ListNode *result = LinkedList::partition(head, 3);
//    ListNode::printList(result);
    
//    rotateRight
//    int a[] = {1,2,3,4,5};
//    ListNode *head = ListNode::creatList(a, 5);
//    ListNode *result = LinkedList::rotateRight(head, 2);
//    ListNode::printList(result);
    
//    copyRandomList
//    RandomListNode *head = new RandomListNode(-1);
////    *head = node;
////    head＝ &node;
//    LinkedList::copyRandomList(head);
    
    //reorderList
//    int a[] = {0,1,2,3,4,5};
//    ListNode *head = ListNode::creatList(a, 6);
//    LinkedList::reorderList(head);
//    ListNode::printList(head);
}

void testLinkedListSort(){
    //sort
    ListNode *head1 = NULL;
    ListNode *result1 = LinkedList::sortList(head1);
    ListNode::printList(result1);
    
    int listAry2[] = {1};
    ListNode *head2 = ListNode::creatList(listAry2,1);
    ListNode *result2 = LinkedList::sortList(head2);
    ListNode::printList(result2);
    
    int listAry3[] = {1,2};
    ListNode *head3 = ListNode::creatList(listAry3,2);
    ListNode *result3 = LinkedList::sortList(head3);
    ListNode::printList(result3);
    
    int listAry4[] = {2,1};
    ListNode *head4 = ListNode::creatList(listAry4,2);
    ListNode *result4 = LinkedList::sortList(head4);
    ListNode::printList(result4);
    
    int listAry5[] = {1,1,1};
    ListNode *head5 = ListNode::creatList(listAry5,3);
    ListNode *result5 = LinkedList::sortList(head5);
    ListNode::printList(result5);
    
    int listAry6[] = {3,5,8,4,2,1};
    ListNode *head6 = ListNode::creatList(listAry6,6);
    ListNode *result6 = LinkedList::sortList(head6);
    ListNode::printList(result6);
    
    int listAry7[] = {2,-1,0};
    ListNode *head7 = ListNode::creatList(listAry7,3);
    ListNode *result7 = LinkedList::sortList(head7);
    ListNode::printList(result7);
}

void testSortedListToBST() {
    
}

void testLevelOrder() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    vector<vector<int>> result = levelOrder(root);
}

void testSearchRange() {
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    vector<int> result = searchRange(root, 10, 22);
}



int main(int argc,char ** argv) {
//    testing::AddGlobalTestEnvironment(new TestTreeNode);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
//    testLinkedList();
//    testLinkedList();
//    testLinkedListSort();
    // insert code here...
//    MyArray.removeElent();
//    int a[109]={2,3,1,1,4};
//    int b[109]={0,1,0,0,0,0,11};
//    vector<int> B(b,b+7);
//    Greedy::canCompleteCircuit(A, B);
//    string a = "178542";
//    Greedy::DeleteDigits(a, 4);

    
//    BinarySearch::sqrt(999999999);
//
//    vector<vector<int> > results = MyArray::threeSum(A);
//    for (auto result:results) {
//        for_each(result.begin(), result.end(), print);
//    }
//    vector<int> result = MyArray::twoSum(A, -1);
//    vector<int>::iterator iter;
//    for_each(result.begin(),result.end(),print);
    
//    int result = MyArray::firstMissingPositive(A);
//    cout << result << endl;
//    for_each(A.begin(),A.end(),print);
    
//    BaseKnowledge *A = BaseKnowledge::getInstance();
//    BaseKnowledge *B = BaseKnowledge::getInstance();
//    cout << A << endl;
//    cout << B << endl;
    
//    ListNode *head = new ListNode(1);
//    head -> next = new ListNode(2);
//    
//    ListNode *newHead = BaseKnowledge::reverse(head);
//    while (newHead != NULL) {
//        cout << newHead->val;
//        newHead = newHead->next;
//    }
//    vector<int> pre;
//    pre.push_back(1);
//    pre.push_back(2);
//    
//    TreeNode *treeNode = BaseKnowledge::buildTree(pre, pre);
//    cout << treeNode << endl;
    
//    testLinkedListSort();
//    testLevelOrder();
//    testSearchRange();
//    testSerialize();
//    testMaxDepth();
//    testMinDepth();
//    testPreOrder();
//    testIsBalanced();
//    testSerialize();
//    testHierarchyOrder();
//    testPreOrderNonrecursive();
//    testInOrder();
//    testInOrderNonrecursive();
//    testPostOrder();
//    testPostOrderNonrecursive();
//    return 0;
}
