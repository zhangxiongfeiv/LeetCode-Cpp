//
//  687_最长同值路径.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/25.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include "687_最长同值路径.hpp"
#include "TreeNode.hpp"
#include "math.h"

using namespace std;
class Solution {
public:
    
    int res = 0;
    int dfs(TreeNode *root){
        if (root == nullptr) return 0;
        
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        
        int left = 0, right = 0;
        if (root -> left != nullptr && root -> left -> val == root -> val) {
            left = l + 1;
        }
        
        if (root -> right != nullptr && root -> right -> val == root -> val) {
            right = r + 1;
        }
        
        res = fmax(res, left + right);
        return fmax(left, right);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};
