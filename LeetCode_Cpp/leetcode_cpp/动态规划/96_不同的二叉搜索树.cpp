//
//  96_不同的二叉搜索树.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/15.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    int numTrees(int n) {
    
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; i ++) {
            for (int j = 1; j <= i; j ++) {
                dp[i] += dp[j - 1] * dp[i - j];                
            }
        }
        
        return dp[n];
    }
};
