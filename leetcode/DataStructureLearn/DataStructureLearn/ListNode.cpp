//
//  ListNode.cpp
//  DataStructureLearn
//
//  Created by bmob-LT on 16/3/28.
//  Copyright © 2016年 bmob-LT. All rights reserved.
//

#include "ListNode.hpp"

List MakeEmpty(List L){
    DeleteList(L);
    return L;
}

int IsEmpty(List L){
    return L->Next == NULL; 
}


int IsLast(Position P,List L){
    return P->Next == NULL;
}

Position Find(ElementType X,List L){
    Position P = L->Next;
    while (P !=  NULL && P->Element != X) {
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L){
    Position P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        Position tmp = P->Next;
        P->Next = tmp->Next;
        delete tmp;
    }
}

//如果没有前驱元，则会返回尾结点
Position FindPrevious(ElementType X, List L){
    Position P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

void Insert(ElementType X, List L, Position P){
    //结构体，类似对象
    struct Node node = {X, NULL};
    //指向结构体的指针
    Position nodePos = &node;
    Position pre = FindPrevious(P->Element, L);
    nodePos->Next = pre->Next;
    pre->Next = nodePos;
}

void DeleteList(List L){
    Position P = L->Next;
    while (P != NULL) {
        Position tmp = P;
        P = P->Next;
        delete tmp;
    }
}

Position Header(List L){
    return L;
}

Position First(List L){
    return L->Next;
}

Position Advance(Position P){
    if (P != NULL) {
        return P->Next;
    } else {
        return NULL;
    }
}

ElementType Retrieve(Position P){
    if (P != NULL) {
        return P->Element;
    } else {
        return __INT_MAX__;
    }
}