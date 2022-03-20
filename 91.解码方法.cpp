// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem91.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int l = s.length();
        vector<int> dp(l + 1, 0);
        dp[0] = 1;
        if(s[0] != '0') dp[1] = 1;
        for(int i = 1; i < l; i++){
            if(s[i] != '0'){
                dp[i + 1] += dp[i];
            }
            if(s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26){
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[l];
    }
};
// @lc code=end

