//
//  只出现一次的数字.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/11.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "set"

using namespace std;
class Solution {
public:
    
    /**
     
     set存储
     
     */
    int singleNumber(vector<int>& nums) {
        set<int> set;
        for (int i = 0; i < nums.size(); i ++) {
            if (set.count(nums[i])) {
                set.erase(nums[i]);
            }else{
                set.insert(nums[i]);
            }
        }
        
        int ans = 0;
        for(auto j : set)  ans = j;
        return ans;
    }
    
    /**
     
     位运算
     
     */
    int singleNumber1(vector<int>& nums) {
        int single = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            single ^= num;
        }
        return single;
    }
};
