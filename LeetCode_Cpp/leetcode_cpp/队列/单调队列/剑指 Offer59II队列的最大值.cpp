//
//  剑指 Offer59II队列的最大值.cpp
//  leetcode_cpp
//
//  Created by 飞熊 on 2020/7/15.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <stdio.h>
#include "queue"

/**
定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入:
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入:
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 

限制：

1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

using namespace std;
class MaxQueue {
public:

    /**
     
     利用额外的单调队列 存储空间
     
     单调队列头部保存最大值, 且从头部到尾部单调递减
     
     求max_value时,引文单调队列头部保存最大值，所以 当 maxqueue 为空时，返回 -1， 不空时，return maxqueue.front即可
     
     push_back时, queue直接入对即可。 循环 value > maxqueue.back() 时，循环执行 maxqueue.pop_back(); 最后 maxqueue.push_back(value)
     
     pop_front时, 如果 queue为空，直接return -1。 如果 queue不为空, 取出 val = queue.front();
                当 val == maxqueue 最大值时, maxqueue.pop_front()
     
     */
    queue<int> queue;
    deque<int> maxqueue;
    MaxQueue() {
    }
    
    int max_value() {
        if (maxqueue.empty()) return -1;
        return maxqueue.front();
    }
    
    void push_back(int value) {
        queue.push(value);
        
        while (!maxqueue.empty() && maxqueue.back() < value) {
            maxqueue.pop_back();
        }
        maxqueue.push_back(value);
    }
    
    int pop_front() {
        if (queue.empty()) return -1;
        int val = queue.front();
        queue.pop();
        if (val == maxqueue.front()) {
            maxqueue.pop_front();
        }
        return val;
    }
};

