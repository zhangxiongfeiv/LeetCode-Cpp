//
//  106_从中序与后序遍历序列构造二叉树.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/30.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "unordered_map"
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    
    unordered_map<int, int> map;
    int rootIdx = 0;
    vector<int> postorder_;
    
    TreeNode* helper(int startIdx, int endIdx){
        if (startIdx > endIdx) return nullptr;
        
        // 根节点在 中序遍历中的 下标
        int idx = map[postorder_[rootIdx]];
        // 根节点
        TreeNode *root = new TreeNode(postorder_[rootIdx]);
        
        rootIdx --;
        
        // 右子树
        root -> right = helper(idx + 1, endIdx);
        
        // 左子树
        root -> left = helper(startIdx, idx - 1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0 || inorder.size() != postorder.size()) return nullptr;
        if (inorder.size() == 1) return new TreeNode(inorder[0]);
        
        postorder_ = postorder;
        rootIdx = postorder_.size() - 1;
        for (int i = 0; i < inorder.size(); i ++) {
            map[inorder[i]] = i;
        }
        
        return helper(0, inorder.size() - 1);
    }
};
