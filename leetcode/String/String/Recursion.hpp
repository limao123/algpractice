//
//  Recursion.hpp
//  String
//
//  Created by bmob-LT on 16/8/29.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef Recursion_hpp
#define Recursion_hpp

#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int> > combine(int n, int k);
vector<vector<int> > permute(vector<int> nums);
vector<vector<int> > permuteNonRecursive(vector<int>& nums);
#endif /* Recursion_hpp */
