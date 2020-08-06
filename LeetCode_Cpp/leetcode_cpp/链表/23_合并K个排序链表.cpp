//
//  23_合并K个排序链表.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/4.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"
#include "ListNode.hpp"

using namespace std;
class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        
        ListNode *newHead = new ListNode(-1);
        ListNode *node = newHead;
        
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                node -> next = l2;
                break;
            }
            if (l2 == nullptr) {
                node -> next = l1;
                break;
            }
            
            if (l1 -> val < l2 -> val) {
                node -> next = l1;
                l1 = l1 -> next;
            }else{
                node -> next = l2;
                l2 = l2 -> next;
            }
            node = node -> next;
        }
        
        return newHead -> next;
    }
    
    // 暴力解法
    // 依次合并两个有序链表
    // 直到合并完全部链表
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        ListNode *l1 = lists[0];
        for (int i = 1; i < lists.size(); i ++) {
            l1 = mergeTwoLists(l1, lists[i]);
        }
        return l1;
    }
    
    // 分治策略
    ListNode* mergeKLists2(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];
        
        int step = 1;
        while (step < lists.size()) {
            int nextStep = step << 1;
            for (int i = 0; i + step < lists.size(); i += nextStep) {
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
            }
            step = nextStep;
        }
        return lists[0];
    }
};
