//
//  897_递增顺序查找树.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/12.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给你一个树，请你 按中序遍历 重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。

 

示例 ：

输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \
1        7   9

输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9
 

提示：

给定树中的结点数介于 1 和 100 之间。
每个结点都有一个从 0 到 1000 范围内的唯一整数值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-order-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "TreeNode.hpp"
#include "stack"

using namespace std;
class Solution {
public:
    
    /**
     
     迭代
     
     */
    TreeNode* increasingBST1(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        stack<TreeNode *>stack;
        TreeNode *newHead = new TreeNode(-1);
        TreeNode *newNode = newHead;
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            
            newNode -> right = new TreeNode(root -> val);
            newNode = newNode -> right;
            
            root = root -> right;
        }
        
        return newHead -> right;
    }
    
    /**
     
     递归
     
     */
    TreeNode *newHead = new TreeNode(-1);
    TreeNode *newNode = newHead;
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        increasingBST(root -> left);
        newNode -> right = new TreeNode(root -> val);
        newNode = newNode -> right;
        
        increasingBST(root -> right);
        return newHead -> right;
    }
};
