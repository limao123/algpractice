//
//  main.cpp
//  Practise
//
//  Created by bmob-LT on 16/6/27.
//  Copyright © 2016年 bmob-LT. All rights reserved.
//

#include <iostream>

int func(int n,int m) {
    if (n<= 0 || m <= 0) {
        return 0;
    }
    if (n == 1) {
        return m;
    }
    if (m==1) {
        return n;
    }
    return func(n-1,m)+func(n, m-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int b;
    std::cin >> b;
    int a = func(4, 5);
    std::cout << a;
    return 0;
}
