//
//  309_最佳买卖股票时机含冷冻期.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/10.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。

 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 示例:

 输入: [1,2,3,0,2]
 输出: 3
 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include "vector"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() <= 1) return 0;
        
        int res = 0, min = prices[0];
        vector<int> dp(prices.size(), 0);
        
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
