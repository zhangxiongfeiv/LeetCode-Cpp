//
//  199_二叉树的右视图.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/18.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"
#include "queue"
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    
    /**
     
     BFS
     
     */
    vector<int> rightSideView1(TreeNode* root) {

        vector<int> res;
        if (root == nullptr) return res;
        
        queue<TreeNode *> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            int val = 0;
            int size = (int)queue.size();
            while (size -- > 0) {
                TreeNode *node = queue.front();
                queue.pop();
                val = node -> val;
                
                if (node -> left != nullptr) queue.push(node -> left);
                if (node -> right != nullptr) queue.push(node -> right);
            }
            
            res.push_back(val);
        }
        return res;
    }
    
    /**
     
     DFS
     
     */
    
    vector<int> res;
    void dfs(TreeNode *root, int depth){
        if (root == nullptr) return;
        
        if (depth == res.size()) {
            res.push_back(root -> val);
        }
        
        depth ++;
        dfs(root -> right, depth);
        dfs(root -> left, depth);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};
