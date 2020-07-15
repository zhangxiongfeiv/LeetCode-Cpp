//
//  剑指Offer33_二叉搜索树的后序遍历序列.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/15.
//  Copyright © 2020 飞熊. All rights reserved.
//

/**
 
 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

  

 参考以下这颗二叉搜索树：

      5
     / \
    2   6
   / \
  1   3
 示例 1：

 输入: [1,6,3,2,5]
 输出: false
 示例 2：

 输入: [1,3,2,6,5]
 输出: true
  

 提示：

 数组长度 <= 1000


 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
#include <stdio.h>
#include "vector"

using namespace std;
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyHelper(postorder, 0, (int)postorder.size() - 1);
    }
    
    bool verifyHelper(vector<int> & postorder, int start, int end){
        if (start >= end) return true;
        
        int p = start;
        while (postorder[p] < postorder[end]) p ++;
        
        int mid = p;
        while (postorder[p] > postorder[end]) p ++;
        
        return (p == end) && verifyHelper(postorder, start, mid - 1) && verifyHelper(postorder, mid, end - 1);
    }
};
