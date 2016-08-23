//
//  main.cpp
//  work
//
//  Created by 林涛 on 16/4/21.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool isContain235(string s){
    if (s.find('2',0) == -1 &&
        s.find('3',0) == -1 &&
        s.find('5',0) == -1) {
        return false;
    } else {
        return true;
    }
}

bool isContain18(string s){
    int pos = s.find('1',0);
    while (pos != -1) {
        if (pos != s.size() - 1 &&
            s[pos+1] == '8') {
            return true;
        }
        pos = s.find('1',pos+1);
    }
    return false;
}

bool isMod7(string s){
    
    while (s.size() > 3) {
        
        long long left = atoll(s.substr(0,s.size()-3).c_str());
        int right = atoi(s.substr(s.size()-3,s.size()).c_str());
        long long remain = left - right;
        char num[30];
        sprintf(num,"%lld", abs(remain));
        s = num;
    }
    
    int n = atoi(s.c_str());
    if (n % 7 == 0) {
        return true;
    } else {
        return false;
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    int count;
//    scanf("%d",&count);
//    for (int i = 0; i < count ; i++) {
//        int result = 0;
//        long long left;
//        long long right;
//        scanf("%lld %lld",&left,&right);
//        for (; left <= right; left++) {
//            
//            char num[30];
//            sprintf(num,"%lld", abs(left));
//            string numStr = num;
//            if (isMod7(numStr) &&
//                isContain235(numStr) &&
//                !isContain18(numStr)) {
//                result++;
//                printf("%s\n",num);
//            }
//            
//        }
//        printf("%d\n",result);
//    }
    
    string a = "一";
    
    for (int i = 0; i < a.length(); i++) {
        printf("%c\n",a[i]);
    }
    
    return 0;
}
