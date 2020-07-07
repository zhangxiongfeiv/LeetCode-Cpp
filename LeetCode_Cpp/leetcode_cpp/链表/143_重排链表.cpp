//
//  143_重排链表.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/7.
//  Copyright © 2020 飞熊. All rights reserved.
//

/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "ListNode.hpp"
#include "vector"

using namespace std;
class Solution {
public:

    // MARK: 思路一 : 找中点 / 反转 / 拼接
    /**
     
     迭代
     1，快慢指针找中间节点
     2, 反转中间节点
     3, 拼接原节点 和 反转后的节点
     */
    
    // 快慢指针 找中间节点
    ListNode* middleNode(ListNode *node){
        ListNode *slow = node;
        ListNode *fast = node -> next;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        if (fast != nullptr) slow = slow -> next;
        return slow;
    }
    
    // 反转链表
    // 递归
    ListNode* reverseNode(ListNode * node){
        if (node == nullptr || node -> next == nullptr) return node;
        
        ListNode *newNode = reverseNode(node -> next);
        
        node -> next -> next = node;
        node -> next = nullptr;
        
        return newNode;
    }
    
    // 迭代
    ListNode* reverseNode1(ListNode * node){
        if (node == nullptr || node -> next == nullptr) return node;
        
        ListNode *newHead = nullptr;
        while (node != nullptr) {
            ListNode *tmp = node -> next;
            node -> next = newHead;
            newHead = node;
            node = tmp;
        }
        
        return newHead;
    }
    
    
    void reorderList(ListNode* head) {
        
        // reversed middle node
        ListNode *lastnode = reverseNode1(middleNode(head));
        
        ListNode *prevnode = head;
        while (prevnode != nullptr && lastnode != nullptr) {
            
            // 先保存 穿起来的下一个节点
            ListNode *prev = prevnode -> next;
            ListNode *last = lastnode -> next;
            
            // 节点 下一个值修改
            prevnode -> next = lastnode;
            lastnode -> next = prev;
            
            // 赋值
            prevnode = prev;
            lastnode = last;
        }
        
        if (prevnode != nullptr) prevnode -> next = lastnode;
    }
    
    // MARK: 思路二 : 转数组实现随机访问
    /**
     
     由于链表 不能随机访问
     所以，我们遍历链表， 把链表中的节点都放入 数组 实现随机访问
     
     放入数组后，用头尾双指针拼接节点
     
     */
    void reorderList1(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return;
        
        vector<ListNode *> listnodes;
        while (head != nullptr) {
            listnodes.push_back(head);
            head = head -> next;
        }
        
        int i = 0, j = (int)listnodes.size() - 1;
        while (i < j) {
            listnodes[i] -> next = listnodes[j];
            i ++;
            
            // 奇数节点
            if (i == j) break;
            
            listnodes[j] -> next = listnodes[i];
            j --;
        }
        
        listnodes[i] -> next = nullptr;
    }
    
    // MARK: 递归
    void reorderList2(ListNode* head){
        if (head == nullptr || head -> next == nullptr) return;
        
        // 先求出链表的总长度
        int len = 0;
        ListNode *node = head;
        while (node != nullptr) {
            len ++;
            node = node -> next;
        }
    
        recorderListHelper(head, len);
    }
    
    // 传入一个节点，找到其尾节点
    ListNode * recorderListHelper(ListNode *node, int len){
        if (len == 1) {
            ListNode *outTail = node -> next;
            node -> next = nullptr;
            return outTail;
        }
        
        if (len == 2) {
            ListNode *outTail = node -> next -> next;
            node -> next -> next = nullptr;
            return outTail;
        }
        
        ListNode *tail = recorderListHelper(node -> next, len - 2);
        ListNode *subHead = node -> next;
        node -> next = tail;
        ListNode *outTail = tail -> next;
        tail -> next = subHead;
        return outTail;
    }
};
