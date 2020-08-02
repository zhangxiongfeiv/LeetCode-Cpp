//
//  114_二叉树展开为链表.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/8/2.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个二叉树，原地将它展开为一个单链表。

 

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "TreeNode.hpp"

using namespace std;
class Solution {
public:
    void flatten(TreeNode* root) {
    
        if (root == nullptr) return;
        
        flatten(root -> left);
        flatten(root -> right);
        
        TreeNode *node = root -> right;
        root -> right = root -> left;
        root -> left = nullptr;
        
        TreeNode *pre = root;
        while (pre -> right) {
            pre = pre -> right;
        }
        pre -> right = node;
    }
    
};

























