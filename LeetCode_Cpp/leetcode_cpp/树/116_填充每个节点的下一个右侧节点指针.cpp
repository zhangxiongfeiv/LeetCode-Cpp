//
//  116_填充每个节点的下一个右侧节点指针.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/3.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

示例：



输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}

解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 

提示：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "queue"

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

using namespace std;
class Solution {
public:
    
    /**
     bfs
     时间复杂度 : O(n)
     空间复杂度 : O(n)
     
     不符合题目 常量级额外空间的要求
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
    
    /**
     
     dfs
     时间复杂度 O(n)
     由于题目中说明递归占用的栈空间不算额外的空间复杂度，所以空间复杂度为 O(1)
     满足题目要求
     */
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        if (root -> left != nullptr) root -> left -> next = root -> right;
        if (root -> right != nullptr && root -> next != nullptr) {
            root -> right -> next = root -> next -> left;
        }
        
        connect(root -> left);
        connect(root -> right);
        
        return root;
    }
};
