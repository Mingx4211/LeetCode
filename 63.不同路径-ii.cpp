// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem63.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        if(!obstacleGrid[0][0]) dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!obstacleGrid[i][j]){
                    if(i - 1 >= 0){
                        dp[i][j] += dp[i - 1][j];
                    }
                    if(j - 1 >= 0){
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

