//
//  429_N叉树的层序遍历.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/18.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "Node.hpp"
#include "queue"

using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> res;
        if (root == nullptr) return res;
        
        queue<Node *> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            vector<int> list;
            int size = (int)queue.size();
            while (size -- > 0) {
                Node *node = queue.front();
                queue.pop();
                
                list.push_back(node -> val);
                for (int i = 0; i < node -> children.size(); i ++) {
                    queue.push(node -> children[i]);
                }
            }
            res.push_back(list);
        }
        
        return res;
    }
};
