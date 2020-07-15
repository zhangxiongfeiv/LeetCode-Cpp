//
//  剑指 Offer59I_滑动窗口的最大值.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/16.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "deque"

using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // 结果数组
        vector<int> res;
        // 维护单调递减双端队列
        deque<int> deque;
        
        for (int i = 0; i < nums.size(); i ++) {
            int num = nums[i];
            
            // while 循环
            // 当队列不为空，且 队尾元素 < num 时
            // 队尾元素出队
            while (!deque.empty() && nums[deque.back()] < num) {
                deque.pop_back();
            }
            
            // 入队新元素
            deque.push_back(i);
            
            // 判断对头元素下标有效性
            // 无效时，需要移除
            if (!deque.empty() && !isValidIdx(deque.front(), i, k)) {
                deque.pop_front();
            }
            
            // i - k + 1 为 结果数组下标
            // i - k + 1 >= 0，说明结果数组下标有效了
            // 也就是, 遍历了 k 个元素了
            // 此时开始对结果数组赋值
            if (i - k + 1 >= 0) {
                res.push_back(nums[deque.front()]);
            }
        }
        
        return res;
    }
    
    /*
    *
    * 计算 targetIdx 是否有限
    * i - k < targetIdx <= i 有效
    *
    * 否则无效，移除
    *
    * */
    bool isValidIdx(int targetIdx, int i, int k){
        return targetIdx > (i - k) && targetIdx <= i;
    }
};
