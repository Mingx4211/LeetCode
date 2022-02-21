// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "commoncppproblem688.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=688 lang=cpp
 *
 * [688] “马”在棋盘上的概率
 */

// @lc code=start
class Solution {
public:
    //BFS 超时 ,正解DP
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> move {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
        double res = 1.0;
        queue<pair<int, int>> q;
        q.emplace(row, column);
        int step = 1;
        int crrl = 1;
        while(step <= k){
            for(int i = 0; i < crrl; i++){
                auto [x, y] = q.front();
                q.pop();
                for(auto [dx, dy] : move){
                    if(x + dx >=0 && x + dx < n && y + dy >= 0 && y + dy < n){
                       q.emplace(x + dx, y + dy);
                    }else{
                        res -= 1.0 / pow(8, step);
                    }
                }
            }
            step++;
            crrl = q.size();
        }
        return res;
    }
};
// @lc code=end

