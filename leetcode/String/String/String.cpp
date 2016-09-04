//
//  String.cpp
//  String
//
//  Created by 林涛 on 16/9/2.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "String.hpp"


bool anagram(string s, string t) {
//    if (s.empty() || t.empty()) {
//        return false;
//    }
//    if (s.size() != t.size()) {
//        return false;
//    }
//    
//    int letterCount[256] = {0};
//    
//    for (int i = 0; i != s.size(); ++i) {
//        ++letterCount[s[i]];
//        --letterCount[t[i]];
//    }
//    for (int i = 0; i != t.size(); ++i) {
//        if (letterCount[t[i]] != 0) {
//            return false;
//        }
//    }
//    
//    return true;
    
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