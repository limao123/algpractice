//
//  RecursionTest.cpp
//  String
//
//  Created by bmob-LT on 16/9/2.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include <stdio.h>
#include "gtest/gtest.h"
#include "Recursion.hpp"

vector<int> changeArrayToVector(int a[],int length) {
    vector<int> v(a,a+length);
    return v;
}

TEST(Recursion, permute){
    int ary1[3] = {1,2,3};
    vector<int> v1(ary1,ary1+3);
    vector<vector<int>> result1 = permute(v1);
}

TEST(Recursion, permuteNonrecursive){
    int ary1[3] = {1,2,3};
    vector<int> v1(ary1,ary1+3);
    vector<vector<int>> result1 = permuteNonRecursive(v1);
}