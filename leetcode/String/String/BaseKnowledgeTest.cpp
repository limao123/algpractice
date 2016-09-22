
//
//  BaseKnowledgeTest.cpp
//  String
//
//  Created by bmob-LT on 16/9/21.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include <stdio.h>
#include "gtest/gtest.h"
#include <sstream>
#include "BaseKnowledge.hpp"
using namespace std;

TEST(BaseKnowledgeTest, countOnes) {
    EXPECT_EQ(0, countOnes(0));
    
    //32 = 100000b
    EXPECT_EQ(1, countOnes(32));
    
    //5 = 101b
    EXPECT_EQ(2, countOnes(5));
    
    //3 = 11
    EXPECT_EQ(2, countOnes(3));
    
    //1023 = 1111111111b
    EXPECT_EQ(10, countOnes(1023));
}

TEST(BaseKnowledgeTest, QueueImplementByStack) {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    EXPECT_EQ(1,queue.top());
    EXPECT_EQ(1,queue.pop());
    EXPECT_EQ(2,queue.top());
    EXPECT_EQ(2,queue.pop());
}
