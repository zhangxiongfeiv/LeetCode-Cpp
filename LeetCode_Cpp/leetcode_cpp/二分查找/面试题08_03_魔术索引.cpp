//
//  面试题08.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/31.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    
    int res = -1;
    void binarySearch(vector<int>& nums, int begin, int end){
        if (begin >= end) return;
        int mid = begin + ((end - begin) >> 1);
        
        if (nums[mid] == mid) {
            // 相同
            res = mid;
            // 继续找左边 查看是否有更小结果
            binarySearch(nums, begin, mid);
        }else{
            // 不相同
            // 先找左边
            binarySearch(nums, begin, mid);
            
            // 左边没找到
            // 找右边
            if (res == -1) {
                binarySearch(nums, mid + 1, end);
            }
        }
    }

    int findMagicIndex(vector<int>& nums) {
        if (nums.size() == 1) return nums[0] == 0 ? 0 : -1;
        
        binarySearch(nums, 0, nums.size());
        return res;
    }
    
};
