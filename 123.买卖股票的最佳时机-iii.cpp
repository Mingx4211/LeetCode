// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem123.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> max_left(n), max_right(n);

        int min_l = prices[0], max_profit = 0;
        for(int i = 1; i < n; i++){
            max_left[i] = max(max_left[i - 1], prices[i] - min_l);
            min_l = min(min_l, prices[i]);
        }
        int max_r = prices[n - 1]; max_profit = 0;
        for(int i = n - 2; i > -1; i--){
            max_right[i] = max(max_right[i + 1], max_r - prices[i]);
            max_r = max(max_r, prices[i]);
        }
        int res = 0;
        for(int i = 0; i < n - 1; i++){
            res = max(res, max_left[i] + max_right[i + 1]);
        }

        return max(res, max_left[n - 1]);
    }
};
// @lc code=end

