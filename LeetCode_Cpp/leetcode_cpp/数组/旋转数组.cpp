//
//  旋转数组.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/10.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
using namespace std;

/**
 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

 示例 1:

 输入: [1,2,3,4,5,6,7] 和 k = 3
 输出: [5,6,7,1,2,3,4]
 解释:
 向右旋转 1 步: [7,1,2,3,4,5,6]
 向右旋转 2 步: [6,7,1,2,3,4,5]
 向右旋转 3 步: [5,6,7,1,2,3,4]
 示例 2:

 输入: [-1,-100,3,99] 和 k = 2
 输出: [3,99,-1,-100]
 解释:
 向右旋转 1 步: [99,-1,-100,3]
 向右旋转 2 步: [3,99,-1,-100]
 说明:

 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 要求使用空间复杂度为 O(1) 的 原地 算法。
 */

class Solution {
public:
    /**
     
     分步旋转
     时间复杂度 : O(N * K)
     空间复杂度 : O(1)
     
     时间复杂度太高，不出意外地超时了
     
     */
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        for (int i = 0; i < k; i ++) {
            int tmp = nums[nums.size() - 1];
            for (int j = (int)nums.size() - 1; j > 0; j --) {
                nums[j] = nums[j - 1];
            }
            nums[0] = tmp;
        }
    }
    
    /**
     
     额外存储空间，备份 k 个元素
     
     */
    void rotate1(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0 || k == nums.size()) return;
        
        if (k > nums.size()) {
            // 保证 k 小于 nums.size()
            rotate1(nums, k % nums.size());
            return;
        }
        
        // 备份 k 个元素
        vector<int> tmp(k);
        
        for (int i = (int)nums.size() - k; i < nums.size(); i ++) {
            tmp[i + k - nums.size()] = nums[i];
        }
        
        for (int i = (int)nums.size() - 1; i >= k; i --) {
            nums[i] = nums[i - k];
        }
        
        for (int i = 0; i < k; i ++) {
            nums[i] = tmp[i];
        }
    }
    
    /**
     
     反转
     先整体反转
     再反转前半部分
     再反转后半部分
     
     */
    void rotate2(vector<int> & nums, int k){
        if (nums.size() == 0 || k == 0 || k == nums.size() - 1) return;
        
        if (k > nums.size()) {
            // 保证 k 小于 nums.size()
            rotate2(nums, k % nums.size());
            return;
        }
        
        int len = (int)nums.size();
        reverse(nums, 0, len - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, len - 1);
    }
    
    void reverse(vector<int> &nums, int left, int right){
        while (left < right) {
            
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            
            left ++;
            right --;
        }
    }
};
