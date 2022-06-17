#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
 */

// @lc code=start
class Solution {
//    """在BFS中push进队列之前进行访问 而不是在出队列之后进行访问 有利于减少时间复杂度"""
public:
    vector<pair<int, int>> delta{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> forest;
    int m, n;
    vector<int> distance;
    vector<pair<int, pair<int, int>>> trees;;
    vector<vector<int>> visited;

    int bfs (pair<int, int> s, pair<int, int> t) {
        visited = vector<vector<int>> (m, vector<int>(n, 0));
        auto [sx, sy] = s; auto [tx, ty] = t;
        if (sx == tx && sy == ty)   return 0;
        queue<pair<int, int>> q;
        q.push(s);
        visited[sx][sy] = 1;

        int step = 0;
        while (!q.empty()) {
            step++;
            int crrl = q.size();
            for (int i = 0; i < crrl; i++) {
                auto [mx, my] = q.front();
                q.pop();
                for (auto [dx, dy] : delta) {
                    int nx = mx + dx, ny = my + dy;
                    if (nx == tx && ny == ty) return step;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        if (forest[nx][ny] > 0 && visited[nx][ny] != 1) {
                            visited[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        this->forest = forest;
        m = forest.size(), n = forest[0].size();
        trees.push_back({0, {0, 0}});
        for (int i = 0; i < forest.size(); i++) {
            for (int j = 0; j < forest[0].size(); j++) {
                if (forest[i][j] > 1) {
                    trees.push_back({forest[i][j], {i, j}});
                }
            }
        }
        sort(trees.begin(), trees.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
            return a.first < b.first;
        });
        distance = vector<int> (trees.size() - 1);
        for (int i = 0; i < distance.size(); i++) {
            distance[i] = bfs(trees[i].second, trees[i + 1].second);
            if (distance[i] == -1)  return -1;
        }
        int sum = 0;
        for (auto i : distance) {
            sum += i;
        }
        return sum;
    }
};
// @lc code=end

