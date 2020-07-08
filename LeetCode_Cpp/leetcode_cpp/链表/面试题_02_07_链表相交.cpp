//
//  面试题_02_07_链表相交.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/8.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "ListNode.cpp"
#include <unordered_set>

using namespace std;

class Solution {
public:
    
    /**
     
     set 存储遍历过的值
     时间复杂度 : O(n)
     空间复杂度 : O(n)
     
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> set;
        while (headA) {
            set.insert(headA);
            headA = headA -> next;
        }
        while (headB) {
            if (set.count(headB)) return headB;
            headB = headB -> next;
        }
        return nullptr;
    }
    
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        
        ListNode *nodeA = headA, *nodeB = headB;
        while (nodeA != nullptr || nodeB != nullptr) {
            if (nodeA == nodeB) return nodeA;
            
            nodeA = nodeA == nullptr ? headB : nodeA -> next;
            headB = nodeB == nullptr ? headA : nodeB -> next;
        }
        
        return nullptr;
    }
};
