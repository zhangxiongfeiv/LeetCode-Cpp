//
//  1019_链表中的下一个更大节点.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/20.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "stack"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> tmp;
        stack<int> stack;
        for (auto p = head; p; p = p -> next) {
            tmp.emplace_back(p -> val);
        }
        
        vector<int> res(tmp.size());
        
        for (int i = 0; i < tmp.size(); i ++) {
            while (!stack.empty() && tmp[stack.top()] < tmp[i]) {
                auto top = stack.top();
                stack.pop();
                res[top] = tmp[i];
            }
            
            stack.push(i);
        }
        
        return res;
    }
};
