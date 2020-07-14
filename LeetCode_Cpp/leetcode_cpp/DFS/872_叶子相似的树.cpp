//
//  872_叶子相似的树.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/14.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    
    /**
     *
     * dfs 二叉树
     * 分别dfs两棵树
     * 当叶子节点时, 将叶子节点加入 list
     *
     * 遍历判断 两个list是否相同
     *
     * */
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> vec1;
        dfs(root1, vec1);
        
        vector<int> vec2;
        dfs(root2, vec2);
        
        return vec1 == vec2;
    }
    
    void dfs(TreeNode *node, vector<int>& res){
        if (node == nullptr) return;
        if (node -> left == nullptr && node -> right == nullptr) {
            res.push_back(node -> val);
        }
        dfs(node -> left, res);
        dfs(node -> right, res);
    }
};
