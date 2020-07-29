//
//  125_验证回文串.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/29.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "string"

using namespace std;
class Solution {
public:
    
    /**
     
     迭代
     
     */
    bool isPalindrome1(string s) {
        if (s.size() <= 1) return true;
        
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            char c1 = s[i];
            char c2 = s[j];
            
            if (!isalnum(c1)) {
                i ++;
                continue;
            }
            
            if (!isalnum(c2)) {
                j --;
                continue;
            }
            
            i ++;
            j --;
            if (tolower(c1) != tolower(c2)) return false;
        }
        return true;
    }
    
    /**
     
     递归
     
     */
    bool isPalindrome(string s, int begin , int end){
        if (begin >= end) return true;
        
        char c1 = s[begin];
        char c2 = s[end];
        
        if (!isalnum(c1)) {
            return isPalindrome(s, begin + 1, end);
        }else if (!isalnum(c2)){
            return isPalindrome(s, begin, end - 1);
        }
        return tolower(c1) == tolower(c2) && isPalindrome(s, begin + 1, end - 1);
    }
    
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        return isPalindrome(s, 0, (int)s.length() - 1);
    }
};
