//
//  20_有效的括号.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/27.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "string"
#include "stack"

using namespace std;
class Solution {
public:
    
    bool isValid(string s) {
        
        stack<char> stack;
        
        for (int i = 0; i < s.length(); i ++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            }else{
                if(stack.empty()) return false;
                
                char c1 = stack.top();
                stack.pop();
                if (c1 == '(' && c == ')') stack.pop();
                if (c1 == '[' && c == ']') stack.pop();
                if (c1 == '{' && c == '}') stack.pop();
            }
        }
        
        return stack.empty();
    }
};
