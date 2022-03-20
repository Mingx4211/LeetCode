// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem329.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> memo;
    int m, n;
    int res = 0;
public:
    void dfs(int i, int j){
        int max_ij = 1;
        if(i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]){
            if(memo[i - 1][j] == 0)
                dfs(i - 1, j);
            max_ij = max(1 + memo[i - 1][j], max_ij);
        }
        if(i + 1 < m && matrix[i + 1][j] > matrix[i][j]){
            if(memo[i + 1][j] == 0)
                dfs(i + 1, j);
            max_ij = max(max_ij, 1 + memo[i + 1][j]);
        }
        if(j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]){
            if(memo[i][j - 1] == 0)
                dfs(i, j - 1);
            max_ij = max(max_ij, 1 + memo[i][j - 1]);
        }
        if(j + 1 < n && matrix[i][j + 1] > matrix[i][j]){
            if(memo[i][j + 1] == 0)
                dfs(i, j + 1);
            max_ij = max(max_ij, 1 + memo[i][j + 1]);
        }
        memo[i][j] = max_ij;
        res = max(res, max_ij);
    }

    int longestIncreasingPath(vector<vector<int>>& _matrix) {
        matrix = _matrix;
        m = matrix.size(), n = matrix[0].size();
        memo = vector<vector<int>>(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(i, j);
            }
        }
        return res;
    }
};
// @lc code=end

