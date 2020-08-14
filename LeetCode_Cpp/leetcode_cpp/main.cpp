//
//  main.cpp
//  leetcode_cpp
//
//  Created by zhangxiongfei on 2020/7/6.
//  Copyright © 2020 飞熊. All rights reserved.
//

#include <iostream>
#include "string"
#include "stack"
#include "vector"
#include "queue"
#include "TreeNode.hpp"
#include <math.h>
#include "unordered_set"

using namespace std;

int multiply(int A, int B) {
    if(A == 0 || B == 0) return 0;
    // 保证 B > A
    // 减少递归次数
    if (A > B) return multiply(B, A);
    
    if (A == 1) return B;
    return B + multiply(A - 1, B);
}

int main(int argc, const char * argv[]) {
    
    int res = multiply(5, 10);
    cout << res << endl;
    return 0;
}



