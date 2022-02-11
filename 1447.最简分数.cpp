#include<bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=1447 lang=cpp
 *
 * [1447] 最简分数
 */

// @lc code=start
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        unordered_map<double, int> mp;
        vector<string> res;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(mp[(double)j / i] == 1){
                    continue;
                }else{
                    mp[(double)j / i] = 1;
                    res.emplace_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

