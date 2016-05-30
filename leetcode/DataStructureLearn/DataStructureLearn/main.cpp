//
//  main.cpp
//  DataStructureLearn
//
//  Created by bmob-LT on 16/3/28.
//  Copyright © 2016年 bmob-LT. All rights reserved.
//

#include <iostream>
#include "Sort.hpp"
#include "Util.hpp"
#include <vector>
#include <string>
#include <sys/types.h>
#include <unistd.h>
using namespace std;


- (void)isContain235(String s){
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int count;
    scanf("%d",&count);
    for (int i = 0; i < count ; i++) {
        
    }
    return 0;
}

void testQuickSort(){
    vector<int> case1;
    quickSort(case1);
    printVector(case1);
    
    int caseAry2[] = {1};
    vector<int> case2(caseAry2,caseAry2+2);
    quickSort(case2);
    printVector(case2);
    
    int caseAry3[] = {1,2};
    vector<int> case3(caseAry3,caseAry3+2);
    quickSort(case3);
    printVector(case3);
    
    int caseAry4[] = {1,2,3,4};
    vector<int> case4(caseAry4,caseAry4+4);
    quickSort(case4);
    printVector(case4);
    
    int caseAry5[] = {1,2,3,4};
    vector<int> case5(caseAry5,caseAry5+4);
    quickSort(case5);
    printVector(case5);
    
    
    int caseAry6[] = {4,3,2,1};
    vector<int> case6(caseAry6,caseAry6+4);
    quickSort(case6);
    printVector(case6);
    
    int caseAry7[] = {1,1,1,1};
    vector<int> case7(caseAry7,caseAry7+4);
    quickSort(case7);
    printVector(case7);
    
    int caseAry8[] = {3,5,2,7,1,8};
    vector<int> case8(caseAry8,caseAry8+6);
    quickSort(case8);
    printVector(case8);
    
}
