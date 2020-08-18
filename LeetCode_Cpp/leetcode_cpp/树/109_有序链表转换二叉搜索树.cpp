//
//  109_有序链表转换二叉搜索树.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/18.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "ListNode.hpp"
#include "TreeNode.hpp"
#include "vector"

using namespace std;
class Solution {
public:
    
    /**
     
     思路一 : 转数组
     链表转数组后，可以实现随机访问
     有序链表中间节点一定是二叉搜索树的root节点
     找到root后，分治策略分别找左右两边的中间节点
     
     超时了...
     
     */
    TreeNode* sortedListToBST(vector<ListNode *>vector, int l, int r){
        if (l > r) return nullptr;
        int mid = l + ((r - l) >> 1);
        TreeNode *root = new TreeNode(vector[mid] -> val);
        TreeNode *left = sortedListToBST(vector, l, mid - 1);
        TreeNode *right = sortedListToBST(vector, mid + 1, r);
        root -> left = left;
        root -> right = right;
        return root;
    }
    
    TreeNode* sortedListToBST1(ListNode* head) {
        vector<ListNode *>vector;
        while (head) {
            vector.push_back(head);
            head = head -> next;
        }
        return sortedListToBST(vector, 0, (int)vector.size() - 1);
    }
    
    /**
     
     思路二 : 快慢指针找中间节点
     
     */
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head -> next == nullptr) return new TreeNode(head -> val);
        
        ListNode *prev = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = nullptr;
        
        TreeNode *root = new TreeNode(slow -> val);
        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(slow -> next);
        
        return root;
    }
    
};
