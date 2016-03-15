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
int Greedy::majorityNumber(vector<int> nums) {
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

/**
 * @param gas: a vector of integers
 * @param cost: a vector of integers
 * @return: an integer
 */
int Greedy::canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    // write your code here
    if (gas.size() == 0 || cost.size() == 0 || gas.size() != cost.size()) {
        return -1;
    }
    
    for (int i = 0; i < gas.size(); i++) {
        int remainder = 0;
        
        int j = i;
        do {
            remainder = remainder + gas[j] - cost[j];
            j++;
            if (j == gas.size()) {
                j = 0;
            }
            if (remainder < 0) {
                break;
            }
            
        } while (j!=i);
        
        if (remainder >= 0) {
            return i;
        }
    }
    return -1;
}

/**
 *@param num: A list of non negative integers
 *@return: A string
 */
string Greedy::largestNumber(vector<int> &num) {
    // write your code here
    vector<string> numStr;
    for (int i = 0; i < num.size(); i++) {
        stringstream ss;
        string str;
        ss<<num[i];
        ss>>str;
        numStr.push_back(str);
    }
    sort(numStr.begin(), numStr.end());
    string result = "";
    
    if (numStr[numStr.size()-1] == "0") {
        return "0";
    }
    
    for (int i = (int)numStr.size() - 1; i >= 0; i--) {
        result += numStr[i];
    }
    return result;
}






