//
//  面试题1704消失的数字.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/14.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

注意：本题相对书上原题稍作改动

示例 1：

输入：[3,0,1]
输出：2
 

示例 2：

输入：[9,6,4,2,3,5,7,0,1]
输出：8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/missing-number-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    /**
     
     异或
     
     时间复杂度 : O(n)
     空间复杂度 : O(1)
     
     异或性质 :
     0和任何值的异或等于本身，即：A ^ 0 = A
     异或本身等于0，即 A ^ A = 0
     异或满足结合律，即 A ^ B ^ C = A ^ ( B ^ C)

     
     */
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }
        res ^= nums.size();
        return res;
    }
    
    /**
     
     求和
     时间复杂度 : O(n)
     空间复杂度 : O(1)
     
     */
    int missingNumber1(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
        }
        int totalSum = (1 + nums.size()) * nums.size() / 2;
        return totalSum - sum;
    }
    
    
};
