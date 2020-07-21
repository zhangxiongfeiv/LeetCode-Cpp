//
//  1021_删除最外层的括号.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/21.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "string"
#include "stack"

using namespace std;
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
        stack<char> stack;
        for (int i = 0; i < S.length(); i ++) {
            if (S[i] == ')') {
                stack.pop();
            }
            
            if (!stack.empty()) {
                res += S[i];
            }
            
            if (S[i] == '(') {
                stack.push('(');
            }
        }
        return res;
    }
};
