//
//  Queue.hpp
//  String
//
//  Created by 林涛 on 16/1/25.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <stack>
using namespace std;

class Queue {
    
public:
    stack<int> stack1;
    stack<int> stack2;
    
    Queue() {
        // do intialization if necessary
    }
    
    void push(int element) {
        // write your code here
        this->stack1.push(element);
    }
    
    int pop() {
        // write your code here
        if (this->stack2.size() == 0) {
            while (this->stack1.size() != 0) {
                this->stack2.push(this->stack1.top());
                this->stack1.pop();
            }
        }
        
        int top = this->stack2.top();
        this->stack2.pop();
        return top;
    }
    
    int top() {
        // write your code here
        if (this->stack2.size() == 0) {
            while (this->stack1.size() != 0) {
                this->stack2.push(this->stack1.top());
                this->stack1.pop();
            }
        }

        return this->stack2.top();
    }
};

#endif /* Queue_hpp */
