//
//  Stack.cpp
//  DataStructureLearn
//
//  Created by bmob-LT on 16/4/11.
//  Copyright © 2016年 bmob-LT. All rights reserved.
//

#include "Stack.hpp"

int isEmpty(Stack s){
    return s->next == NULL;
}

Stack createStack(){
    
}

void disposeStack(Stack s);
void makeEmpty(Stack s);
void Push(ElementType x,Stack s);
ElementType top(Stack s);
void pop(Stack s);