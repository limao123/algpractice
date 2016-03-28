//
//  Sort.cpp
//  DataStructureLearn
//
//  Created by bmob-LT on 16/3/28.
//  Copyright © 2016年 bmob-LT. All rights reserved.
//

#include "Sort.hpp"

void partition(int a[],int start, int end){
    int k = a[start];
    int left = start;
    int right = end;
    while (left < right) {
        while (a[right] >= k && left < right) {
            right--;
        }
        
        while (a[left] < k && left < right) {
            left++;
        }
        
        int temp = a[left];
        a[right] = a[left];
        a[left] = temp;
    }
    
    
}

void quickSort(int a[],int length){
    partition(a, 0, length-1);
}

