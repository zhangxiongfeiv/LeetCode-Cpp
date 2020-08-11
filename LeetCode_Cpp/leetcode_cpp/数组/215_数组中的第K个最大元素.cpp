//
//  215_数组中的第K个最大元素.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/11.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"
#include <queue>

using namespace std;
class Solution {
public:
    
    /**
     
     全排序
     时间复杂度 : O(N * logN)
     
     */
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    
    /**
     
     使用堆
     时间复杂度 : O(N * log K)
     
     */
    int findKthLargest1(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto num : nums) {
            if (heap.size() == k && heap.top() >= num) continue;
            if (heap.size() == k) heap.pop();
            heap.push(num);
        }
        return heap.top();
    }
    
    /**
     
     基于快排思想
     时间复杂度 : O(N)
     
     */
    
};
