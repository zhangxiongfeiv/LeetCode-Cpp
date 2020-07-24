//
//  1290_二进制链表转整数.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/24.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "ListNode.hpp"

using namespace std;
class Solution {
public:
    int getDecimalValue(ListNode* head) {

        ListNode *node = head;
        int ans = 0;
        while (node != nullptr) {
            ans = ans *2 + node -> val;
            node = node -> next;
        }
        return ans;
    }
};
