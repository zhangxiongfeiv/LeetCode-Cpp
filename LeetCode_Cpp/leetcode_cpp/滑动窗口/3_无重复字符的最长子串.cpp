//
//  3_无重复字符的最长子串.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/7.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "string"
#include "vector"
#include <math.h>
#include "unordered_set"

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return (int)s.length();
        unordered_set<char> set;
        int ans = 1;
        int i = 0;
        int j = 1;
        while (i < s.length() && j < s.length()) {
            if (set.find(s[j]) == set.end()) {
                set.insert(s[j ++]);
                ans = max(ans, j - i);
            }else{
                set.erase(s[i ++]);
            }
        }
        return ans;
    }
};
