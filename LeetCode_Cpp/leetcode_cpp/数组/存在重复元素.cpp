//
//  存在重复元素.cpp
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
    bool containsDuplicate(vector<int>& nums) {
        
        set<int> set;
        for (int i = 0; i < nums.size(); i ++) {
            if (set.count(nums[i])) return true;
            set.insert(nums[i]);
        }
        return false;
    }
};
