#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string largestNumber(vector<int> &cost, int target) {
    vector<int> dp(target + 1, INT_MIN);
    dp[0] = 0;
    for (int c : cost) {
        for (int i = c; i <= target; i++) {
            dp[i] = max(dp[i], dp[i - c] + 1);
        }
    }

    if (dp[target] < 0) {
        return "0";
    }

    string ans;
    for (int i = 8, j = target; i >= 0; i--) {
        for (int c = cost[i]; j >= c && dp[j] == dp[j - c] + 1; j -= c) {
            ans += '1' + i;
        }
    }
    return ans;
}