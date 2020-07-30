//
//  103_二叉树的锯齿形层次遍历.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/30.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
 
 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

 例如：
 给定二叉树 [3,9,20,null,null,15,7],

     3
    / \
   9  20
     /  \
    15   7
 返回锯齿形层次遍历如下：

 [
   [3],
   [20,9],
   [15,7]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
#include <stdio.h>
#include "vector"
#include "TreeNode.hpp"
#include "queue"

using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if (root == nullptr) return res;
        
        queue<TreeNode *> queue;
        queue.push(root);
        
        bool flag = false;
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
            
            if (flag) reverse(tmp.begin(), tmp.end());
            flag = !flag;
            res.push_back(tmp);
        }
        
        return res;
    }
};
