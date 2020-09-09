//
//  _80_删除排序数组中的重复项II.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/9/9.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int slow = 0, cnt = 1, num = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            if (num == nums[i]) {
                cnt ++;
                if (cnt <= 2) {
                    nums[++slow] = num;
                }
            }else{
                num = nums[i];
                nums[++slow] = num;
                cnt = 1;
            }
        }
        return slow + 1;
    }
};

