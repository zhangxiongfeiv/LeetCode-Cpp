//
//  19.cpp
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head -> next == nullptr) return nullptr;
        
        ListNode *slow = new ListNode(-1);
        slow -> next = head;
        ListNode *fast = head;
        
        int k = 0;
        while (fast -> next != nullptr) {
            fast = fast -> next;
            n ++;
            if (n >= k) {
                slow = slow -> next;
            }
        }
        
        if (slow -> next == nullptr) {
            // 删除的是最后一个
            slow -> next = nullptr;
        }else if(slow -> next == head){
            // 删除的是第一个
            head = head -> next;
        }else{
            slow -> next = slow -> next -> next;
        }
        
        delete slow;
        delete fast;
        return head;
    }
};
