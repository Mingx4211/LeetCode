// @before-stub-for-debug-begin
#include <bits/stdc++.h>
#include "commoncppproblem51.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    int n;
    unordered_map<int, int> m1, m2, m3, m4;
    vector<vector<string>> res;

    void dfs(int i){
        if(i == n){
            vector<string> temp(n, string(n, '.'));
            for(int j = 0; j < n; j++){
                temp[j][m1[j]] = 'Q';
            }
            res.emplace_back(move(temp));
        }else{
            for(int j = 0; j < n; j++){
                if(m2[j] || m3[i - j] || m4[i + j])
                    continue;
                else{
                    m1[i] = j;
                    m2[j] = 1;
                    m3[i - j] = 1;
                    m4[i + j] = 1;
                    dfs(i + 1);
                    m2[j] = 0;
                    m3[i - j] = 0;
                    m4[i + j] = 0;
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        dfs(0);
        return res;
    }
};
// @lc code=end

