//
//  118_杨辉三角.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/28.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        vector<int> line(numRows, 1);
        for (int i = 0; i < numRows; i ++) {
            auto t = 1;
            for (int j = 1; j < i; j ++) {
                auto tmp = line[j];
                line[j] = t + line[j];
                t = tmp;
            }
            res.push_back(vector<int>(line.begin(), line.begin() + i + 1));
        }
        
        return res;
    }
};
