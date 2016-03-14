//
//  BinarySearch.cpp
//  String
//
//  Created by 林涛 on 16/2/25.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "BinarySearch.hpp"

/**
 * @param nums: The integer array.
 * @param target: Target number to find.
 * @return: The first position of target. Position starts from 0.
 */
int BinarySearch::binarySearch(vector<int> &array, int target) {
    // write your code here
    int left = 0;
    int right = (int)array.size() - 1;
    int mid = (left + right)/2;
    while (left < right && array[mid] != target) {
        //left
        if (array[mid] < target) {
            left = mid;
        }
        
        //right
        if (array[mid] > target) {
            right = mid;
        }
        
        mid = (left + right)/2;
    }
    
    if (array[mid] == target) {
        int firstTarget = mid;
        while (firstTarget > 0) {
            
            if (array[firstTarget-1] != target ) {
                break;
            } else {
                firstTarget--;
            }
        }
        
        if (firstTarget == 0 && array[firstTarget] != target) {
            return firstTarget+1;
        } else {
            return firstTarget;
        }
        
    } else {
        return -1;
    }
}

/**
 * @param x: An integer
 * @return: The sqrt of x
 */
int BinarySearch::sqrt(int x) {
    // write your code here
    long long left = 0;
    long long right = x/2 + 1;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long result = mid * mid;
        if (x == result) {
            return (int)mid;
        } else if ( result < x ){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        
    }
    
    return (int)right ;
}

int BinarySearch::searchInsert(vector<int> &A, int target) {
    // write your code here
    int left = 0;
    int right = (int)A.size()-1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (A[mid] == target) {
            return mid;
        } else if (A[mid] > target){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

/**
 * @param matrix, a list of lists of integers
 * @param target, an integer
 * @return a boolean, indicate whether matrix contains target
 */
bool BinarySearch::searchMatrix(vector<vector<int> > &matrix, int target) {
    // write your code here
    if (matrix.size() == 0) {
        return false;
    }
    
    int coltop = 0;
    int colbottom = (int)matrix.size() - 1;
    int targetCol = 0;
    int rowleft = 0;
    int rowright = (int)(matrix[0].size())-1;
    int rowmid = (rowleft + rowright ) / 2;
    while (coltop <= colbottom) {
        int colmid = (coltop + colbottom) / 2;
        if (target == matrix[colmid][rowmid]) {
            return true;
        } else if(target < matrix[colmid][0]){
            colbottom = colmid - 1;
        } else if (target > matrix[colmid][rowright]){
            coltop = colmid + 1;
        } else {
            //找到目标行
            targetCol = colmid;
            break;
        }
    }
    
    while (rowleft <= rowright) {
        int mid = (rowleft + rowright) / 2;
        if (target == matrix[targetCol][mid]) {
            return true;
        } else if (target < matrix[targetCol][mid]){
            rowright = mid - 1;
        } else {
            rowleft = mid + 1;
        }
    }
    
    return false;
}

bool isCut(vector<int> L,int k, int len){
    int sum = 0;
    for (int i = 0; i < L.size(); i++) {
        sum += L[i]/len;
    }
    return sum >= k;
}

/**
 *@param L: Given n pieces of wood with length L[i]
 *@param k: An integer
 *return: The maximum length of the small pieces.
 */
int  BinarySearch::woodCut(vector<int> L, int k) {
    // write your code here
    int max = L[0];
    for (int i = 1; i < L.size(); i++) {
        if (max < L[i]) {
            max = L[i];
        }
    }
    
    int left = 1;
    int right = max;
    while (left + 1 < right) {
        int mid = (left + right)/2;
        if(isCut(L, k, mid)){
            left = mid;
        } else {
            right = mid;
        }
    }
    
    return left;
    
}

/**
 * @param A: An integers array.
 * @return: return any of peek positions.
 */
int BinarySearch::findPeak(vector<int> A) {
    // write your code here
    if (A.size() == 0) {
        return 0;
    }
    
    long long left = 0;
    long long right = (int)A.size() - 1;
    while (left < right) {
        int mid = (left + right ) / 2;
        if (A[mid] > A[mid-1] && A[mid] > A[mid+1]) {
            return mid;
        } else if (A[mid] >= A[mid-1] && A[mid] <= A[mid+1]){
            left = mid;
        } else {
            right = mid;
        }
    }
    
    //问题代码
//    while (left < right) {
//        int mid = (left + right ) / 2;
//        if (A[mid] > A[mid-1] && A[mid] > A[mid+1]) {
//            return mid;
//        } else if (A[mid] >= A[mid-1] && A[mid] <= A[mid+1]){
//            left = mid + 1;
//        } else {
//            right = mid - 1;
//        }
//    }
    
    return 0;
    
//    if (A.size() == 0) return -1;
//    
//    int l = 0, r = A.size() - 1;
//    while (l + 1 < r) {
//        int mid = l + (r - l) / 2;
//        if (A[mid] < A[mid - 1]) {
//            r = mid;
//        } else if (A[mid] < A[mid + 1]) {
//            l = mid;
//        } else {
//            return mid;
//        }
//    }
//    
//    int mid = A[l] > A[r] ? l : r;
//    return mid;
}

bool isBadVersion(int k){
    return true;
}

int  BinarySearch::findFirstBadVersion(int n) {
    // write your code here
    
    if (n == 0) {
        return 0;
    }
    
    long long left = 1;
    long long right = n;
    while (left + 1 < right ) {
        long long mid = (left + right ) / 2;
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    if (left == 1) {
        if (isBadVersion(1)) {
            return 1;
        } else {
            return 2;
        }
    } else if (right == n){
        if (isBadVersion(n)) {
            return n;
        } else {
            return 0;
        }
    }
    
    return right;
}



vector<int> BinarySearch::searchRange(vector<int> &A, int target) {
    // write your code here
    vector<int> result;
    result.push_back(-1);
    result.push_back(-1);
    
    if (A.size() == 0) {

        return result;
    }
    
    int left = -1;
    int right = (int)A.size();
    while (left +1 < right ) {
        int mid = left + (right-left) / 2;
        if (A[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }
    
    if (left+1 < A.size() && A[left+1] == target ) {
        result[0] = left + 1;
    } else {
        return result;
    }
    
    right = (int)A.size();
    while (left + 1 < right) {
        int mid = left + (right-left) / 2;
        if (A[mid] > target) {
            right = mid;
        } else {
            left = mid;
        }
    }
    result[1] = left;
    return result;
}

//1.找出排序
//2.判断目标是否在排序的列队中
int BinarySearch::search(vector<int> &A, int target) {
    // write your code here
    if (A.size() == 0) {
        return -1;
    }
    
    int left = 0;
    int right = (int)A.size() - 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == target) {
            return mid;
        }
        
        if (A[left] < A[mid]) {
            if (A[left] <= target && target < A[mid]) {
                right = mid;
            } else {
                left = mid;
            }
        } else if(A[left] > A[mid]){
            if (A[mid] < target && target <= A[right]) {
                left = mid;
            } else {
                right = mid;
            }
        }
    }
    
    if (A[left] == target) {
        return left;
    } else if (A[right] == target){
        return right;
    } else {
        return -1;
    }
}
