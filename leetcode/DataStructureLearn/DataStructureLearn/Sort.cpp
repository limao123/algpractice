//
//  Sort.cpp
//  DataStructureLearn
//
//  Created by bmob-LT on 16/3/28.
//  Copyright © 2016年 bmob-LT. All rights reserved.
//

#include "Sort.hpp"
#include "Util.hpp"


void partition(vector<int> a,int start, int end){
    if (start >= end) {
        return;
    }
    
    int k = a[start];
    int left = start+1;
    int right = end;
    while (left < right) {
        while (a[right] >= k && left < right) {
            right--;
        }
        
        while (a[left] < k && left < right) {
            left++;
        }
        
        if (left < right) {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }
    int temp = a[start];
    a[start] = a[right];
    a[right] = temp;
    partition(a, start, left -1);
    partition(a, left+1, end);

}

void quickSort(vector<int> a){
    partition(a, 0, a.size()-1);
        printVector(a);
}

