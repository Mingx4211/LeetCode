// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem172.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        if(n >= 5){
            return n / 5 + trailingZeroes(n / 5);
        }
        return 0; 
    }
};
// @lc code=end

