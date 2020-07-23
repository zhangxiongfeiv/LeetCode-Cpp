
//
//  1305_两棵二叉搜索树中的所有元素.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/23.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给你 root1 和 root2 这两棵二叉搜索树。

请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。
*/
 
#include <stdio.h>
#include "vector"
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    
    /**
     
     中序遍历 + 归并排序
     
     */
    void dfs(TreeNode *node, vector<int> &list){
        if (node == nullptr) return;
        
        dfs(node -> left, list);
        list.push_back(node -> val);
        dfs(node -> right, list);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> v1, v2;
        dfs(root1, v1);
        dfs(root2, v2);
        
        vector<int> res;
        int i = 0, j = 0;
        while (i < v1.size() || j < v2.size()) {
            if (i < v1.size() && (j == v2.size() || v1[i] <= v2[j])) {
                res.push_back(v1[i ++]);
            }else{
                res.push_back(v2[j ++]);
            }
        }
        return res;
    }
};
