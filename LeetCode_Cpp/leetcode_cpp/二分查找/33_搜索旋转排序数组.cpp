//
//  33_搜索旋转排序数组.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/16.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    
    /**
     *
     * 搜索旋转数组,最小值的下标
     * 根据下标，把旋转数组分为两个有序数组
     *
     * */
    int findMinIdx(vector<int>& nums){
        if (nums.size() == 1) return 0;
        
        int begain = 0, end = (int)nums.size() - 1;
        while (begain < end) {
            int mid = begain + ((end - begain) >> 1);
            int midNum = nums[mid];
            
            if (nums[end] > midNum) {
                // 说明 [mid, end] 单调递增
                // 则最小值在 mid 左边(包含 mid)
                end = mid;
            }else if (nums[end] < midNum){
                // 说明 [mid, end] 不是单调递增
                // 则最小值在 mid 右边(不包含 mid)
                begain = mid + 1;
            }else{
                // 相等时,缩小范围
                end --;
            }
        }
        return begain;
    }
    
    int binarySearch(vector<int> &nums, int begain, int end, int target){
        if (begain >= end) return nums[begain] == target ? begain : -1;
        
        int mid = begain + ((end - begain) >> 1);
        if (nums[mid] == target) return mid;
        
        if (nums[mid] > target) return binarySearch(nums, begain, mid - 1, target);
        return binarySearch(nums, mid + 1, end, target);
    }
    
    /**
     
     整体思路是 :
        1, 二分搜索查找,最小节点的下标，根据 minIdx 就可以把数组分为两个升序数组
        2, 根据两个有序数组边界, 看target在那个数组。
        3, 再对应数组二分查找
        3, 写了两遍二分, 一个找切分节点，一个查找target. 顺便复习了递归和迭代两种写法。
     
     */
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        
        int minIdx = findMinIdx(nums);
        if (target == nums[minIdx]) return minIdx;
        if (target < nums[minIdx]) return -1;
        
        // 在后边数组中 [minIdx + 1, end] 之间找
        if (target <= nums[nums.size() - 1]) return binarySearch(nums, minIdx + 1, (int)nums.size() - 1, target);
        // 在前边数组中 [0, minIdx - 1] 之间找
        return binarySearch(nums, 0, minIdx - 1, target);
    }
};
