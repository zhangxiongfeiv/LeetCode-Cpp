//
//  TreeNode.hpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/7.
//  Copyright © 2020 飞熊. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif /* TreeNode_hpp */
