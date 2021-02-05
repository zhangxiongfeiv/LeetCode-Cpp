//
//  17_18_最短子串.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2021/2/5.
//  Copyright © 2021 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "map"

using namespace std;
class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        map<int, int> need, store;
        for(auto cha : small)need[cha]++;

        int left = 0, right = 0;
        int start = 0, valid = 0;
        int len = INT_MAX;
        //先固定右端再逐渐缩短左端
        while(right < big.size()){
            int temp = big[right];
            right++;
            if(need.count(temp) != 0){
                store[temp]++;
                if(store[temp] == need[temp])valid++;
            }

            while(valid == need.size()){
                if(right - left < len){
                    len = right - left;
                    start = left;
                }

                int temp1 = big[left];
                left++;
                if(need.count(temp1)!=0){
                    if(need[temp1] == store[temp1])valid--;
                    store[temp1]--;
                }
            }
        }
        vector<int>res;
        if(len != INT_MAX)res = {start, start + len - 1};
        return res;
    }
};
