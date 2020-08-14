//
//  面试题08_05_递归乘法.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/14.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    
    int multiply(int A, int B) {
        if(A == 0 || B == 0) return 0;
        // 保证 B > A
        // 减少递归次数
        if (A > B) return multiply(B, A);
        
        if (A == 1) return B;
        return multiply(A - 1, B);
    }
};
