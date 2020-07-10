//
//  121_买卖股票的最佳时机.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/10.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;

/**
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

 

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    
    /**
     
     暴力法
     遍历每一种可能
     时间复杂度 : O(n ^ 2)
     空间复杂度 : O(1)
     
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int max = 0;
        for (int i = 0; i < prices.size() - 1; i ++) {
            for (int j = i + 1; j < prices.size(); j ++) {
                
                int diff = prices[j] - prices[i];
                max = max > diff ? max : diff;
            }
        }
        return max;
    }
    
    /**
     
     动态规划
     记录最小价值 min 为数组首元素
     记录最大获利润 res
     
     从 index为1 元素开始遍历
     当最小值 > prices[i] 时, 说明当前下标没有利润。 将 min = prices[i] 即可
     当最小值 < prices[i] 时, res = max(res,prices[i] - min);
     
     时间复杂度 : O(n)
     空间复杂度 : O(1)
     
     */
    int maxProfit1(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        int res = 0, min = prices[0];
        
        for (int i = 1; i < prices.size(); i ++) {
            if (min > prices[i]) {
                min = prices[i];
                continue;
            }
            res = max(res,prices[i] - min);
        }
        return res;
    }
};
