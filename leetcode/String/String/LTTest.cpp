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