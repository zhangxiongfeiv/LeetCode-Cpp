//
//  1502_判断能否形成等差数列.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/17.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i ++) {
            if (diff != arr[i] - arr[i - 1]) return false;
        }
        return true;
    }
};
