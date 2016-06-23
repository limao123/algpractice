//
//  LTTest.hpp
//  String
//
//  Created by bmob-LT on 16/6/20.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef LTTest_hpp
#define LTTest_hpp

#include <iostream>

using namespace std;

void LTTest(int except, int test,string msg = "");
void LTTestString(string except, string test,string errMsg = "");
void LTTestBool(bool except,bool test,string errMsg = "");
#endif /* LTTest_hpp */
