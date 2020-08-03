//
//  415_字符串相加.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/3.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "string"

using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int i = (int)num1.size() - 1, j = (int)num2.size() - 1, carry = 0;
        string res;
        while (i >= 0 || j >=0 || carry > 0) {
            int n1 = i < 0 ? 0 : num1[i --] - '0';
            int n2 = j < 0 ? 0 : num2[j --] - '0';
            
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            sum %= 10;

            res.push_back('0' + sum % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
