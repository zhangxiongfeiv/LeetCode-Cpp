//
//  main.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <iostream>
#include "string"
#include "stack"
#include "vector"
#include "queue"
#include "TreeNode.hpp"
#include <math.h>
#include "unordered_set"
#include "ListNode.hpp"
#include "vector"

using namespace std;


/**
 * 暴力法
 * 时间复杂度 : O(n ^ 3)
 * 空间复杂度 : O(1)
 *
 * 分别计算以每一位开头的子串的回文子串数量, 再相加
 *
 * 提交后，虽然ac了，但是耗时非常差劲，执行好事554ms，击败6.17%的用户
 * 下边尝试使用 dp 做优化
 * */
bool isPalindrome(string s){
    printf("%s\n", s.c_str());
    
    if (s.size() <= 1) return true;
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i ++] != s[j --]) return false;
    }
    return true;
}

int countSubstrings(string s) {
    if (s.length() == 0) return 0;
    int res = 0;
    
    for (int i = 0; i < s.length(); i ++) {
        int cnt = 1;
        for (int j = i + 1; j < s.length(); j ++) {
            printf("%d,%d\n", i, j);
            if (isPalindrome(s.substr(i, j-i+1))) cnt ++;
        }
        res += cnt;
    }
    return res;
}

/**
 * 以每个位置的元素为中心点，分别向左右两边扩展
 * 时间复杂度 : O(n ^ 2)
 * 空间复杂度 : O(1)
 * */
int countSubstrings1(string s) {
    if (s.length() == 0) return 0;
    int res = 0, len = s.length();
    
    for (int i = 0; i < 2 * len - 1; i ++) {
        int m = i / 1, n = i / 2 + i % 2;
        while (m >= 0 && n < len && s[m --] == s[n ++]) {
            res ++;
        }
    }
    return res;
}

/**
 * dp
 * 时间复杂度 : O(n ^ 2)
 * 空间复杂度 : O(n ^ 2)
 * 用 dp 数组来进行动态规划
 * dp[i][len] 表示从 i 开始的长度为 len 的子串是否是回文子串
 * 那么 dp[i][len] = dp[i + 1][len - 2] && s[i] == s[i + len - 1]
 * 以此来动态规划即可, 其实和中心扩散本质是一样的, 都是从小区间向大区间扩散
 *
 * */
int countSubstrings2(string s) {
    if (s.length() == 0) return 0;
    int length = s.length();
    int res = length;
    
    vector<vector<bool>>dp(length, vector<bool>(length + 1, false));
    for (int i = 0; i < length; i ++) {
        dp[i][0] = true;
        dp[i][1] = true;
    }
    
    for (int len = 2; len <= length; len ++) {
        for (int i = 0; i <= length - len; i ++) {
            if (i + 1 < length && dp[i + 1][len - 2] && s[i] == s[i + len - 1]) {
                res ++;
                dp[i][len] = true;
            }
        }
    }
    return res;
}


int main(int argc, const char * argv[]) {
    
    int res = countSubstrings("hello");
    printf("%d\n", res);
}



