//
//  112_路径总和.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/7.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.hpp"
#include <stack>
#include <queue>
using namespace std;
/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 递归
bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) return 0;
    if (root -> left == nullptr && root -> right == nullptr) return sum == root -> val;
    
    return hasPathSum(root -> left, sum - root -> val) || hasPathSum(root -> right, sum - root -> val);
}

// DFS 深度优先遍历
bool hasPathSum1(TreeNode* root, int sum) {
    if (root == nullptr) return 0;
    if (root -> left == nullptr && root -> right == nullptr) return sum == root -> val;
    
    stack<int> numstack;
    numstack.push(sum - root -> val);
    
    stack<TreeNode *> stack;
    stack.push(root);
    
    while (!stack.empty()) {
        
        TreeNode *node = stack.top();
        stack.pop();
        
        int num = numstack.top();
        numstack.pop();
        
        if (node -> left == nullptr && node -> right == nullptr && num == 0) return true;
        
        if (node -> left != nullptr) {
            stack.push(node -> left);
            numstack.push(num - node -> left -> val);
        }
        
        if (node -> right != nullptr) {
            stack.push(node -> right);
            numstack.push(num - node -> right -> val);
        }
    }
    
    return false;
}

// BFS 广度优先遍历
bool hasPathSum2(TreeNode* root, int sum) {
    if (root == nullptr) return 0;
    if (root -> left == nullptr && root -> right == nullptr) return sum == root -> val;
    
    queue<int> que_val;
    queue<TreeNode *>que_node;
    
    que_node.push(root);
    que_val.push(root -> val);
    
    while (!que_node.empty()) {
        TreeNode *node = que_node.front();
        que_node.pop();
        
        int tmp = que_val.front();
        que_val.pop();
        
        if (node -> left == nullptr && node -> right == nullptr && tmp == sum) {
            return true;
        }
        
        if (node -> left != nullptr) {
            que_node.push(node -> left);
            que_val.push(node -> left -> val + tmp);
        }
        
        if (node -> right != nullptr) {
            que_node.push(node -> right);
            que_val.push(node -> right -> val + tmp);
        }
    }
    
    return false;
}
