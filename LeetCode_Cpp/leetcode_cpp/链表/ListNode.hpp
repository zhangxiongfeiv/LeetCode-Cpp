//
//  ListNode.hpp
//  LeetCode_Cpp
//
//  Created by zhangxiongfei on 2020/7/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif /* ListNode_hpp */
