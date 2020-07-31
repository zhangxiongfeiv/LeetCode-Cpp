//
//  108_将有序数组转换为二叉搜索树.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/31.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    
    // 左闭又开
    TreeNode* helper(vector<int>& nums, int begin, int end){
        if (begin >= end) return nullptr;
        
        int mid = begin + ((end - begin) >> 1);
        TreeNode *root = new TreeNode(nums[mid]);
        
        root -> left = helper(nums, begin, mid);
        root -> right = helper(nums, mid + 1, end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return helper(nums, 0, nums.size());
    }
};
