//
//  404_左叶子之和.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/20.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "TreeNode.hpp"
#include "queue"

using namespace std;
class Solution {
public:
    
    /**
     
     方法一 :
     dfs
     
     */
    int sum;
    void sumOfLeftLeaves(TreeNode* root, bool isleft){
        if (root == nullptr) return;
        if (root -> left == nullptr && root -> right == nullptr && isleft) sum += root -> val;
        
        sumOfLeftLeaves(root -> left, true);
        sumOfLeftLeaves(root -> right, false);
    }
    
    int sumOfLeftLeaves1(TreeNode* root) {
        sumOfLeftLeaves(root, false);
        return sum;
    }
    
    /**
     
     方法二 :
     dfs
     
     */
    int sumOfLeftLeaves2(TreeNode* root) {
        if (root == nullptr) return sum;
        if (root -> left != nullptr && root -> left -> left == nullptr && root -> left -> right == nullptr) {
            sum += root -> left -> val;
        }
        sumOfLeftLeaves(root -> left);
        sumOfLeftLeaves(root -> right);
        return sum;
    }
    
    /**
     
     方法三 :
     bfs
     
     */
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return sum;
        queue<TreeNode *>queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();
            
            if (node -> left != nullptr && node -> left -> left == nullptr && node -> left -> right == nullptr) {
                sum += node -> left -> val;
            }
            
            if (node -> left != nullptr) queue.push(node -> left);
            if (node -> right != nullptr) queue.push(node -> right);
        }
        return sum;
    }
};
