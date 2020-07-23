//
//  64_最小路径和.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/23.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    
    /**
     动态规划
     时间复杂度 : O(m * n)
     空间复杂度 : O(m * n)
     */
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();
        auto dp = vector < vector <int> > (rows, vector <int> (cols));
        
        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (i == 0) {
                    dp[i][j] = grid[i][j] + (j == 0 ? 0 : dp[i][j - 1]);
                    continue;
                }
                if (j == 0) {
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                    continue;
                }
                
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp[rows - 1][cols - 1];
    }
    
    /**
     
     空间复杂度的优化
     时间复杂度 : O(m * n)
     空间复杂度 : O(m)
     
     */
    int minPathSum1(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();
        auto dp = vector <int> (cols);
        
        for (int i = 0; i < rows; i ++) {
            for (int j = 0; j < cols; j ++) {
                if (i == 0) {
                    dp[j] = grid[i][j] + (j == 0 ? 0 : dp[j - 1]);
                    continue;
                }
                if (j == 0) {
                    dp[j] = grid[i][j] + dp[j];
                    continue;
                }
                
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        
        return dp[cols - 1];
    }
};
