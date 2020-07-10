//
//  55_跳跃游戏.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/9.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;

/**
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    
    /**
     
     从后往前
     
     时间复杂度 : O(n)
     空间复杂度 : O(1)
     
     题目标签是贪心
     但是，此解法貌似没有贪心思想
     
     查看题解后，发现从前往后的解法
     体现了贪心思想
     
     */
    bool canJump1(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        
        // targetIdx 是最终要到达的目的地
        long targetIdx = nums.size() - 1;
        for (long i = nums.size() - 2; i >= 0; i--) {
            
            int num = nums[i];
            
            // 如果 某位置 == 0 或者 i + num < targetIdx
            // 说明 i 位置的元素，不能到达 targetIdx
            // continue 继续向前找 可能能到达目的地的值
            if (num == 0 || (i + num < targetIdx)) continue;
            
            // i 位置能到达目的地
            // 如果 i==0，说明可以从开始位置到目的地
            // return true
            if (i == 0) return true;
            
            // 如果不是初始位置
            // i以前的位置，要到达 targetIdx 就可以了
            targetIdx = i;
        }
        
        return false;
    }
    
    /**
     
     从前往后
     每一步都取，能往后走最远的步数
     
     */
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;

        int diff = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int num = nums[i];
            
            diff = (diff - 1) > num ? (diff - 1) : num;
            
            if (diff == 0 && i != nums.size() - 1) return false;
        }
        return true;
    }
    
    /**
     
     从前往后
     每一步都取，能往后走最远的步数
     
     优化 如果 diff >= nums.size() - 1就没必要往后比了
     
     */
    bool canJump2(vector<int>& nums) {
        if (nums.size() <= 1) return true;

        int diff = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int num = nums[i];
            
            diff = (diff - 1) > num ? (diff - 1) : num;
            
            if (diff == 0 && i != nums.size() - 1) return false;
            
            if (diff >= nums.size() - 1 - i) return true;
        }
        return true;
    }
    
};
