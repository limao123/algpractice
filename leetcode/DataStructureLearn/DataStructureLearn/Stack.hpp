//
//  Stack.hpp
//  DataStructureLearn
//
//  Created by bmob-LT on 16/4/11.
//  Copyright © 2016年 bmob-LT. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int isEmpty(Stack s);
Stack createStack();
void disposeStack(Stack s);
void makeEmpty(Stack s);
void Push(ElementType x,Stack s);
ElementType top(Stack s);
void pop(Stack s);

struct Node{
    ElementType element;
    PtrToNode next;
};

#endif /* Stack_hpp */
