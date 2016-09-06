//
//  String.cpp
//  String
//
//  Created by 林涛 on 16/9/2.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "String.hpp"

//lintcode 158
bool anagram(string s, string t) {
    
    if (s.empty() || t.empty() || (s.size() != t.size())) {
        return false;
    }
    
    int letterCount[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        letterCount[s[i]]++;
        letterCount[t[i]]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (letterCount[i] != 0) {
            return false;
        }
    }
    
    return true;
}

//lintcode 55,此处限制了A、B都由大写字母组成，如果不受这个限制则可以使用2方法，
//另外要注意跟面试官确认好，如果B为空是否算作包含，此处假定是算作包含的
bool compareStrings(string A, string B) {
    // write your code here
    
    //解决1
//    int a[26] = {0};
//    for (int i = 0; i < A.length(); i++) {
//        a[A[i]-'A']++;
//    }
//    
//    int b[26] = {0};
//    for (int i = 0; i < B.length(); i++) {
//        b[B[i]-'A']++;
//    }
//    
//    for (int i = 0; i < 26; i++) {
//        if (b[i] > a[i]) {
//            return false;
//        }
//    }
//    return true;
    
    //解法2
    if (A.size() < B.size()) {
        return false;
    }
    
    int letterCount[256] = {0};
    for (int i = 0; i < A.size(); i++) {
        letterCount[A[i]]++;
       
    }
    
    for (int i = 0; i < B.size(); i++) {
         letterCount[B[i]]--;
    }
    
    for (int i = 0; i < 256; i++) {
        if (letterCount[i] < 0) {
            return false;
        }
    }
    
    return true;
}