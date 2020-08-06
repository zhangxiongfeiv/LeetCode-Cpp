//
//  141_环形链表.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。


 

进阶：

你能用 O(1)（即，常量）内存解决此问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <stdio.h>
#include "ListNode.hpp"

using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) return false;
        
        ListNode *slow = head;
        ListNode *fast = head -> next;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if (slow == fast) return true;
        }
        return false;
    }
};
