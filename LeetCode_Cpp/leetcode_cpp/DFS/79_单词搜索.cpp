//
//  79_单词搜索.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/15.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "string"

using namespace std;
class Solution {
public:
    
    /**
    *
    * dfs 深度优先搜索
    *
    * 因为每一个路径都可以是起点，所以最外层需要两层循环。 以每个点开始为起点 dfs 查找
    * 因为 可以👆，👇，👈，👉四个放下走， 所以用 i， j 模拟四个方向走路
    * i - 1, j 代表 👈
    * i + 1, j 代表 👉
    * i, j - 1 代表 👆
    * i, j + 1 代表 👇
    *
    *
    * dfs 过程中
    *  如果 i < 0 || j < 0 || i >= m || j >= n 说明走出矩形区域。 return false
    *  如果 borad[i][j] != words[idx] 说明走不通，return false
    *
    *  否则, 进入下一次 dfs.
    *  因为走过的节点，不能重复走, 所以开始我们的想法是记录 visited 数组记录走过的节点
    *  题解中看到一种巧妙的方法, 直接修改原数组board, 访问过 board[i][j] == '0'. 因为 是 字符串中是字母，就不可能与 board[i][j] 相等
    *  相当于模拟了 visited数组，但是要问清楚，是否允许修改原矩形的数据, 如果不允许, 还得老老实实使用 visit 数组
    *
    *  ⚠️⚠️⚠️ 关键点 回溯
    *  当 此条路径不通时, 我们需要把路过此路径的节点值，重新置回原来的值⚠️.
    *  题解中非常巧妙的使用了一种方法, 记录临时变量, 放路径不通时, 将 board[i][j] 回复为 记录的临时变量
    *
    *
    * */
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int m, int n, int idx){
        if (i < 0 || j < 0 || i >= m || j >= n || word[idx] != board[i][j]) return false;
        if (idx == word.length() - 1) return true;
        
        char tmp = board[i][j];
        board[i][j] = '0';
        bool res =
        dfs(board, word, i - 1, j, m, n, idx + 1) ||    // 👈
        dfs(board, word, i + 1, j, m ,n, idx + 1) ||    // 👉
        dfs(board, word, i, j - 1, m, n, idx + 1) ||    // 👆
        dfs(board, word, i, j + 1, m, n, idx + 1);      // 👇
        
        // 走通了
        if (res == true) return true;
        
        // 这一步很重要 ⚠️⚠️⚠️
        // 没走通，状态重置, 回溯
        board[i][j] = tmp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string &word) {
        
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                bool res = dfs(board, word, i, j, (int)board.size(), (int)board[0].size(), 0);
                if (res == true) return true;
            }
        }
        return false;
    }
};
