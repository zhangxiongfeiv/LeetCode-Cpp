//
//  88_合并两个有序数组.cpp
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            
            int n1 = nums1[i];
            int n2 = nums2[j];
            
            if (n1 >= n2) {
                nums1[i + j + 1] = n1;
                i --;
            }else{
                nums1[i + j + 1] = n2;
                j --;
            }
        }
        
        while (j >= 0) {
            nums1[j] = nums2[j];
            j --;
        }
    }
};
