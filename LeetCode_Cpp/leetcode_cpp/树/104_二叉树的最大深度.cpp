//
//  104_二叉树的最大深度.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/28.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.hpp"
#include "math.h"
#include "queue"

using namespace std;
class Solution {
public:
    
    /**
     
     DFS
     
     */
    int maxDepthRecursive(TreeNode* root) {
        if (root == nullptr) return 0;
        return fmax(maxDepthRecursive(root -> left), maxDepthRecursive(root -> right)) + 1;
    }
    
    /**
     
     BFS
     
     */
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<TreeNode *>queue;
        queue.push(root);
        
        int height = 0;
        while (!queue.empty()) {
            int size = (int)queue.size();
            
            while (size -- > 0) {
                TreeNode *node = queue.front();
                queue.pop();
                
                if (node -> left != nullptr) {
                    queue.push(node -> left);
                }
                
                if (node -> right != nullptr) {
                    queue.push(node -> right);
                }
            }
            
            height ++;
        }
        return height;
    }
};
