#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int mod = 1e9 + 7;

const int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

class Solution {
  public:
    //记忆化搜索
    vector<vector<int>> grid;
    vector<vector<ll>> count;
    int m, n;

    ll dfs(int x, int y) {
        if (count[x][y] != -1) {
            return count[x][y];
        }

        ll c = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] > grid[x][y]) {
                c = (c + dfs(nx, ny)) % mod;
            }
        }
        count[x][y] = c;
        return c;
    }

    int countPaths(vector<vector<int>> &grid) {
        this->grid = grid;
        m = grid.size(), n = grid[0].size();
        count = vector<vector<ll>>(m, vector<ll>(n, -1));
        ll res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = (res + dfs(i, j)) % mod;
            }
        }
        return res;
    }
};