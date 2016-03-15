//
//  Greedy.hpp
//  String
//
//  Created by bmob-LT on 16/3/14.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef Greedy_hpp
#define Greedy_hpp

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;

class Greedy{
public:
    static int singleNumber(vector<int> &A);
    static int majorityNumber(vector<int> nums);
    static int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
    static string largestNumber(vector<int> &num);
};
#endif /* Greedy_hpp */