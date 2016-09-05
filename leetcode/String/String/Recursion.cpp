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

void reverse(vector<int>& nums, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

vector<vector<int> > permuteNonRecursive(vector<int>& nums) {
    vector<vector<int> > result;
    if (nums.empty() || nums.size() <= 1) {
        result.push_back(nums);
        return result;
    }
    
    // sort nums first
    sort(nums.begin(), nums.end());
    for (;;) {
        result.push_back(nums);
        
        // step1: find nums[i] < nums[i + 1]
        int i = 0;
        for (i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            } else if (0 == i) {
                return result;
            }
        }
        
        // step2: find nums[i] < nums[j]
        int j = 0;
        for (j = nums.size() - 1; j > i; --j) {
            if (nums[i] < nums[j]) break;
        }
        
        // step3: swap betwenn nums[i] and nums[j]
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
        
        // step4: reverse between [i + 1, n - 1]
        reverse(nums, i + 1, nums.size() - 1);
    }
    return result;
}


