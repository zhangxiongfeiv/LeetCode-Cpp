//
//  268_缺失数字.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/20.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    /**
     
     排序
     时间复杂度 : O(n * log n)
     
     */
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i ++) {
            if (i != nums[i]) return i;
        }
        
        return nums.size();
    }
    
    /**
     
     相加 求差值
     
     */
    int missingNumber1(vector<int>& nums) {

        int sum = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            sum += nums[i];
        }
        return ((len * (1 + len)) >> 1) - sum;
    }
    
    /**
     
     交换
     
     */
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    /**
     *
     * 挪动元素
     * 跟 287 寻找数组中重复元素解法一样
     *
     * 时间复杂度 : O(n)
     *
     * */
    // [9,6,4,2,3,5,7,0,1]
    int missingNumber2(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= nums.size() - 1) continue;
            while (nums[i] != i){
                if (nums[i] >= nums.size() - 1) break;
                swap(nums, nums[i], i);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) return i;
        }
        return nums.size();
    }

};
