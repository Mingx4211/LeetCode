// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem1020.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> move{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1){
                q.push({i, 0});
                grid[i][0] = 0;
            }
            if(grid[i][n - 1] == 1){
                q.push({i, n - 1});
                grid[i][n - 1] = 0;
            }
        }
        for(int i = 1; i < n - 1; i++){
            if(grid[0][i] == 1){
                q.push({0, i});
                grid[0][i] = 0;
            }
            if(grid[m - 1][i] == 1){
                q.push({m - 1, i});
                grid[m - 1][i] = 0;
            }
        }
        while(!q.empty()){
            auto& [x, y] = q.front();
            for(auto& [dx, dy] : move){
                if(x + dx > -1 && x + dx < m && y + dy > -1 && y + dy < n && grid[x + dx][y + dy] == 1){
                    q.push({x + dx, y + dy});
                    grid[x + dx][y + dy] = 0;
                }
            }
            q.pop();
        }
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                    res++;
            }
        }

        return res;
    }
};
// @lc code=end

