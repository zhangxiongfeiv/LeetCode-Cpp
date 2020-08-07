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

int lengthOfLongestSubstring(string s) {
    if (s.length() <= 1) return (int)s.length();
    unordered_set<char> set;
    int ans = 0;
    int left = 0;
    int right = 0;
    while (right < s.length()) {
        if (!set.count(s[right])) {
            ans = max(ans, right - left + 1);
            set.insert(s[right ++]);
        }else{
            set.erase(s[left ++]);
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    int res = lengthOfLongestSubstring("abcabcbb");
    cout << res << endl;
    return 0;
}



