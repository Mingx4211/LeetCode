#include<bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<int, int> mr, mc;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] < matrix[i][mr[i]]){
                    mr[i] =j;
                }
                if(matrix[i][j] > matrix[mc[j]][j]){
                    mc[j] = i;
                }
            }
        }
        vector<int> res;
        for(int i = 0; i < m; i++){
            if(mc[mr[i]] == i){
                res.push_back(matrix[i][mr[i]]);
            }
        }
        return res;
    }
};
// @lc code=end

