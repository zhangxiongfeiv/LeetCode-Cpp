//
//  82_删除排序链表中的重复元素II.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/16.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "ListNode.hpp"

using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        
        ListNode *newHead = new ListNode(-1);
        if (head -> val == head -> next -> val) {
            ListNode *next = head -> next;
            while (next != nullptr && next -> val == head -> val) {
                next = next -> next;
            }
            newHead -> next = deleteDuplicates(next);
        }else{
            newHead -> next = head;
            head -> next = deleteDuplicates(head -> next);
        }
        return newHead -> next;
    }
};
