//
//  SwapString.hpp
//  String
//
//  Created by 林涛 on 16/1/18.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//


#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

#ifndef SwapString_hpp
#define SwapString_hpp

class SwapString {
    
public:
    
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t);
    bool compareStrings(string A, string B);
    int strStr(const char *source, const char *target);
    vector<string> anagrams(vector<string> &strs);
    int longestCommonSubstring(string &A, string &B);
    string longestCommonPrefix(vector<string> &strs);
};
#endif /* SwapString_hpp */
