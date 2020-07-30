//
//  101_对称二叉树.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/30.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个二叉树，检查它是否是镜像对称的。

 

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "queue"
#include "stack"
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    
    /**
     
     递归
     
     */
    bool isSymmetric(TreeNode *q, TreeNode *p){
        if (q == nullptr && p == nullptr) return true;
        if (q == nullptr || p == nullptr) return false;
        
        return (q -> val == p -> val) && (isSymmetric(q -> left, p -> right)) && (isSymmetric(q -> right, p -> left));
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
    
    /**
     
     迭代
     层序遍历
     
     */
    bool isSymmetric1(TreeNode* root) {
        if (root == nullptr) return true;
        
        queue<TreeNode *> queue;
        queue.push(root);
        queue.push(root);
        
        while (!queue.empty()) {
            TreeNode *node1 = queue.front();
            queue.pop();
            
            TreeNode *node2 = queue.front();
            queue.pop();
            
            if (node1 == nullptr && node2 == nullptr) continue;
            if (node1 == nullptr || node2 == nullptr) return false;
            if (node1 -> val != node2 -> val) return false;
            
            queue.push(node1 -> left);
            queue.push(node2 -> right);
            queue.push(node1 -> right);
            queue.push(node2 -> left);
        }
        return true;
    }
};
