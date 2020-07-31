//
//  110_平衡二叉树.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/31.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "TreeNode.hpp"
#include <math.h>

using namespace std;
class Solution {
public:
    
    int height(TreeNode *root){
        if (root == nullptr) return 0;
        
        int l = height(root -> left);
        if (l == -1) return -1;
        
        int r = height(root -> right);
        if (r == -1) return -1;
        
        return fabs(r - l) <= 1 ? fmax(l, r) + 1 : -1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        return height(root) != -1;
    }
};
