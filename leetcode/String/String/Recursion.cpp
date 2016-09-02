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

/**
 * @param nums: A list of integers.
 * @return: A list of permutations.
 */
vector<vector<int> > permute(vector<int> nums) {
    // write your code here
//    vector<vector<int> > result;
//    
//    if (nums.size() == 1) {
//        result.push_back(nums);
//        return result;
//    }
//    
//    for (int i = 0; i < nums.size(); ++i) {
//        //消除第i个数据，递归找出剩余数据的全排队
//        vector<int> nums_new = nums;
//        nums_new.erase(nums_new.begin() + i);
//        vector<vector<int> > res_tmp = permute(nums_new);
//
//        for (int j = 0; j < res_tmp.size(); ++j) {
//        
//            vector<int> temp = res_tmp[j];
//            //将消除的数据放在末位
//            temp.push_back(nums[i]);
//            result.push_back(temp);
//        }
//    }
//    
//    return result;
    
    
    vector<vector<int>> result;
    if (nums.size() == 1) {
        result.push_back(nums);
        return result;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        vector<int> subNums = nums;
        subNums.erase(subNums.begin()+i);
        
        vector<vector<int>> subResult = permute(subNums);
        for (int j = 0; j < subResult.size(); j++) {
            vector<int> temp = subResult[j];
            temp.push_back(nums[i]);
            result.push_back(temp);
        }
    }
    return result;
}
