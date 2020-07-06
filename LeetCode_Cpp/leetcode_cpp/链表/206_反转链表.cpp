//
//  206_反转链表.cpp
//  LeetCodeCpp
//
//  Created by zhangxiongfei on 2020/7/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "ListNode.hpp"

/**
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

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
