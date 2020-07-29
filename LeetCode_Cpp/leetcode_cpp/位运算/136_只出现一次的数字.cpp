//
//  136_只出现一次的数字.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/29.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "set"

using namespace std;
class Solution {
public:
    
    /**
     set去重复
     */
    int singleNumber(vector<int>& nums) {
        set<int> count;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < nums.size(); i ++) {
            count.insert(nums[i]);
            sum2 += nums[i];
        }
        for (set<int> :: iterator it = count.begin(); it != count.end(); it ++) {
            sum1 += *it;
        }
        return sum1 * 2 - sum1;
    }
    
    int singleNumber1(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i ++) {
            res = res ^ nums[i];
        }
        return res;
    }
};
