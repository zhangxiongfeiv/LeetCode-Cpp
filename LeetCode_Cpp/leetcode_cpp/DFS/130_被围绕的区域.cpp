//
//  130_被围绕的区域.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/11.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    
    int m = 0, n = 0;
    void dfs(vector<vector<char>>& board, int i, int j){
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        
        board[i][j] = 'A';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
    
    /*
     X X X X
     X O O X
     X X O X
     X O X X
     */
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        
        m = (int)board.size();
        n = (int)board[0].size();
        
        for (int i = 0; i < m; i ++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        
        for (int i = 0; i < n; i ++) {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};
