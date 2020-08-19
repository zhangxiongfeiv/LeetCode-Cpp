//
//  387_字符串中的第一个唯一字符.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/18.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "string"
#include "unordered_map"

using namespace std;
class Solution {
public:
    
    /**
     *
     * 哈希表
     * 第一次遍历 哈希表存储元素出现次数
     * 再次遍历字符串 哈希表中存储的次数为1时，则为最终结果
     *
     * 时间复杂度 : O(n)
     * 空间复杂度 : O(n)
     *
     * */
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (char c : s) {
            if (map.count(c)) map[c] ++;
            else map[c] = 1;
        }
        
        for (int i = 0; i < s.length(); i ++) if(map[s[i]] == 1) return i;
        return -1;
    }
    
    /**
     *
     * 哈希表优化为数组
     *
     * 因为题目中有限制，字符串只包含小写字母
     * 所以可以使用长度为 26 的数组来存储字母的出现次数
     *
     * */
    int firstUniqChar1(string s) {
        int count[26] = {0};
        for (char c : s) count[c - 'a']++;
        
        for (int i = 0; i < s.length(); i ++) if(count[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
