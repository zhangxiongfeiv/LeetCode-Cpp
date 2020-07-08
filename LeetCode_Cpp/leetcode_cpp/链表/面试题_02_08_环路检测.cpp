//
//  面试题_02_08_环路检测.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/8.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) return nullptr;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 因为给定的是有环链表
        // 所以没必要 判断快指针是否为空，一定不会为空
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if (slow == fast) break;
        }
        
        if (fast != slow) return nullptr;
        
        // 当 slow == fast 了
        slow = head;
        while (slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return slow;
    }
};
