//
//  206_反转链表.cpp
//  LeetCodeCpp
//
//  Created by zhangxiongfei on 2020/7/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include "206_反转链表.hpp"

// 递归
ListNode* reverseListRecursive(ListNode* head) {
    if (head == nullptr || head -> next == nullptr) return head;
    
    ListNode *node = reverseListRecursive(head -> next);
    head -> next -> next = head;
    head -> next = nullptr;
    
    return node;
}

// 迭代
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head -> next == nullptr) return head;
    
    ListNode *newHead = nullptr;
    while (head != nullptr) {
        ListNode *tmp = head -> next;
        head -> next = newHead;
        newHead = head;
        head = tmp;
    }
    
    return newHead;
}
