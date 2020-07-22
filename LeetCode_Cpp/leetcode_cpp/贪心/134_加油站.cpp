//
//  134_加油站.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/22.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, minIdx = -1, minSum = INT_MAX;
        for (int i = 0; i < gas.size(); i ++) {
            sum = gas[i] - cost[i] + sum;
            if (minSum > sum) {
                minSum = sum;
                minIdx = i;
            }
        }
        
        if (sum < 0) return -1;
        return (minIdx + 1) % gas.size();
    }
};
