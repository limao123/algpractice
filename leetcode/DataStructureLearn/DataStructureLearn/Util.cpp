//
//  Util.cpp
//  DataStructureLearn
//
//  Created by bmob-LT on 16/3/29.
//  Copyright © 2016年 bmob-LT. All rights reserved.
//

#include "Util.hpp"

void printArray(int a[],int length){
    for (int i = 0; i < length; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void printVector( vector<int> a){
    for (int i = 0; i < a.size(); i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
}