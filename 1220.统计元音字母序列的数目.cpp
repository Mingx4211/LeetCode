/*
 * @lc app=leetcode.cn id=1220 lang=cpp
 *
 * [1220] 统计元音字母序列的数目
 */

// @lc code=start
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long long> dp(5, 1);
        vector<long long> temp(5, 0);
        for(int i = 2; i <= n; i++){
            temp[0] = dp[1] + dp[2] + dp[4];
            temp[1] = dp[0] + dp[2];
            temp[2] = dp[1] + dp[3];
            temp[3] = dp[2];
            temp[4] = dp[2] + dp[3];
            dp = temp;
        }
        long long m = 1000000000 + 7;
        long long res = 0;
        for(int i = 0; i < 5; i++){
            res = (res + dp[i]) % m;
        }
        return res;
    }
};
// @lc code=end

