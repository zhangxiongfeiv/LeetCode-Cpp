//
//  24_两两交换链表中的节点.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/7.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "ListNode.hpp"
using namespace std;

class Solution {
public:
    
    // MARK: 递归
    // 递归函数的作用，传入 head 返回 交换过的链表
    ListNode* swapPairs(ListNode* head) {
        // 递归结束条件 : head为空 或者 head -> next为空. 没有节点 或者 只有一个节点，没必要交换
        if (head == nullptr || head -> next == nullptr) return head;
        
        ListNode *node = head;
        
        // 传入 head -> next -> next
        // 这句递归函数，会把 head->next->next 后所有节点 交换
        ListNode *last = swapPairs(head->next->next);
        
        // 剩下要做的，就是交换 head 和 head.next
        ListNode *tmp = node -> next;
        node -> next = last;
        tmp -> next = node;
        head = tmp;
        
        return head;
    }
    
    // MARK: 迭代
    ListNode* swapPairs1(ListNode* head) {
        // head为空 或者 head -> next为空. 没有节点 或者 只有一个节点，没必要交换
        if (head == nullptr || head -> next == nullptr) return head;
        
        ListNode *prev = nullptr;
        ListNode *node = head;
        while (node != nullptr && node->next != nullptr) {
            ListNode *tmp = node -> next;
            node -> next = node -> next -> next;
            tmp -> next = node;
            
            // tmp 是反转后临时的头节点
            // 当 prev为空时，tmp为新的头节点
            // 当 prev不为空时, tmp是临时反转的头节点，prev的next指向 tmp
            if (prev == nullptr) {
                head = tmp;
            }else{
                prev -> next = tmp;
            }
            
            prev = node;
            node = node -> next;
        }
        return head;
    }
    
};
