// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem115.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
    using ull = unsigned long long;
public:
    int numDistinct(string s, string t) {
        int sl = s.length(), tl = t.length();
        vector<vector<ull>> dp(sl + 1, vector<ull> (tl + 1));
        for(int i = 0; i < sl; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= sl; i++){
            for(int j = 1; j <= tl; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] += dp[i - 1][j - 1];
                }
                dp[i][j] += dp[i - 1][j];
            }
        }
        return dp[sl][tl];
    }
};
// @lc code=end

