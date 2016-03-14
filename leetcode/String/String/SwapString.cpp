//
//  SwapString.cpp
//  String
//
//  Created by 林涛 on 16/1/18.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "SwapString.hpp"

//顺序不需要相等
/**
 * @param s: The first string
 * @param b: The second string
 * @return true or false
 */
bool SwapString::anagram(string s, string t) {
    // write your code here
    if (s.length() <= 0 ||
        t.length() <= 0 ||
        s.length() != t.length()) {
        return false;
    }
    
    vector<unsigned> v1(s.begin(), s.end());
    vector<unsigned> v2(t.begin(), t.end());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    unsigned long length = s.length();

    
    for (int i = 0; i < length; i++) {
        //有一个不等就退出
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

//出现个数要相同
/**
 * @param A: A string includes Upper Case letters
 * @param B: A string includes Upper Case letter
 * @return:  if string A contains all of the characters in B return true
 *           else return false
 */
bool SwapString::compareStrings(string A, string B) {
    // write your code here
    int a[26] = {0};
    for (int i = 0; i < A.length(); i++) {
        a[A[i]-'A']++;
    }
    
    int b[26] = {0};
    for (int i = 0; i < B.length(); i++) {
        b[B[i]-'A']++;
    }
    
    for (int i = 0; i < 26; i++) {
        if (b[i] > a[i]) {
            return false;
        }
    }
    return true;
}

/**
 * Returns a index to the first occurrence of target in source,
 * or -1  if target is not part of source.
 * @param source string to be scanned.
 * @param target string containing the sequence of characters to match.
 */
int SwapString::strStr(const char *source, const char *target) {
    // write your code here
    if (source == NULL || target == NULL) {
        return -1;
    }
    
    if (target[0] == '\0') {
        return 0;
    }
    
    int i= 0;
    while (source[i] != '\0') {
        int j = 0;
        
        bool isContain = true;
        while (target[j] != '\0') {
            if (source[i+j] != target[j]) {
                isContain = false;
                break;
            } else {
                j++;
            }
        }
        
        if (isContain) {
            return i;
        } else {
            i++;
        }
    }
    return -1;
}

/**
 * @param strs: A list of strings
 * @return: A list of strings
 */
vector<string> SwapString::anagrams(vector<string> &strs) {
    // write your code here
    map<string,int> m;
    for (auto s:strs) {
        sort(s.begin(),s.end());
        m[s]++;
    }
    
    vector<string> results;
    for(auto s:strs) {
        auto temp = s;
        sort(temp.begin(), temp.end());
        if (m[temp] > 1) {
            results.push_back(s);
        }
    }
    
    return results;
}

int SwapString::longestCommonSubstring(string &A, string &B) {
    // write your code here
    int  max = 0;
    for (int i = 0; i < A.length(); i++) {
        for (int j = i ; j < A.length(); j++) {
            string sub = A.substr(i,j+1-i);
            if (B.find(sub) != -1 && sub.length() > max) {
                max = (int)sub.length();
            }
        }
    }
    return max;
}

string SwapString::longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
        return "";
    }
    
    string lastStr = strs.back();
    strs.pop_back();
    for (int i = 0; i < lastStr.length(); i++) {
        string subString = lastStr.substr(0,lastStr.length()-i);
        bool isCP = true;
        for (auto str:strs) {
            if (str.find(subString) == -1) {
                isCP = false;
                break;
            }
        }
        
        if (isCP) {
            return subString;
        }
    }
    return "";
}
