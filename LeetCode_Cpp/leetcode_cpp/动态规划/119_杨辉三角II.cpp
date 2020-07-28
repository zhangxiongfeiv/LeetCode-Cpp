//
//  119_杨辉三角II.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/28.
//  Copyright © 2020 飞熊. All rights reserved.
//

/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



        在杨辉三角中，每个数是它左上方和右上方的数的和。

        示例:

        输入: 3
        输出: [1,3,3,1]

        [
            [1],
           [1,1],
          [1,2,1],
         [1,3,3,1],
        [1,4,6,4,1]
        ]

        来源：力扣（LeetCode）
        链接：https://leetcode-cn.com/problems/pascals-triangle-ii
        著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        
        for (int i = 0; i <= rowIndex; i ++) {
            res[i] = 1;
            for (int j = i; j > 1; j --) {
                res[j - 1] = res[j - 2] + res[j - 1];
            }
        }
        
        return res;
    }
};
