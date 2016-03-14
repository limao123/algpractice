//
//  Greedy.cpp
//  String
//
//  Created by bmob-LT on 16/3/14.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "Greedy.hpp"

/**
 * @param A: Array of integers.
 * return: The single number.
 */
int Greedy::singleNumber(vector<int> &A) {
    // write your code here
    // a^a = 0, 0^a=a,利用这两个特性遍历之后可得到落单的数字
    int x = 0;
    for (int i = 0; i < A.size(); i++) {
        x ^= A[i];
    }
    return x;
}

/**
 * @param nums: A list of integers
 * @return: The majority number
 */
int majorityNumber(vector<int> nums) {
    // write your code here
    int candidate = -1;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            candidate = nums[i];
            count++;
        } else {
            if (candidate == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
    }
    return candidate;
}

