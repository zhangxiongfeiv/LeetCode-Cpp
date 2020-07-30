//
//  105_从前序与中序遍历序列构造二叉树.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/30.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"
#include "unordered_map"
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    
    unordered_map<int, int> map;
    int rootIdx = 0;
    vector<int> preorder_;
    
    TreeNode *helper(int startIdx, int endIdx){
        if (startIdx > endIdx) return nullptr;
        
        TreeNode *root = new TreeNode(preorder_[rootIdx]);
        int idx = map[preorder_[rootIdx]];
        
        rootIdx ++;
        
        root -> left = helper(startIdx, idx - 1);
        root -> right = helper(idx + 1, endIdx);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0 || preorder.size() == 0 || inorder.size() != preorder.size()) return nullptr;
        if (inorder.size() == 0) return new TreeNode(inorder[0]);
        
        for (int i = 0; i < inorder.size(); i ++) {
            map[inorder[i]] = i;
        }
        
        preorder_ = preorder;
        
        return helper(0, (int)preorder_.size() - 1);
    }
};
