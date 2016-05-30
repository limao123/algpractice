//
//  LinkedList.cpp
//  String
//
//  Created by bmob-LT on 16/3/19.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "LinkedList.hpp"
#include "TreeNode.hpp"

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

/**
 * @param ListNode l1 is the head of the linked list
 * @param ListNode l2 is the head of the linked list
 * @return: ListNode head of linked list
 */
ListNode *LinkedList::mergeTwoLists(ListNode *l1, ListNode *l2) {
    // write your code here
    if (l1 == NULL ) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }
    
    ListNode *l3;
    ListNode *head;
    if (l1->val < l2->val) {
        head = l3 = l1;
        l1 = l1->next;
    } else {
        head = l3 = l2;
        l2 = l2->next;
    }
    
    while (l1 != NULL && l2 != NULL) {
        while (l1!= NULL && l2 != NULL && l1->val < l2->val) {
            l3->next = l1;
            l3 = l3->next;
            l1 = l1->next;
        }
        
        while (l1 != NULL && l2 != NULL && l1->val >= l2->val) {
            l3->next = l2;
            l3 = l3->next;
            l2 = l2->next;
        }
    }
    
    if (l1 != NULL) {
        l3->next = l1;
    } else if(l2 != NULL){
        l3->next = l2;
    }
    return head;
}

/**
 * @param head: The first node of linked list.
 * @return: head node
 */
ListNode *LinkedList::deleteDuplicates(ListNode *head) {
    // write your code here
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode *i1 = head;
    ListNode *i2 = head->next;
    while (i2 != NULL) {
        if (i1->val == i2->val) {
            ListNode *tmp = i2;
            i2 = i2->next;
            i1->next = i2;
            free(tmp);
        } else {
            i1 = i2;
            i2 = i2->next;
        }
    }
    return head;
}

/**
 * @param head: The first node of linked list.
 * @param x: an integer
 * @return: a ListNode
 */
ListNode *LinkedList::partition(ListNode *head, int x) {
    // write your code here
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode *index; //遍历链表
    ListNode *p; //在第一个>=x的节点之前
    //找到头节点
    if (head->val < x) {
        //头节点小于x的情况
        ListNode *tmp = head;
        while (tmp->next != NULL && tmp->next->val < x) {
            tmp = tmp->next;
        }
        
        if (tmp ->next == NULL) {
            return head;
        } else {
            p = tmp;
            index = p->next;
        }
        
    } else {
        //头节点>=x的情况，需要找到头节点
        ListNode *tmp = head;
        while (tmp->next != NULL && tmp->next->val >= x) {
            tmp = tmp->next;
        }
        
        if (tmp->next == NULL) {
            //所有节点都大于等于x
            return head;
        } else {
            //找到第一个小于x的节点，取代当前头节点
            index = tmp;
            tmp = tmp->next;
            index->next = tmp->next;
            tmp->next = head;
            p = head = tmp;
        }
    }
    
    //遍历，找到所有小于x的节点并放在正确的位置
    while (index->next != NULL) {
        if (index->next->val < x) {
            ListNode *tmp = index->next;
            index->next = tmp->next;
            tmp->next = p->next;
            p->next = tmp;
            p = p->next;
        } else {
            index = index->next;
        }
    }
    
    return head;
}

/**
 * @param head: the list
 * @param k: rotate to the right k places
 * @return: the list after rotation
 */
ListNode *LinkedList::rotateRight(ListNode *head, int k) {
    // write your code here
    if (k <= 0 || head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode *index = head;
    unsigned count = 1;
    while (index->next != NULL) {
        count++;
        index = index->next;
    }
    
    //注意还有一种特殊情况，就是不需要移动时的处理
    if (k%count == 0) {
        return head;
    }
    
    unsigned move = count - (unsigned)k % count;
    ListNode *newEnd = head;
    
    for (unsigned i = 1; i < move; i++) {
        newEnd = newEnd->next;
    }
    
    ListNode *newHead = newEnd->next;
    newEnd->next = NULL;
    index->next = head;
    return newHead;
}

void insertNode(RandomListNode *head){
    RandomListNode *node = head;
    while (node != NULL) {
        RandomListNode *newNode = new RandomListNode(node->label);
        newNode->next = node->next;
        node->next = newNode;
        node = newNode->next;
    }
}

void connectRandomNode(RandomListNode *head){
    RandomListNode *node = head;
    while(node != NULL){
        RandomListNode *newNode;
        newNode = node->next;
        if(node->random != NULL){
            newNode->random = node->random->next;
        }
        node = newNode->next;
    }
}

RandomListNode *separateNode(RandomListNode *head){
    //确定头
    RandomListNode *newHead = head->next;
    RandomListNode *node = newHead->next;
    RandomListNode *newNode = newHead;
    while (node != NULL) {
        newNode->next = node->next;
        newNode = newNode->next;
        node->next = newNode->next;
        node = node->next;
    }
    return newHead;
}

/**
 * @param head: The head of linked list with a random pointer.
 * @return: A new head of a deep copy of the list.
 */
RandomListNode *LinkedList::copyRandomList(RandomListNode *head) {
    // write your code here
    if (head == NULL) {
        return NULL;
    }
    insertNode(head);
    connectRandomNode(head);
    return separateNode(head);
}

/**
 * @param head: The first node of linked list.
 * @return: True if it has a cycle, or false
 */
bool LinkedList::hasCycle(ListNode *head) {
    // write your code here
    if (head == NULL || head->next == NULL) {
        return false;
    }
    
    ListNode *p = head;
    ListNode *q = head;
    while (p != q) {
        p = p->next;
        if (q != NULL && q ->next != NULL) {
            q = q -> next -> next;
        } else {
            return false;
        }
    }
    return true;
}

/**
 * @param head: The first node of linked list.
 * @return: void
 */
void LinkedList::reorderList(ListNode *head) {
    // write your code here
    if (head == NULL || head->next == NULL) {
        return;
    }
    
    //找到链表中间位置
    int len = 0;
    ListNode *index = head;
    while (index != NULL) {
        len++;
        index = index->next;
    }
    
    int len1 = (len%2==0)?len/2:len/2+1;
    ListNode *head1 = head;
    ListNode *head2 = head;
    index = head;
    for (int i = 0; i < len1-1; i++) {
        head2 = head2->next;
    }
    //此时head2已经在head1最后一个结点
    ListNode *temp = head2;
    head2 = head2->next;
    temp->next = NULL;
    
    //反转反半部分链表
    ListNode *newHead2;
    if (head2->next == NULL) {
        newHead2 = head2;
    } else if(head2->next->next == NULL){
        ListNode *temp = head2->next;
        temp->next = head2;
        head2->next = NULL;
        newHead2 = temp;
    } else {
        ListNode *i1 = head2;
        ListNode *i2 = i1->next;
        ListNode *i3 = i2->next;
        i1->next = NULL;
        while (i3!=NULL) {
            i2->next = i1;
            i1 = i2;
            i2 = i3;
            i3 = i3->next;
        }
        i2->next = i1;
        newHead2 = i2;
    }
    
    //连接
    ListNode *i1 = head1;
    ListNode *i2 = newHead2;
    while (i1 != NULL && i2 != NULL) {
        ListNode *temp = i1;
        i1 = i1->next;
        temp->next = i2;
        temp = i2;
        i2 = i2->next;
        temp->next = i1;
    }
}

/**
 * @param head: The first node of linked list.
 * @return: a tree node
 */
TreeNode *sortedListToBST(ListNode *head) {
    // write your code here
    return NULL;
}

void partition(ListNode *head){
    if (head == NULL || head->next == NULL) {
        return;
    }
    
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && slow != NULL){
        while (slow->next != NULL && slow->next->val < head->val) {
            slow = slow->next;
        }
        
        if (fast == head) {
            fast = slow->next;
        }

        while (fast != NULL && fast->val >= head->val) {
            fast = fast->next;
        }
        
        if(fast != NULL && slow ->next != NULL){
        int tmp = slow->next->val;
        slow->next->val = fast->val;
        fast->val = tmp;
        }
    }
    
    if (head != slow) {
        int tmp = slow->val;
        slow->val = head->val;
        head->val = tmp;
    }
    partition(head->next);
    partition(slow->next);
    
    
}

/**
 * @param head: The first node of linked list.
 * @return: You should return the head of the sorted linked list,
 using constant space complexity.
 */
ListNode * LinkedList::sortList(ListNode *head) {
    // write your code here
    ::partition(head);
    return head;
    
}

TreeNode * LinkedList::sortedListToBST(ListNode *head) {
    // write your code here
    if (head == NULL) {
        return NULL;
    }
    
    int len = 0;
    ListNode *index = head;
    while (index != NULL) {
        len++;
        index = index->next;
    }
    
    TreeNode *tree;
    if (len == 1) {
        tree = new TreeNode(head->val);
    } else {
        index = head;
        for (int i = 1; i < len/2; i++) {
            index = index->next;
        }
        ListNode *temp = index->next;
        index->next = NULL;
        tree = new TreeNode(temp->val);
        tree->left = sortedListToBST(head);
        tree->right = sortedListToBST(temp->next);
        free(temp);
    }
    return tree;
}