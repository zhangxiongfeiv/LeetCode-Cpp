//
//  111_二叉树的最小深度.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/31.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <math.h>
#include "TreeNode.hpp"
#include "stack"
#include "queue"

using namespace std;
class Solution {
public:
    
    /**
     
     递归
     
     */
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        if (root -> left == nullptr) return minDepth(root -> right) + 1;
        if (root -> right == nullptr) return minDepth(root -> left) + 1;
        
        return fmin(minDepth(root -> left), minDepth(root -> right)) + 1;
    }
    
    /**
     
     迭代
     bfs
     
     bfs 当遍历到某个节点为叶子节点时, 直接return height + 1
     
     */
    int minDepth1(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<TreeNode *>queue;
        queue.push(root);
        int height = 0;
        while (!queue.empty()) {
            
            int size = (int)queue.size();
            while (size -- > 0) {
                TreeNode *node = queue.front();
                queue.pop();
                
                if (node -> left == nullptr && node -> right == nullptr) return height + 1;
                
                if (node -> right != nullptr) queue.push(node -> right);
                if (node -> left != nullptr) queue.push(node -> left);
            }
            
            height ++;
        }
        
        return height;
    }
    
    /**
     
     迭代
     dfs
     
     */
    int minDepth2(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int height = INT_MAX;
        stack<pair<TreeNode *, int>> stack;
        stack.push(make_pair(root, 1));
        
        while (!stack.empty()) {
            
            TreeNode *node = stack.top().first;
            int depth = stack.top().second;
            stack.pop();
            
            if (node -> left == nullptr && node -> right == nullptr) {
                height = fmin(height, depth);
            }
            
            if (node -> left != nullptr) {
                stack.push(make_pair(node -> left, depth + 1));
            }
            if (node -> right != nullptr) {
                stack.push(make_pair(node -> right, depth + 1));
            }
        }
        
        return height;
    }
};
