//
//  240_搜索二维矩阵II.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/29.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int i = 0, j = (int)matrix[0].size() - 1;
        
        while (i < matrix.size() && j >= 0) {
            if (target == matrix[i][j]) return true;
            
            if (target > matrix[i][j]) i ++;
            else j --;
        }
        
        return false;
    }
};
