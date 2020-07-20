//
//  167_两数之和_II _输入有序数组.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/20.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int i = 0, j = (int)numbers.size() - 1;
        while (i <= j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) return {i + 1, j + 1};
            
            if (sum > target) {
                j --;
            }else {
                i ++;
            }
        }
        
        return {-1, -1};
    }
};
