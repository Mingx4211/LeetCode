#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=691 lang=cpp
 *
 * [691] 贴纸拼词
 */

// @lc code=start
class Solution {
public:
    string target;
    int m;
    vector<int> dp;
    vector<string> stickers;

    int dfs(int mask) {
        if (dp[mask] != -1)     return dp[mask];
        dp[mask] = m + 1;
        for (int i = 0; i < stickers.size(); i++) {
            vector<int> sti(26);
            for (auto c : stickers[i]) {
                sti[c - 'a']++;
            }

            int left = mask;
            for (int j = 0; j < m; j++) {
                if ((mask & (1 << j)) && sti[target[j] - 'a'] > 0) {
                    sti[target[j] - 'a']--;
                    left ^= 1 << j;
                }
            }
            if (left < mask) {
                dp[mask] = min(dp[mask], dfs(left) + 1);
            }
        }
        return dp[mask];
    }

    int minStickers(vector<string>& stickers, string target) {
        this->target = target;
        m = target.length();
        dp = vector<int> (1 << m, -1);          //若初始化为m + 1 会导致超时, 最终无法到达的mask(即dp[mask]恒等于m + 1)的情况dp没有更新意志为m+1会重复搜索 例如target = ab ; stickers = bc, bde, bf; mask = 10的情况会被重复搜索
        dp[0] = 0;
        this->stickers = stickers;
        int res = dfs((1 << m) - 1);
        return res > m ? -1 : res;
    }
};
// @lc code=end

