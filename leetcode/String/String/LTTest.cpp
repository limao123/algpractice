//
//  LTTest.cpp
//  String
//
//  Created by bmob-LT on 16/6/20.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "LTTest.hpp"


void LTTest(int except, int test,string errMsg){
    if (except == test) {
        printf("pass except:%d test:%d\n",except,test);
    } else {
        printf("fail except:%d test:%d errorMsg:%s\n",except,test,errMsg.c_str());
    }
}

void LTTestString(string except, string test,string errMsg){
    
    if (except.compare(test) == 0) {
        printf("pass except:%s test:%s\n",except.c_str(),test.c_str());
    } else {
        printf("fail except:%s test:%s errorMsg:%s\n",except.c_str(),test.c_str(),errMsg.c_str());
    }
}

void LTTestBool(bool except,bool test,string errMsg){
    if (except == test) {
        printf("pass except:%d test:%d\n",except,test);
    } else {
        printf("fail except:%d test:%d errorMsg:%s\n",except,test,errMsg.c_str());
    }
}