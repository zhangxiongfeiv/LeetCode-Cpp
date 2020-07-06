//
//  206_反转链表.hpp
//  LeetCodeCpp
//
//  Created by zhangxiongfei on 2020/7/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

#ifndef _06______hpp
#define _06______hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head);

#endif /* _06______hpp */
