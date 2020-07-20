//
//  1302_层数最深叶子节点的和.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/17.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "math.h"
#include "TreeNode.hpp"
#include "queue"

using namespace std;
class Solution {
public:
    
    /**
     *
     * 两遍 dfs
     * 第一遍，求出树高度
     * 第二遍遍历，是叶子节点 且 高度等于总高时，把结果加进去
     *
     * */
    int dfs(TreeNode * root){
        if (root == nullptr) return 0;
        return fmax(dfs(root -> left), dfs(root -> right)) + 1;
    }
    
    int res = 0;
    int dfs(TreeNode * root, int depth, int maxDepth){
        if (root == nullptr) return 0;
        if (root -> left == nullptr && root -> right == nullptr && depth == maxDepth) {
            res += root -> val;
        }
        return dfs(root -> left, depth + 1, maxDepth) + dfs(root -> right, depth + 1, maxDepth);
    }
    
    /**
     
     一遍 dfs
     
     */
    int maxDepth = 0;
    int sum = 0;
    void dfs1(TreeNode *root, int depth){
        if (root == nullptr) return;
        
        if (depth == maxDepth) {
            sum += root -> val;
        }else if (depth > maxDepth){
            sum = root -> val;
            maxDepth = depth;
        }
        dfs1(root -> left, depth + 1);
        dfs1(root -> right, depth + 1);
    }
    
    /**
     
     dfs
     
     */
    int deepestLeavesSum(TreeNode* root) {
       
        queue<TreeNode *> queue;
        queue.push(root);
        
        int res = 0;
        while (!queue.empty()) {
            
            res = 0;
            int size = (int)queue.size();
            while (size -- > 0) {
                TreeNode *node = queue.front();
                queue.pop();
                
                res += node -> val;
                if (node -> left != nullptr) queue.push(node -> left);
                if (node -> right != nullptr) queue.push(node -> right);
            }
        }
        
        return res;
    }
};
