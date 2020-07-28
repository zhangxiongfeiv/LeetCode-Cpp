//
//  94_二叉树的中序遍历.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/28.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"
#include "stack"
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    
    vector<int> res;
    /// 递归
    /// @param root 树根节点
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return res;
        
        inorderTraversal(root->left);
        res.push_back(root -> val);
        inorderTraversal(root->right);
        
        return res;
    }
    
    /// 迭代
    /// @param root 树根节点
    vector<int> inorderTraversal1(TreeNode* root) {
        if (root == nullptr) return res;

        stack<TreeNode *>stack;
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            
            root = stack.top();
            stack.pop();
            res.push_back(root -> val);
            
            root = root -> right;
        }
        
        return res;
    }
};
