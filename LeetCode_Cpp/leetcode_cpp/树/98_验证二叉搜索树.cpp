//
//  98_验证二叉搜索树.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/30.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <iostream>
#include <limits.h>
#include "TreeNode.hpp"
#include "stack"

using namespace std;
class Solution {
public:
    
    /**
     
     dfs 递归中序遍历
     
     */
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        
        bool l = isValidBST(root -> left);
        if (l == false) return false;
        
        cout << root -> val << endl;
        cout << pre << endl;
        
        if (root -> val < pre) return false;
        else pre = root -> val;
        
        return isValidBST(root -> right);
    }
    
    /**
     
     dfs 迭代中序遍历
     
     */
    bool isValidBST1(TreeNode* root) {
        if (root == nullptr) return true;
        
        stack<TreeNode *>stack;
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                
                root = root -> left;
            }
            
            root = stack.top();
            stack.pop();
            
            if (pre >= root -> val) return false;
            else pre = root -> val;
            
            root = root -> right;
        }
        return true;
    }
};
