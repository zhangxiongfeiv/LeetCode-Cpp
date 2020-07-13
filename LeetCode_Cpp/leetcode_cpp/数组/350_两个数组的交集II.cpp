//
//  350_两个数组的交集II.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/13.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "unordered_map"

using namespace std;
class Solution {
public:
    
    /**
     
     map 解决
     
     遍历 nums1， map中存储 数字对应的出现次数
     遍历 nums2， 如果map中对应的次数 > 0. 则拼入结果中，并且map中次数 --
     最终返回结果数组
     
     时间复杂度 : O(m + n)
     空间复杂度 : O(1) 除开结果数组外，没有用到额外的存储空间
     
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;
        
        unordered_map<int, int> map;
        for(int num : nums1){
            map[num] ++;
        }
        
        for(int num : nums2){
            if (map[num] > 0) {
                res.push_back(num);
                map[num] --;
            }
        }
        return res;
    }
    
    /**
     
     先排序
     
     先把 nums1 和 nums2排序
     然后使用双指针从头开始遍历 nums1 和 nums2
     
     当两指针指向的元素相等时， 说明是共同元素，加入结果数组中
     当num1 > num2时, i++. 去nums1数组后边找 和 num2相等的元素
     当num2 > num1时, j++. 去nums2数组后边找 和 num1相等的元素
     
     时间复杂度 : O(m * logm + n * logn + m + n) = O(m*logm + n*logn)
     空间复杂度 : O(1)
     
     */
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            int num1 = nums1[i], num2 = nums2[j];
            if (num1 == num2) {
                res.push_back(num1);
                i ++;
                j ++;
            }else if (num1 > num2){
                j ++;
            }else{
                i ++;
            }
        }
        return res;
    }
};
