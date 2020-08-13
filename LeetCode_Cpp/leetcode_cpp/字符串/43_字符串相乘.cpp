//
//  43_字符串相乘.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/13.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "string"

using namespace std;
class Solution {
public:
    string addString(string &num1, string &num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
    
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ans = "0";
        int m = num1.size(), n = num2.size();
        for (int i = n - 1; i >= 0; i--) {
            string curr;
            int add = 0;
            for (int j = n - 1; j > i; j--) {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            while (add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for (auto &c : curr) {
                c += '0';
            }
            ans = addString(ans, curr);
        }
        return ans;
    }
};
