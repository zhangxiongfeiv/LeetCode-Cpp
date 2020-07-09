//
//  面试题_02_04_分割链表.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/9.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。

示例:

输入: head = 3->5->8->5->10->2->1, x = 5
输出: 3->1->2->10->5->5->8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "ListNode.hpp"

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode *smallHead = new ListNode(-1);
        ListNode *smallNode = smallHead;
        
        ListNode *bigHead = new ListNode(-1);
        ListNode *bigNode = bigHead;
        
        while (head) {
            
            int val = head -> val;
            if (val < x) {
                smallNode -> next = head;
                smallNode = smallNode -> next;
            }else{
                bigNode -> next = head;
                bigNode = bigNode -> next;
            }
            
            head = head -> next;
        }
        
        smallNode -> next = bigHead -> next;
        bigNode -> next = nullptr;
        
        return smallHead -> next;
    }
};
