//
//  Recursion.cpp
//  String
//
//  Created by bmob-LT on 16/8/29.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "Recursion.hpp"

void helper(int n,int k,int pos,vector<int> &v,vector<vector<int>> &result) {
    if (v.size() == k) {
        result.push_back(v);
        return;
    }
    
    for (int i = pos; i <= n; i++) {
        v.push_back(i);
        helper(n, k, i+1, v, result);
        v.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {
    // write your code here
    vector<vector<int>> result;
    vector<int> v;
    
    if (n <= 0 || k <= 0) {
        return result;
    }
    
    helper(n, k, 1, v, result);
    return result;
}

