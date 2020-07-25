//
//  38_外观数列.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/25.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "string"

using namespace std;
class Solution {
public:

    /**
     
     递归 + 一次遍历
     
     */
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string prestr = countAndSay(n - 1), res;
        
        int i = 0;
        for (int j = 1; j <= prestr.length(); j ++) {
            if (prestr[i] == prestr[j]) continue;
            
            res += to_string(j - i)+prestr[i];
            i = j;
        }
        
        return res;
    }
};
