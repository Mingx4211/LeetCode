#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1), nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for(int j = 2; j <= n + 1; j++){
            for(int i = 0; i < n + 2 - j; i++){
                for(int k = i + 1; k < i + j; k++){
                    dp[i][i + j] = max(dp[i][i + j], dp[i][k] + dp[k][i + j] + nums[i] * nums[k] * nums[i + j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
// @lc code=end

