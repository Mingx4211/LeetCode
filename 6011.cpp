#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        constexpr int K = 20;
        vector<long long> dp(numLaps + 1, INT_MAX);
        vector<long long> best(K + 1, INT_MAX);

        for(int i = 1; i <= K; i++){
            for(int j = 0; j < tires.size(); j++){
                int fi = tires[j][0], ri = tires[j][1];
                best[i] = min(best[i], fi * ((long long)pow(ri,  i) - 1) / (ri - 1));
            }
        }
        dp[0] = 0;
        for(int i = 1; i <= numLaps; i++){
            for(int j = 1; j <= K && i - j > 0; j++){
                dp[i] = min(dp[i], dp[i - j] + changeTime + best[i]);
            }
        }

        return dp[numLaps] - changeTime;
    }
};