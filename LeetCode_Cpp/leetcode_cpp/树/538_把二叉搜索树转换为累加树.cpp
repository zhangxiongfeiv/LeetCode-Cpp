//
//  538_把二叉搜索树转换为累加树.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/23.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

 

例如：

输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "stack"
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    
    /**
     
     递归中序遍历
     
     */
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return root;
        
        convertBST(root -> right);
        
        root -> val += sum;
        sum = root -> val;
        
        convertBST(root -> left);
        return root;
    }
    
    /**
     
     利用栈 中序遍历
     
     */
    TreeNode* convertBST1(TreeNode* root) {
        if (root == nullptr) return root;
        
        int sum = 0;
        TreeNode *node = root;
        stack<TreeNode *> stack;
        while (!stack.empty() || node != nullptr) {
            while (node != nullptr) {
                stack.push(node);
                node = node -> right;
            }
            
            node = stack.top();
            stack.pop();
            
            node -> val += sum;
            sum = node -> val;
            
            node = node -> left;
        }
        return root;
    }
    
};
