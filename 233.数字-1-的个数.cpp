// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <cmath>
#include "commoncppproblem233.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        long long mulk = 1;
        for(int i = 0; n >= mulk; i++){
            res += (n / (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk); ; 
            mulk *= 10;
        }

        return res;
    }
};
// @lc code=end

