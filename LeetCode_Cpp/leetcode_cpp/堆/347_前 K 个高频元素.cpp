//
//  347_前 K 个高频元素.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/8/14.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
 

提示：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include "vector"
#include <queue>
#include "unordered_map"

using namespace std;
class Solution {
public:
    
    /**
     
     最小堆优先级队列
     时间复杂度 : O(n * log k)
     空间复杂度 : O(n) 哈希表的开销
     
     */
    bool operator()(const pair<int, int>& o1, const pair<int, int> &o2){
        return o1.second > o2.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // 统计元素出现的次数
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i ++) {
            map[nums[i]] ++;
        }
        
        // 对次数排序
        // 小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>,Solution> queue;
        for (unordered_map<int, int> :: iterator it = map.begin(); it != map.end(); it ++) {
            queue.push(*it);
            if (queue.size() > k) {
                queue.pop();
            }
        }
        
        // 找到前K个高频元素，小顶堆最先弹出的是最小值，所有倒叙来赋值数组
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i --) {
            res[i] = queue.top().first;
            queue.pop();
        }
        return res;
    }
};
