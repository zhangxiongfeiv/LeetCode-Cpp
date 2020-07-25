//
//  371_两整数之和.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/25.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>

using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        
        int lower, carry;
        while (true) {
            lower = a ^ b;
            carry = a & b;
            if (carry == 0) break;
            a = lower;
            b = carry << 1;
        }
        return lower;
    }
};
