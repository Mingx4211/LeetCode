// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem44.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        s = string(" ") + s, p = string(" ") + p;
        int sl = s.length(), pl = p.length();
        vector<vector<int>> dp(pl, vector<int>(sl));
        dp[0][0] = 1;
        for(int i = 1; i < pl; i++){
            if(p[i] == '*'){
                int flag = 0;
                for(int j = 0; j < sl; j++){
                    if(dp[i - 1][j])
                        flag = 1;
                    if(flag)
                        dp[i][j] = 1;
                }
            }else if(p[i] == '?'){
                for(int j = 1; j < sl; j++){
                    if(dp[i - 1][j - 1])
                        dp[i][j] = 1;
                }
            }else{
                for(int j = 1; j < sl; j++){
                    if(p[i] == s[j] && dp[i - 1][j - 1])
                        dp[i][j] = 1;
                }
            }
        }
        return dp[pl - 1][sl - 1];
    }
};
// @lc code=end

