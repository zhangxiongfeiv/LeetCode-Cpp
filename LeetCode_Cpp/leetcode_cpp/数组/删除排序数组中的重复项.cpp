//
//  删除排序数组中的重复项.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/8.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int i = 0;
        for (int j = 1; j < nums.size(); j ++) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        
        return i + 1;
    }
};
