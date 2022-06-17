#include <bits/stdc++.h>

/*
 * @lc app=leetcode.cn id=479 lang=cpp
 *
 * [479] 最大回文数乘积
 */

// @lc code=start
class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1){ 
            return 9;
        }
        int upper = pow(10, n) - 1;
        for(int left = upper; ; left--){   //循环写跳出条件就会报错,需要额外的返回值, 没有跳出条件说明一定会从里面return
            long p = left;
            for(int i = left; i > 0; i /= 10){
                p = p * 10 + (i % 10);
            }
            for(long i = upper; i * i >= p; i--){
                if(p % i == 0){
                    return p % 1337;
                }
            }
        }
    }
};
// @lc code=end

