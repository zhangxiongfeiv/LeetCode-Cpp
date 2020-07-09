//
//  1_两数之和.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/8.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> map(nums.size());
        for (int i=0; i<nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                return {map[nums[i]], i};
            }
            map[target - nums[i]] = i;
        }
        
        return {};
    }
};
