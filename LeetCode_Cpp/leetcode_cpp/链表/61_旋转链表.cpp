//
//  61_旋转链表.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "ListNode.hpp"

using namespace std;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr || k == 0) return head;
    
        // 找出链表总长度
        // 同时找到链表的最后一个节点
        ListNode *n = head;
        int cnt = 0;
        ListNode *lastNode = nullptr;
        while (n != nullptr) {
            lastNode = n;
            n = n -> next;
            cnt ++;
        }
        k %= cnt;
        if (k == 0) return head;
                
        ListNode *slow = head;
        ListNode *fast = head;
        int i = 0;
        while (fast != nullptr) {
            fast = fast -> next;
            
            if (i ++ > k + 1) {
                slow = slow -> next;
            }
        }
        
        ListNode *newHead = slow -> next;
        slow -> next = nullptr;
        lastNode -> next = head;
        
        return newHead;
    }
};
