//
//  83_删除排序链表中的重复元素.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/16.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "ListNode.hpp"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *current = head;
        while (current != nullptr && current -> next != nullptr) {
            if (current -> val == current -> next -> val) {
                current -> next = current -> next -> next;
            }else{
                current = current -> next;
            }
        }
        return head;
    }
};
