//
//  459_重复的子字符串.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/24.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:

输入: "abab"

输出: True

解释: 可由子字符串 "ab" 重复两次构成。
示例 2:

输入: "aba"

输出: False
示例 3:

输入: "abcabcabcabc"

输出: True

解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/repeated-substring-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "string"

using namespace std;
class Solution {
public:
    /**
    *
    * 暴力法
    * 枚举每一种可能的重复子串
    * 匹配
    *
    * 时间复杂度 : O(n ^ 2)
    * 空间复杂度 : O(1)
    *
    * */
    bool repeatedSubstringPattern(string s) {
        int len = 1;
        while (len <= s.length() / 2) {
            if (s.length() % len != 0) {
                len ++;
                continue;
            }
            
            string s1 = s.substr(0, len);
            for (int i = len; i + len <= s.length(); i += len) {
                string s2 = s.substr(i, len);
                if (s1 != s2) break;
                if (i + len == s.length()) return true;
            }
            len ++;
        }
        return false;
    }
    
    /**
     *
     * 思路二 :
     * 题解区大神思路
     * 如果可以分为 n 个重复子串
     * 则 s + s 截取掉 头尾两个字符的子串，必然包含 s
     *
     * */
    bool repeatedSubstringPattern1(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};
