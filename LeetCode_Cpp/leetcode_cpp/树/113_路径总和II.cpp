//
//  113_路径总和II.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/1.
//  Copyright © 2020 飞熊. All rights reserved.
//


/**
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include "vector"
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    
    // 结果数组
    vector<vector<int>> res;
    
    // 路径
    vector<int> path;
    
    void dfs(TreeNode *node, int sum){
        if (node == nullptr) return;
        
        path.push_back(node -> val);
        sum -= node -> val;
        
        if (sum == 0 && node -> left == nullptr && node -> right == nullptr) {
            res.push_back(path);
        }
        
        dfs(node -> left, sum);
        dfs(node -> right, sum);
        
        // 回溯
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return res;
    }
};

