//
//  1025_除数博弈.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/24.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    
    bool divisorGame1(int N) {
        return (N & 1) == 0;
    }
    
    bool divisorGame(int N) {
        if (N == 1) return false;

        vector<bool> dp(N + 1, false);
        dp[1] = false;
        dp[2] = true;
        
        for (int i = 3; i <= N; i ++) {
            int j = 1;
            while (i % j == 0 && j < i) {
                if (dp[i - j] == false) {
                    dp[i] = true;
                    break;
                }
                j ++;
            }
        }
        return dp[N];
    }
};
