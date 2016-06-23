//
//  TreeNode.hpp
//  DataStructureLearn
//
//  Created by 林涛 on 16/6/23.
//  Copyright © 2016年 bmob-LT. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

typedef struct TreeNode *PtrToNode;

struct TreeNode{
    int element;
    PtrToNode firstChile;
    PtrToNode nextSilbing;
};

#endif /* TreeNode_hpp */
