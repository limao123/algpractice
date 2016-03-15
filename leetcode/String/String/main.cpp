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
using namespace std;

void print(int n){
    cout<<n<< endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    MyArray.removeElent();
    int a[109]={2,0,1,2,3,4,0};
    int b[109]={0,1,0,0,0,0,11};
    vector<int> A(a,a+7);
    vector<int> B(b,b+7);
    Greedy::canCompleteCircuit(A, B);
    

    
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
