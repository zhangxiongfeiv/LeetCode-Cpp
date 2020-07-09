//
//  _328_奇偶链表.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/9.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
示例 2:

输入: 2->1->3->5->6->4->7->NULL
输出: 2->3->6->7->1->5->4->NULL
说明:

应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/odd-even-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "ListNode.hpp"

using namespace std;

class Solution {
public:
    
    /**
     
     使用额外的内存空间
     构建奇数链表 和 偶数链表
     最后再把 偶数链表串到奇数链表的尾部
     
     时间复杂度 : O(n)
     空间复杂度 : O(n)
     
     */
    ListNode* oddEvenList(ListNode* head) {
        // 节点为空，或者只有一个节点，直接 return
        if (head == nullptr || head -> next == nullptr) return head;
        
        ListNode *oddHead = new ListNode(-1);
        ListNode *oddnode = oddHead;
        
        ListNode *evenHead = new ListNode(-1);
        ListNode *evenNode = evenHead;
        
        int num = 0;
        while (head != nullptr) {
            int isodd = num & 1;
            num ++;
            if (isodd == 0) {
                // 偶数
                oddnode -> next = head;
                oddnode = oddnode -> next;
            }else{
                evenNode -> next = head;
                evenNode = evenNode -> next;
            }
            
            head = head -> next;
        }
        
        oddnode -> next = evenHead -> next;
        evenNode -> next = nullptr;
        
        return oddHead -> next;
    }
    
    /**
     
     原地算法
     使用了额外的三个指针
     串起来之前链表的node
     
     时间复杂度 : O(n)
     空间复杂度 : O(1)
     
     */
    ListNode* oddEvenList1(ListNode* head) {
        // 节点为空，或者只有一个节点，直接 return
        if (head == nullptr || head -> next == nullptr) return head;
     
        ListNode *odd = head, *even = head -> next, *evenHead = even;
        
        while (even != nullptr && even -> next != nullptr) {
            odd -> next = even -> next;
            odd = odd -> next;
            
            even -> next = odd -> next;
            even = even -> next;
        }
        
        odd -> next = evenHead;
        return head;
    }
};
