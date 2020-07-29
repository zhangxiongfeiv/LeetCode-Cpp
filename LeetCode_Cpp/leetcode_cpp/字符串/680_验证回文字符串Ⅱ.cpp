//
//  680_验证回文字符串Ⅱ.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/29.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:

字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "string"

using namespace std;
class Solution {
public:
    
    bool validPalindrome(string s, int begin, int end){
        if (begin + 1 >= end) return true;
        
        char c1 = s[begin];
        char c2 = s[end];
        
        return (c1 == c2 && validPalindrome(s, begin + 1, end - 1)) ||
        (c1 != c2 && (validPalindrome(s, begin + 1, end) || validPalindrome(s, begin, end - 1)));
    }
    
    bool validPalindrome(string s) {
        if (s.size() <= 2) return true;
        
        return validPalindrome(s, 0, s.length() - 1);
    }
};
