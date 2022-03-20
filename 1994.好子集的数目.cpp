#include <bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode.cn id=1994 lang=cpp
 *
 * [1994] 好子集的数目
 */

// @lc code=start
class Solution {
public:
    //DFS 
    vector<int> nums;
    vector<vector<int>> mp = vector<vector<int>>(31);
    long long res = 0;
    long long mod = 1e9 + 7;
    long long acc = 1;
    long long temp_res = 1;
    set<int> except_nums{1, 4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28};

    int numberOfGoodSubsets(vector<int>& _nums) {
        nums = _nums;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        dfs(2);
        long long temp_1 = 1;
        int cnt_1 = mp[1].size();
        for(int i = 0; i < cnt_1; i++){
            temp_1 *= 2;
            temp_1 %= mod;
        }
        return (res * temp_1) % mod;
    }

    void dfs(int i){
        if(i == 31) return;
        dfs(i + 1);
        if(!(except_nums.count(i)) && gcd(acc, i) == 1){
            acc *= i;
            int cur_temp_res = temp_res;
            temp_res *= mp[i].size();
            temp_res %= mod;
            res += temp_res;
            res %= mod;
            dfs(i + 1);
            acc /= i;
            temp_res = cur_temp_res;
        }
    }
};
// @lc code=end

