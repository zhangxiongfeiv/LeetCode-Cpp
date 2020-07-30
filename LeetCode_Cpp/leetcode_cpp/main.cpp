//
//  main.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <iostream>
#include "string"
#include "stack"
#include "vector"
#include "queue"
#include "TreeNode.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    TreeNode *node = new TreeNode(1);
    node -> left = new TreeNode(2);
    node -> right = new TreeNode(2);
    
    node -> left -> left = new TreeNode(3);
    node -> left -> right = new TreeNode(4);
    node -> right -> left = new TreeNode(4);
    node -> right -> right = new TreeNode(3);
    
    
    return 0;
}



