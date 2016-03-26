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
using namespace std;

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
    int a[] = {0,1,2,3,4,5};
    ListNode *head = ListNode::creatList(a, 6);
    LinkedList::reorderList(head);
    ListNode::printList(head);
}

int main(int argc, const char * argv[]) {
    testLinkedList();
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
    
    
    return 0;
}
