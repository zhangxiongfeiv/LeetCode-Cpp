//
//  1295_统计位数为偶数的数字.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/18.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int num : nums) if ((num >= 10 && num < 100) || (num >= 1000 && num < 10000) || num == 100000) res ++;
        return res;
    }
};
