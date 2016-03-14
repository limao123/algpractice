//
//  DoublyListNode.hpp
//  String
//
//  Created by 林涛 on 16/2/28.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef DoublyListNode_hpp
#define DoublyListNode_hpp

#include <stdio.h>

class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int val) {
        this->val = val;
        this->prev = this->next = NULL;
    }
};

#endif /* DoublyListNode_hpp */
