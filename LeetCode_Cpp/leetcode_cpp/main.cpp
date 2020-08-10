//
//  main.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <iostream>
#include "string"
#include "stack"
#include "vector"
#include "queue"
#include "TreeNode.hpp"
#include <math.h>
#include "unordered_set"

using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    // 最终结果
    int res = nums[0];
    // 以 i 结尾的子数组的最大乘积
    int maxres = nums[0];
    // 以 i 结尾的子数组的最小乘机
    int minres = nums[0];

    for (int i = 1; i < nums.size(); i ++) {
        int tmp = maxres;
        maxres = max(maxres * nums[i], max(nums[i], minres * nums[i]));
        minres = min(tmp * nums[i], min(nums[i], minres * nums[i]));

        res = max(res, maxres);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    vector<int> vec = {2,3,-3,4,-2};
    int res = maxProduct(vec);
    cout << res << endl;
    return 0;
}



