/*
 * @lc app=leetcode.cn id=1765 lang=cpp
 *
 * [1765] 地图中的最高点
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j])
                    q.push(pair<int, int>(i, j));
            }
        }
        int crrl = q.size();
        int a = 0, b = 0;
        while (!q.empty()) {
            for (int i = 0; i < crrl; i++) {
                pair<int, int> t = q.front();
                q.pop();
                a = t.first, b = t.second;
                if (a - 1 > -1 && isWater[a - 1][b] == 0 && height[a - 1][b] == 0) {
                    height[a - 1][b] = height[a][b] + 1;
                    q.push(pair<int, int>(a - 1, b));
                }
                if (a + 1 < m && isWater[a + 1][b] == 0 && height[a + 1][b] == 0) {
                    height[a + 1][b] = height[a][b] + 1;
                    q.push(pair<int, int>(a + 1, b));
                }
                if (b - 1 > -1 && isWater[a][b - 1] == 0 && height[a][b - 1] == 0) {
                    height[a][b - 1] = height[a][b] + 1;
                    q.push(pair<int, int>(a, b - 1));
                }
                if (b + 1 < n && isWater[a][b + 1] == 0 && height[a][b + 1] == 0) {
                    height[a][b + 1] = height[a][b] + 1;
                    q.push(pair<int, int>(a, b + 1));
                }
            }
            crrl = q.size();
        }
        return height;
    }
};
// @lc code=end

