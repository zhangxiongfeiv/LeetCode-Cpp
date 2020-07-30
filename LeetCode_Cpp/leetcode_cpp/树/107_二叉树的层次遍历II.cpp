//
//  107_二叉树的层次遍历II.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/30.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <vector>
#include <queue>
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        
        queue<TreeNode *>queue;
        queue.push(root);
        
        while (!queue.empty()) {
            
            vector<int> tmp;
            int size = (int)queue.size();
            while (size -- > 0) {
                TreeNode *node = queue.front();
                queue.pop();
                
                tmp.push_back(node -> val);
                
                if (node -> left != nullptr) queue.push(node -> left);
                if (node -> right != nullptr) queue.push(node -> right);
            }
            
            res.push_back(tmp);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
