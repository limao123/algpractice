//
//  BaseKnowledge.hpp
//  String
//
//  Created by 林涛 on 16/1/22.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef BaseKnowledge_hpp
#define BaseKnowledge_hpp

#include <stdio.h>
#include <vector>
#include "ListNode.hpp"
#include <stack>
#include "TreeNode.hpp"
#include "DoublyListNode.hpp"
using namespace std;

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder);
int countOnes(int num);


class BaseKnowledge {
    

//private:
//    BaseKnowledge(){
//    }
//    
//    static BaseKnowledge *m_pInstance;
    
public:    
//    static BaseKnowledge* getInstance();
    static int searchMatrix(vector<vector<int> > &matrix, int target);
    static int replaceBlank(char string[], int length);
    static ListNode *reverse(ListNode *head);
    static int fibonacci(int n);
    static int countOnes(int num);
    static int findMin(vector<int> &num);
    static DoublyListNode* bstToDoublyList(TreeNode* root);
};
#endif /* BaseKnowledge_hpp */
