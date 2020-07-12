//
//  5460_好数对的数目.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/12.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "map"

using namespace std;
class Solution {
public:
    
    // 使用 map
    int numIdenticalPairs1(vector<int>& nums) {
        map<int, int> cntmap;
        for (int i = 0; i < nums.size(); i ++) {
            cntmap[nums[i]] += 1;
        }
        int res = 0;
        for (int i = 0; i < cntmap.size(); i ++) {
            int cnt = cntmap[i];
            if (cnt == 1) continue;
            
            res += (cnt * (cnt - 1)) / 2;
        }
        return res;
    }
    
    // 优化为数组
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> counts(101);
        for (int i = 0; i < nums.size(); i ++) {
            counts[nums[i]] += 1;
        }
        int res = 0;
        for (int i = 0; i < counts.size(); i ++) {
            int cnt = counts[i];
            if (cnt <= 1) continue;
            
            res += (cnt * (cnt - 1)) / 2;
        }
        return res;
    }
    

};
