//
//  102_二叉树的层序遍历.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/30.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "TreeNode.hpp"
#include "vector"
#include "queue"

using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty()) {
            
            vector<int> tmp;
            int size = (int)queue.size();
            while (size -- > 0) {
                
                TreeNode *node = queue.front();
                tmp.push_back(node ->val);
                queue.pop();
                
                if (node -> left != nullptr) queue.push(node -> left);
                if (node -> right != nullptr) queue.push(node -> right);
            }
            res.push_back(tmp);
        }
        
        return res;
    }
};
