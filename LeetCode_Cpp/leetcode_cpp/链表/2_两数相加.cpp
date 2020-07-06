//
//  2_两数相加.cpp
//  LeetCode_Cpp
//
//  Created by zhangxiongfei on 2020/7/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "ListNode.hpp"

/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    
    ListNode *newHead = new ListNode(-1);
    ListNode *current = newHead;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int v1 = l1 == nullptr ? 0 : l1 -> val;
        int v2 = l2 == nullptr ? 0 : l2 -> val;
        
        l1 = l1 == nullptr ? nullptr : l1 -> next;
        l2 = l2 == nullptr ? nullptr : l2 -> next;
        
        int sum = v1 + v2 + carry;
        carry = 0;
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        }
        
        current -> next = new ListNode(sum);
        current = current -> next;
    }
    
    if (carry > 0) {
        current -> next = new ListNode(1);
    }
    
    return newHead -> next;
}

