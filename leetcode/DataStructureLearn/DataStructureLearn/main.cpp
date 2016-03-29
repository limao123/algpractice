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
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int ary[] = {3,4,5,5,2,4,8};
    vector<int> a(ary,ary+7);
    quickSort(a);
//    printVector(a);
    return 0;
}
