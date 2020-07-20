//
//  Node.hpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/18.
//  Copyright © 2020 飞熊. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "vector"

using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


#endif /* Node_hpp */
