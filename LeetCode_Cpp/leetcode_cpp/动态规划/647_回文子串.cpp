//
//  647_回文子串.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/19.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 

示例 1：

输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 

提示：

输入的字符串长度不会超过 1000 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindromic-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "string"

using namespace std;
class Solution {
public:
    
    bool isPalindrome(string s){
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
                if (isPalindrome(s.substr(i, j + 1))) cnt ++;
            }
            res += cnt;
        }
        return res;
    }
};
