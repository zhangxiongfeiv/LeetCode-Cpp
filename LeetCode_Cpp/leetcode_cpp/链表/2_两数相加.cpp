//
//  2_两数相加.cpp
//  LeetCode_Cpp
//
//  Created by zhangxiongfei on 2020/7/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "ListNode.hpp"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    
    ListNode *newHead = new ListNode(-1);
    ListNode *current = newHead;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int v1 = l1 == nullptr ? 0 : l1 -> val;
        int v2 = l2 == nullptr ? 0 : l2 -> val;
        
        l1 = l1 == nullptr ? nullptr : l1 -> next;
        l2 = l2 == nullptr ? nullptr : l2 -> next;
        
        int sum = v1 + v2 + carry;
        carry = 0;
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        }
        
        current -> next = new ListNode(sum);
        current = current -> next;
    }
    
    if (carry > 0) {
        current -> next = new ListNode(1);
    }
    
    return newHead -> next;
}

