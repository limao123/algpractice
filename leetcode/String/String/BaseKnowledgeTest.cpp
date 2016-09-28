
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

TEST(BaseKnowledgeTest, findMin) {
    //无重复数据
    int ary1[1] = {1};
    vector<int> v1(ary1,ary1+1);
    EXPECT_EQ(1, findMin(v1));
    
    int ary2[2] = {1,2};
    vector<int> v2(ary2,ary2+2);
    EXPECT_EQ(1, findMin(v2));
    
    int ary3[2] = {2,1};
    vector<int> v3(ary3,ary3+2);
    EXPECT_EQ(1,findMin(v3));
    
    int ary4[5] = {1,2,3,4,5};
    vector<int> v4(ary4,ary4+5);
    EXPECT_EQ(1, findMin(v4));
    
    int ary5[5] = {3,4,5,1,2};
    vector<int> v5(ary5,ary5+5);
    EXPECT_EQ(1, findMin(v5));
    
    //重复数据
    /*
    int ary6[5] = {1,1,1,1,1};
    vector<int> v6(ary6,ary6+5);
    EXPECT_EQ(1, findMin(v6));
    
    int ary7[5] = {1,1,0,1,1};
    vector<int> v7(ary7,ary7+5);
    EXPECT_EQ(1, findMin(v7));
     */
}

TEST(BaseKnowledgeTest,numbersByRecursion) {
    int ary1[9] = {1,2,3,4,5,6,7,8,9};
    vector<int> v1(ary1,ary1+9);
    vector<int> ret1 = numbersByRecursion(1);
    //EXPECT_EQ(1, findMin(v5));
}
