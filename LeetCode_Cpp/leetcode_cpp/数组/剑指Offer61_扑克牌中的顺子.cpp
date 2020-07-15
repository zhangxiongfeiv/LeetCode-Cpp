//
//  剑指Offer61_扑克牌中的顺子.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/15.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int joker = 0;
        int prev = -1;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) {
                joker ++;
                continue;
            }
            
            if (prev > 0) {
                int diff = nums[i] - prev;
                if (diff == 0) return false;
                if (diff > 1) {
                    if (joker < (diff - 1)) return false;
                    joker -= (diff - 1);
                }
            }
            prev = nums[i];
        }
        return true;
    }
};
