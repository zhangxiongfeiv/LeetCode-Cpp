//
//  513_找树左下角的值.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/14.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.hpp"
#include "queue"

using namespace std;
class Solution {
public:
    
    /**
     *
     * 二叉树层序遍历
     * 每遍历一层时，将每一层第一个值赋值给 targetNode
     *
     * */
    void bfs(TreeNode *root,TreeNode *targetNode){
        if (root == nullptr) return;
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = (int)queue.size();
            targetNode -> val = queue.front() -> val;
            while (size -- > 0) {
                TreeNode *node = queue.front();
                queue.pop();
                
                if (node -> left != nullptr) queue.push(node -> left);
                if (node -> right != nullptr) queue.push(node -> right);
            }
        }
    }
    
    int findBottomLeftValue(TreeNode* root) {
        TreeNode *targetNode = new TreeNode(root -> val);
        bfs(root, targetNode);
        return targetNode -> val;
    }
    
    /**
     *
     * dfs
     * 深度优先搜索
     *
     * 用 max 记录遍历的层级, 初始默认为 -1,代表还没有遍历
     * 用 res 记录最终结果.
     *
     * dfs过程中, 如果是叶子节点，并且 目前层级 max < depth.
     *    此时找到了，下一个较大结果, max = depth; res = root.val
     *
     * 再分别遍历 root 的左右子节点
     *
     * */
    int max = -1;
    int res;
    
    void dfs(TreeNode *root, int depth){
        if (root == nullptr) return;
        
        if (root -> left == nullptr && root -> right == nullptr && max < depth) {
            max = depth;
            res = root -> val;
        }
        dfs(root -> left, depth + 1);
        dfs(root -> right, depth + 1);
    }
    
    int findBottomLeftValue1(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

};
