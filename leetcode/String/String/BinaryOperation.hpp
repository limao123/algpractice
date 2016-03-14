//
//  BinaryOperation.hpp
//  String
//
//  Created by 林涛 on 16/3/5.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef BinaryOperation_hpp
#define BinaryOperation_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stack>
using namespace std;

class BinaryOperation{
public:
    int bitSwapRequired(int a, int b);
    static int updateBits(int n, int m, int i, int j);
    static int fastPower(int a, int b, int n);
    static int numTrees(int n);
    static string binaryRepresentation(string n);
};
#endif /* BinaryOperation_hpp */
