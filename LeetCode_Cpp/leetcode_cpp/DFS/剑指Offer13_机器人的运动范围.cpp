//
//  剑指Offer13_机器人的运动范围.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/13.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    
    /**
     
     dfs 深度优先搜索
     
     */
    int movingCount(int m, int n, int k) {
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        return dfs(0,0,m,n,k,visited);
    }
    
    int dfs(int i, int j, int m, int n, int k, vector<vector<bool>>& visited){
        if (i < 0 || j < 0 || i >= m || j >= n || sum(i) + sum(j) > k || visited[i][j] == true) {
            return 0;
        }
        
        visited[i][j] = true;
        
        return 1 + dfs(i - 1, j, m, n, k, visited) + dfs(i + 1, j, m, n,k, visited) + dfs(i, j - 1, m, n,k, visited) + dfs(i, j + 1, m, n,k, visited);
    }
    
    int sum(int x){
        if (x < 10) return x;
        int res = 0;
        while (x > 0) {
            res += x%10;
            x /= 10;
        }
        return res;
    }
};
