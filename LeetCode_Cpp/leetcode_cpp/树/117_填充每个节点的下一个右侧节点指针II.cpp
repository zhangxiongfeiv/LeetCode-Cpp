//
//  117_填充每个节点的下一个右侧节点指针II.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/3.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

进阶：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 

示例：



输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 

提示：

树中的节点数小于 6000
-100 <= node.val <= 100


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <iostream>
#include "queue"

using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    
    /**
     
     bfs
     时间复杂度 : O(n)
     空间复杂度 : O(n)
     
     不符合题目对时间复杂度的要求
     
     */
    Node* connect1(Node* root) {
        if (root == nullptr) return nullptr;
        queue<Node *>queue;
        queue.push(root);
        while (!queue.empty()) {
            int size = (int)queue.size();
            Node *node = nullptr;
            while (size-- > 0) {
                Node *tmp = queue.front();
                queue.pop();
                
                tmp -> next = node;
                node = tmp;
                
                if (tmp -> right != nullptr) queue.push(tmp -> right);
                if (tmp -> left != nullptr) queue.push(tmp -> left);
            }
        }
        return root;
    }
    
    Node *nextNode(Node *root){
        if (root == nullptr) return nullptr;
        
        if (root -> left != nullptr) return root -> left;
        if (root -> right != nullptr) return root -> right;
        
        if (root -> next != nullptr) return nextNode(root -> next);
        return nullptr;
    }
    
    /**
     
     dfs
     
     */
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        
        if (root -> left != nullptr) {
            if (root -> right != nullptr) {
                root -> left -> next = root -> right;
            }else{
                root -> left -> next = nextNode(root -> next);
            }
        }
        
        if (root -> right != nullptr) {
            root -> right -> next = nextNode(root -> next);
        }
        
        connect(root -> right);
        connect(root -> left);
        
        return root;
    }
        
        
};
