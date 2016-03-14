//
//  BinarySearch.hpp
//  String
//
//  Created by 林涛 on 16/2/25.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef BinarySearch_hpp
#define BinarySearch_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class BinarySearch{
public:
    static int binarySearch(vector<int> &array, int target);
    static int sqrt(int x);
    static int searchInsert(vector<int> &A, int target);
    static bool searchMatrix(vector<vector<int> > &matrix, int target);
    static int woodCut(vector<int> L, int k);
    static int findPeak(vector<int> A);
    static int findFirstBadVersion(int n);
    static vector<int> searchRange(vector<int> &A, int target);
    static int search(vector<int> &A, int target);
};

#endif /* BinarySearch_hpp */
