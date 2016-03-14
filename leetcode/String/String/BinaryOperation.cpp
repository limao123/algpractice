//
//  BinaryOperation.cpp
//  String
//
//  Created by 林涛 on 16/3/5.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "BinaryOperation.hpp"

/**
 *@param a, b: Two integer
 *return: An integer
 */
int BinaryOperation::bitSwapRequired(int a, int b) {
    // write your code here
    int c = a^b;
    int num = 0;
    while (c) {
        num++;
        c = c & (c-1);
    }
    return num;
}

/**
 * @param n, m: positive integer (1 <= n ,m <= 100)
 * @return an integer
 */
int uniquePaths(int m, int n) {
    // wirte your code here
    int dp[m][n];
    memset(dp,0,sizeof(dp));
    
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j< n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}

int  BinaryOperation::updateBits(int n, int m, int i, int j) {
    // write your code here
    
//    int one = ~0;
//    int mask = 0;
//    if (j < 31) {
//        int left = one << (j+1);
//        int right = (1 << i) - 1;
//        mask = left | right;
//    } else {
//        mask = (1 << i) - 1;
//    }
//    return (n & mask) | (m << i);
    
    int one = ~0;
    int bitWidth = 8 * sizeof(int);
    //先算出有多少个0，先左移0的个数位
    unsigned int mask = one << (bitWidth - (j - i + 1));
    //算出右边有多少个0，右移0的个数位
    mask = mask >> (bitWidth - j - 1);
    return (n & ~mask) | (m << i);

}

/*
 * @param a, b, n: 32bit integers
 * @return: An integer
 */
int BinaryOperation::fastPower(int a, int b, int n) {
    // write your code here
    if (n == 1) {
        return a % b;
    } else if( n == 0 ){
        //此处不能直接返回1，因为如果b=＝1时，1%b==0
        return 1 % b;
    }
    
    long long temp = fastPower(a, b, n/2);
    long long result = (temp * temp) % b;
    if (n % 2 == 1) {
        result = (result * a) % b;
    }
    return (int)result;
}

/**
 * @paramn n: An integer
 * @return: An integer
 */
int BinaryOperation::numTrees(int n) {
    // write your code here
    if (n < 0) {
        return -1;
    }
    
    vector<int> count(n+1);
    count[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            count[i] += count[j]* count[i-1-j];
        }
    }
    return count[n];
}


/**
 *@param n: Given a decimal number that is passed in as a string
 *@return: A string
 */
static string binaryRepresentation(string n) {
    // wirte your code here
    string result = "";
    int pointInder = n.find(".");
    int intNum = atoi(n.substr(0,pointInder).c_str());
    double decimal = atof(n.substr(pointInder).c_str());
    
    stack<int> s;
    if (intNum == 0) {
        result += "0";
    }
    
    while (intNum > 0) {
        s.push(intNum/2);
        intNum /= 2;
    }
    
    if (decimal > 0.0) {
        result += ".";
    }
    
    while (!s.empty()) {
        result.push_back('0'+s.top());
        s.pop();
    }
    
    int count = 0;
    while (decimal > 0.0) {
        if (count > 32) {
            return "error";
        }
        
        decimal *= 2;
        if (decimal >= 1.0) {
            result += "1";
            decimal -= 1;
        } else {
            result += "0";
        }
        count++;
    }
    return result;
    
}




