//
//  1123_最深叶节点的最近公共祖先.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/14.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.hpp"
#include "math.h"

using namespace std;
class Solution {
public:
    
    // 如果当前节点是最深叶子节点的最近公共祖先，那么它的左右子树的高度一定是相等的
    // 否则高度低的那个子树的叶子节点深度一定比另一个子树的叶子节点的深度小
    // 所以向高度较高的子数中查找
    // 所以只需要dfs遍历找到左右子树高度相等的根节点即出答案
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr) return root;
        
        int ld = depth(root -> left);
        int rd = depth(root -> right);
        
        if (ld == rd) return root;
        
        if (ld > rd) return lcaDeepestLeaves(root -> left);
            
        return lcaDeepestLeaves(root -> right);
    }
    
    // 求出节点高度
    int depth(TreeNode *root){
        if (root == nullptr) return 0;
        
        int ld = depth(root -> left);
        int rd = depth(root -> right);
        
        return fmax(ld, rd) + 1;
    }
};
