#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1219 lang=cpp
 *
 * [1219] 黄金矿工
 */

// @lc code=start
class Solution {
public:
    int m = 0, n = 0;
    vector<vector<int>> grid, max_grid, visited;
    int res = 0, max_res = 0;

    void getOneGrid(int i, int j){
        res += grid[i][j];
        if(res > max_res) max_res = res;
        visited[i][j] = 1;
        if(res >= max_grid[i][j]){
            if(i - 1 > -1 && grid[i - 1][j] != 0 && visited[i - 1][j] == 0){
                getOneGrid(i - 1, j);
            }
            if(i + 1 < m && grid[i + 1][j] != 0 && visited[i + 1][j] == 0){
                getOneGrid(i + 1, j);
            }
            if(j - 1 > -1 && grid[i][j - 1] != 0 && visited[i][j - 1] == 0){
                getOneGrid(i, j - 1);
            }
            if(j + 1 < n && grid[i][j + 1] != 0 && visited[i][j + 1] == 0){
                getOneGrid(i, j + 1);
            }
        }
        res -= grid[i][j];
        visited[i][j] = 0;
    }

    int getMaximumGold(vector<vector<int>>& _grid) {
        grid = _grid;
        m = grid.size(), n = grid[0].size();
        max_grid = vector<vector<int>>(m, vector<int>(n, 0));
        visited = vector<vector<int>>(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0 && max_grid[i][j] == 0){
                    getOneGrid(i, j);
                }
            }
        }
        return max_res;
    }
};
// @lc code=end

