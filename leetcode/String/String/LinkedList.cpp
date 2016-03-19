//
//  LinkedList.cpp
//  String
//
//  Created by bmob-LT on 16/3/19.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "LinkedList.hpp"

/**
 * @param head: The first node of linked list.
 * @param n: An integer.
 * @return: The head of linked list.
 */
ListNode * LinkedList::removeNthFromEnd(ListNode *head, int n) {
    // write your code here
    if (head == NULL || n <= 0) {
        return head;
    }
    
    ListNode *index = head;
    int count = 0;
    while (index != NULL) {
        count++;
        index = index -> next;
    }
    
    int targetIndex = count - n;
    if (targetIndex < 0) {
        return NULL;
    } else if( targetIndex == 0){
        //特殊情况，删除头节点
        ListNode *node = head -> next;
        free(head);
        return node;
    }
    
    index = head;
    for (int i = 1; i < targetIndex; i++) {
        index = index -> next;
    }
    
    ListNode *tmp = index -> next;
    index -> next = tmp -> next;
    free(tmp);
    
    return head;
}