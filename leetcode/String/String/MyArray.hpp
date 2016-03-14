//
//  Array.hpp
//  String
//
//  Created by 林涛 on 16/1/19.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef MyArray_hpp
#define MyArray_hpp

#include <stdio.h>
#include <vector>
#include <limits.h>
#include <stdlib.h>
using namespace std;

class MyArray{
public:
    static int removeElement(vector<int> &A, int elem);
    static vector<int> subarraySum(vector<int> nums);
    static int removeDuplicates(vector<int> &nums);
    static void mergeSortedArray(int A[], int m, int B[], int n);
    static vector<long long> productExcludeItself(vector<int> &nums);
    static int firstMissingPositive(vector<int> A);
    static int threeSumClosest(vector<int> nums, int target);
    static vector<vector<int> > threeSum(vector<int> &nums);
    static vector<int> twoSum(vector<int> &nums, int target);
    static int partitionArray(vector<int> &nums, int k);
};

#endif /* Array_hpp */
