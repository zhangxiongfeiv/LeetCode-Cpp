//
//  120_三角形最小路径和.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/14.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
 
 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

  

 例如，给定三角形：

 [
      [2],
     [3,4],
    [6,5,7],
   [4,1,8,3]
 ]
 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

  

 说明：

 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/triangle
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    
    /**
     
     动态规划
     
     1, 定义状态
        dp[i][j]表示 到达 三角形 i,j位置的最小路径和
     2, 定义初始值
        dp[0][0] = trangle[0][0]
     3, 定义状态转移方程
        j == 0 是最左端, 直接加上上一层的值
        j == triangle[i].size - 1 是最右端, 直接加上上一层的值
        否则 dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + num
     
     */
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<vector<int>> dp (n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        
        
        for (int i = 1; i < triangle.size(); i ++) {
            for (int j = 0; j < triangle[i].size(); j ++) {
                int num = triangle[i][j];
                if (j == 0) {
                    // 第一个
                    dp[i][j] = dp[i - 1][j] + num;
                }else if (j == triangle[i].size() - 1){
                    // 最后一个
                    dp[i][j] = dp[i - 1][j - 1] + num;
                }else{
                    // 中间元素
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + num;
                }
            }
        }
        
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
    
    /**
     
     空间复杂度的优化
     上述解题过程中, 发现我们在计算 dp[i][j]时, 只会用到 上一层的值
     
     
     */
    int minimumTotal1(vector<vector<int>>& triangle) {
        int n = (int)triangle.size();
        vector<int> dp(n);
        dp[0] = triangle[0][0];
        
        for (int i = 1; i < n; i ++) {
            for (int j = i; j >= 0; j --) {
                int num = triangle[i][j];
                if (j == 0) {
                    // 第一个
                    dp[j] = dp[j] + num;
                }else if (j == i){
                    // 最后一个
                    dp[j] = dp[j - 1] + num;
                }else{
                    // 中间元素
                    dp[j] = min(dp[j], dp[j - 1]) + num;
                }
            }
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};

