#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */

// @lc code=start
class Solution {
public:
    vector<int> dp;
    int maxChoosableInteger;

    int dfs(int choosable, int desired) {
        if (dp[choosable] != -1)    return dp[choosable];
        for (int i = 0; i < maxChoosableInteger; i++) {
            if (choosable & (1 << i)) {
                if (i + 1 >= desired) {
                    dp[choosable] = 1;
                    return 1;
                }

                if (dfs(choosable ^ (1 << i), desired - i - 1) == 0) {
                    dp[choosable] = 1;
                    return 1;
                }
            }
        }
        dp[choosable] = 0;
        return 0;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        dp = vector<int> (1 << maxChoosableInteger, -1);
        this->maxChoosableInteger = maxChoosableInteger;
        if (desiredTotal < maxChoosableInteger) return true;
//        if (maxChoosableInteger == 20 && desiredTotal == 152) return false;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        return dfs((1 << maxChoosableInteger) - 1, desiredTotal);
    }
};
// @lc code=end

