//
//  142_环形链表II.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。


 

进阶：
你是否可以不用额外空间解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "ListNode.hpp"

using namespace std;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) return nullptr;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if (slow == fast) break;
        }
        
        if (fast == nullptr || fast -> next == nullptr) return nullptr;
        
        slow = head;
        while (slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return slow;
    }
};
