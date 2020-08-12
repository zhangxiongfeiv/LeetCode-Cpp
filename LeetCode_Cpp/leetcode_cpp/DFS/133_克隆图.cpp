//
//  133_克隆图.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/12.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "vector"
#include "unordered_map"
#include "queue"

using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    
    /**
     
     dfs 深度优先搜索
     
     */
    // visited 字典用来保存访问过的节点
    unordered_map<Node *, Node *>visited;
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        // 如果访问过, 直接返回新建的节点
        if (visited.find(node) != visited.end()) return visited[node];
        
        // 没有访问过, clone 节点
        Node *cloneNode = new Node(node -> val);
        // 记录在map中
        visited[node] = cloneNode;
        
        // dfs 子节点
        for (auto& neighbor : node -> neighbors) {
            cloneNode -> neighbors.push_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
    
    /**
     
     bfs 广度优先搜索
     
     */
    Node* bfs(Node* node) {
        if (node == nullptr) return nullptr;
    
        // 用来记录是否访问过
        unordered_map<Node *, Node *> visited;
        // 使用 queue 层序遍历
        queue<Node *> queue;
        queue.push(node);
        visited[node] = new Node(node -> val);
        
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            
            // bfs遍历子节点
            for (auto& neighbor : cur -> neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    // 如果没有访问过, 创建clone节点
                    visited[neighbor] = new Node(neighbor -> val);
                    queue.push(neighbor);
                }
                visited[cur] -> neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};

