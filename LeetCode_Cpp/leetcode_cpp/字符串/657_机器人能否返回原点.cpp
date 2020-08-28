//
//  657_机器人能否返回原点.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/28.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "string"

using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.size() == 0) return true;
        
        int x = 0, y = 0;
        for (int i = 0; i < moves.size(); i ++) {
            char c = moves[i];
            if(c == 'R') x ++;
            else if(c == 'L') x --;
            else if(c == 'U') y ++;
            else if(c == 'D') y --;
        }
        return x == 0 && y == 0;
    }
};
