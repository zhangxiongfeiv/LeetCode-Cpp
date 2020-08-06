//
//  86_分隔链表.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "ListNode.hpp"

using namespace std;
class Solution {
public:
    
    // 申请两个新链表 more 和 less. more用来存储 >= x 的节点，less用来存储 < x 的节点
    // 拼接 less 和 more
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head -> next == nullptr) return head;
        
        ListNode *moreHead = new ListNode(-1);
        ListNode *more = moreHead;
        
        ListNode *lessHead = new ListNode(-1);
        ListNode *less = lessHead;
        
        while (head != nullptr) {
            if (head -> val < x) {
                less -> next = head;
                less = less -> next;
            }else{
                more -> next = head;
                more = more -> next;
            }
            head = head -> next;
        }
        
        more -> next = nullptr;
        less -> next = moreHead -> next;
        
        return lessHead -> next;
    }
};
