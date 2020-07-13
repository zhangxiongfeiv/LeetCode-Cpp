//
//  349_两个数组的交集.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/13.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "set"

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> res;
        for(set<int>::iterator it = set1.begin(); it != set1.end(); it ++){
            if (set2.find(*it) != set2.end()) {
                res.push_back(*it);
            }
        }
        return res;
    }
};
