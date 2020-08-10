//
//  152_乘积最大子数组.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/10.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"
#include <math.h>

using namespace std;
class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        // 最终结果
        int res = nums[0];
        // 以 i 结尾的子数组的最大乘积
        int maxres = nums[0];
        // 以 i 结尾的子数组的最小乘机
        int minres = nums[0];

        for (int i = 1; i < nums.size(); i ++) {
            int tmp = maxres;
            maxres = max(maxres * nums[i], max(nums[i], minres * nums[i]));
            minres = min(tmp * nums[i], min(nums[i], minres * nums[i]));

            res = max(res, maxres);
        }
        return res;
    }

};
