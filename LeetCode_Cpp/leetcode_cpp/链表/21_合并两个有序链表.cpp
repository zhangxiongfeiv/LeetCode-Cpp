//
//  21_合并两个有序链表.cpp
//  LeetCode_Cpp
//
//  Created by zhangxiongfei on 2020/7/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "ListNode.hpp"

/**
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/// 递归
ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    
    if (l1 -> val < l2 -> val) {
        l1 -> next = mergeTwoListsRecursive(l1 -> next, l2);
        return l1;
    }else{
        l2 -> next = mergeTwoListsRecursive(l1, l2 -> next);
        return l2;
    }
}

/// 迭代
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    
    ListNode *newNode = new ListNode(-1);
    ListNode *current = newNode;
    while (l1 != nullptr || l2 != nullptr) {
        if (l1 == nullptr) {
            current -> next = l2;
            break;
        }
        
        if (l2 == nullptr) {
            current -> next = l1;
            break;
        }
        
        if (l1 -> val < l2 -> val) {
            current -> next = l1;
            l1 = l1 -> next;
        }else{
            current -> next = l2;
            l2 = l2 -> next;
        }
        current = current -> next;
    }
    delete current;
    return newNode -> next;
}
