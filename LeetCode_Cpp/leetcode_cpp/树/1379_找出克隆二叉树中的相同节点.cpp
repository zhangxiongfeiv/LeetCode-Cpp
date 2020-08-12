//
//  1379_找出克隆二叉树中的相同节点.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/12.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    
    TreeNode *dfs(TreeNode *node, TreeNode *target){
        if (node == nullptr || target -> val == node -> val) return node;
        
        TreeNode *left = dfs(node -> left, target);
        if (left) return left;
        return dfs(node -> right, target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned, target);
    }
};
