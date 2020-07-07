//
//  面试题 10.01.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/7.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i1 = m - 1, i2 = n - 1, index = m + n - 1;
        
        while (i2 >= 0) {
            A[index --] = (i1 >= 0 && A[i1] > B[i2]) ? A[i1 --] : B[i2 --];
        }
    }
};
