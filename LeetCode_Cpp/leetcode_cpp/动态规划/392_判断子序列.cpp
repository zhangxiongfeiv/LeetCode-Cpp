//
//  392_判断子序列.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/27.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "string"

using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0) return true;
        
        // 定义状态 字符串 s 截止 index为i的 子串 是否是子序列
        
        // 设置初始状态 字符串长度为0时，肯定是t的子序列
        
        int lastIdx = 0;
        
        for (int i = 0; i < s.length(); i ++) {
            char c = s[i];
            for (int j = lastIdx; j < t.length(); j ++) {
                char c1 = t[j];
                if (c == c1) {
                    if (i == s.length() - 1) return true;
                    lastIdx = j + 1;
                    break;
                }else if (j == t.length() - 1){
                    return false;
                }
            }
        }
        
        return false;
    }
};
