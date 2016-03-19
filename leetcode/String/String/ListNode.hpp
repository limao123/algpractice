//
//  ListNode.hpp
//  String
//
//  Created by 林涛 on 16/1/22.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>

class ListNode {
public:
    int val;
    ListNode *next;
    
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
    
    static void printList(ListNode *head);
    static ListNode* creatList(int num[],int size);
};

#endif /* ListNode_hpp */
