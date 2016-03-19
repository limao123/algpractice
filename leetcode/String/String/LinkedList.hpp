//
//  LinkedList.hpp
//  String
//
//  Created by bmob-LT on 16/3/19.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "ListNode.hpp"
using namespace std;

class LinkedList{
public:
    static ListNode *removeNthFromEnd(ListNode *head, int n);
};

#endif /* LinkedList_hpp */
