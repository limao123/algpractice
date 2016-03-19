//
//  ListNode.cpp
//  String
//
//  Created by 林涛 on 16/1/22.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "ListNode.hpp"

void ListNode::printList(ListNode *head){
    while (head != NULL) {
        printf("%d->",head->val);
        head = head->next;
    }
    printf("NULL\n");
}

ListNode* ListNode::creatList(int num[], int size){
    
    ListNode *head = new ListNode(num[0]);
    ListNode *tmp = head;
    for (int i = 1; i < size; i++) {
        ListNode *node = new ListNode(num[i]);
        tmp -> next = node;
        tmp = tmp -> next;
    }
    return head;
}