//
//  344_反转字符串.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/28.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

 

示例 1：

输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
示例 2：

输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    
    /**
     
     迭代
     
     */
    void reverseString1(vector<char>& s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            char c1 = s[i];
            s[i] = s[j];
            s[j] = c1;
            i ++; j --;
        }
    }
    
    /**
     
     递归
     
     */
    void reverseHelper(vector<char>& s, int i, int j){
        if (i >= j) return;
        reverseHelper(s, i + 1, j - 1);
        
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    
    void reverseString(vector<char>& s) {
        if (s.size() <= 1) return;
        reverseHelper(s, 0, (int)s.size() - 1);
    }
};
