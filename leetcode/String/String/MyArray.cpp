
//
//  Array.cpp
//  String
//
//  Created by 林涛 on 16/1/19.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "MyArray.hpp"

int MyArray::removeElement(vector<int> &A, int elem){
    
    vector<int>::iterator iter = A.begin();
    while (iter != A.end()) {
        if (*iter == elem) {
            A.erase(iter);
        } else {
            iter++;
        }
    }
    return (int)A.size();
}

/**
 * @param nums: A list of integers
 * @return: A list of integers includes the index of the first number
 *          and the index of the last number
 */
vector<int> MyArray::subarraySum(vector<int> nums){
    // write your code here
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        int sum = nums.at(i);
        if (sum == 0) {
            result.push_back(0);
            result.push_back(0);
            return result;
        }
        
        for (int j = i+1; j < nums.size(); j++) {
            if ((sum += nums.at(j)) == 0) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

/**
 * @param A: a list of integers
 * @return : return an integer
 */
int MyArray::removeDuplicates(vector<int> &nums) {
    // write your code here
    //暴力解法
//    vector<int>::iterator iter1;
//    
//    for (iter1 = nums.begin(); iter1 != nums.end(); iter1++) {
//        vector<int>::iterator iter2 = iter1+1;
//        while (iter2 != nums.end()) {
//            if (*iter2 == *iter1) {
//                nums.erase(iter2);
//            } else {
//                iter2++;
//            }
//        }
//    }
//    return (int)nums.size();
    
    if (nums.size() == 0) {
        return 0;
    }
   
    int tempCompare = nums.front();
    vector<int>::iterator indexOfCompare;
    vector<int>::iterator indexOfPut = nums.begin();
    for (indexOfCompare = nums.begin()+1; indexOfCompare != nums.end(); indexOfCompare++) {
        if (*indexOfCompare != *(indexOfCompare-1)) {
            *indexOfPut = *(indexOfCompare-1);
            indexOfPut++;
            
            tempCompare = *indexOfCompare;
        }
    }
    
    *indexOfPut = *(indexOfCompare-1);
    indexOfPut++;
    while (indexOfPut != nums.end()) {
        nums.erase(indexOfPut);
    }
    return (int)nums.size();
}

/**
 * @param A: sorted integer array A which has m elements,
 *           but size of A is m+n
 * @param B: sorted integer array B which has n elements
 * @return: void
 */
void MyArray::mergeSortedArray(int A[], int m, int B[], int n) {
    // write your code here
    if (n <= 0) {
        return;
    }
    
    int tempA[m];
    for (int i = 0; i < m; i++) {
        tempA[i] = A[i];
    }
    //遍历A
    int indexOfTempA = 0;
    int indexOfB = 0;
    int indexOfA = 0;
    while (indexOfTempA < m && indexOfB < n) {
        if (tempA[indexOfTempA] <= B[indexOfB]) {
            A[indexOfA++] = tempA[indexOfTempA++];
        } else {
            A[indexOfA++] = B[indexOfB++];
        }
    }
    
    while (indexOfTempA < m) {
        A[indexOfA++] = tempA[indexOfTempA++];
    }
    
    while(indexOfB < n) {
        A[indexOfA++] = B[indexOfB++];
    }
}

/**
 * @param A: Given an integers array A
 * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
 */
vector<long long> MyArray::productExcludeItself(vector<int> &nums) {
    // write your code here
    vector<int>::iterator index;
    vector<long long> results;
    for (index = nums.begin(); index != nums.end(); index++) {
        vector<int>::iterator index1;
        long long result = 1;
        for (index1 = nums.begin(); index1 != nums.end(); index1++) {
            if (index1 != index) {
                result *= *index1;
            }
        }
        results.push_back(result);
    }
    return results;
}

/**
 * @param A: a vector of integers
 * @return: an integer
 */
int MyArray::firstMissingPositive(vector<int> A) {
    // write your code here
    //排序
    sort(A.begin(),A.end());
    
    vector<int>::iterator index;
    int result = 1;
    for (index = A.begin(); index != A.end(); index++) {
        if (*index > 0) {
            break;
        }
    }
    
    while(index != A.end()) {
        if (result != *index) {
            return result;
        } else {
            
            index++;
            if (*index != *(index-1)) {
                result++;
            }
        }
    }
    
    return result;
}

/**
 * @param numbers: Give an array numbers of n integer
 * @param target: An integer
 * @return: return the sum of the three integers, the sum closest target.
 */
int MyArray::threeSumClosest(vector<int> nums, int target) {
    // write your code here
    if (nums.size() < 3) {
        return 0;
    }
    
    int result = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum-target) < abs(result-target)) {
                    result = sum;
                }
            }
        }
    }
    return result;
}

/**
 * @param numbers : Give an array numbers of n integer
 * @return : Find all unique triplets in the array which gives the sum of zero.
 */
vector<vector<int> > MyArray::threeSum(vector<int> &nums) {
    // write your code here
    vector<vector<int> > results;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size(); i++) {
        bool isOneTarget = false;
        if (nums[i] > 0) {
            break;
        } else {
            for (int j = i + 1; j < nums.size(); j++) {
                
                int twoSum = nums[i] + nums[j];
                bool isSecondTarget = false;
                if (twoSum > 0) {
                    break;
                } else {
                    
                    for (int k = j + 1; k < nums.size(); k++) {
                        int sum = twoSum + nums[k];
                        if (sum > 0) {
                            break;
                        } else if (sum == 0){
                            vector<int> result;
                            result.push_back(nums[i]);
                            result.push_back(nums[j]);
                            result.push_back(nums[k]);
                            results.push_back(result);
                            isOneTarget = true;
                            isSecondTarget = true;
                            break;
                        }
                    }
                }
                
                if (isSecondTarget) {
                    while (((j+1) < nums.size()) &&
                           (nums[j] == nums[j+1])) {
                        j++;
                    }
                    
                    if (j == nums.size() -1) {
                        break;
                    }
                }
            }
        }
        
        if (isOneTarget) {
            while (((i+1) < nums.size()) &&
                   (nums[i] == nums[i+1])) {
                i++;
            }
            
            if (i == nums.size() -1) {
                break;
            }
        }
    }
    
    return results;
}

/*
 * @param numbers : An array of Integer
 * @param target : target = numbers[index1] + numbers[index2]
 * @return : [index1+1, index2+1] (index1 < index2)
 */
vector<int> MyArray::twoSum(vector<int> &nums, int target) {
    // write your code here
    vector<int> results;
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            int sum = nums.at(i) + nums.at(j);
            if (sum == target) {
                results.push_back(i+1);
                results.push_back(j+1);
                return results;
            }
        }
    }
    
    return results;
}

int MyArray::partitionArray(vector<int> &nums, int k) {
    // write your code here
    int left = 0;
    int right = (int)nums.size() - 1;
    while (left < right) {
        while ((left < right) && (nums[left] < k)) {
            left++;
        }
        
        while ((left < right) && (nums[right] >= k)) {
            right--;
        }
        
        if (left < right) {
            int temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;
        }
    }
    
    if (right == (int)nums.size()-1) {
        right++;
    }
    
    return right;
}