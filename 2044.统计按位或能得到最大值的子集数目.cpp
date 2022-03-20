#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 *
 * [2044] 统计按位或能得到最大值的子集数目
 */

// @lc code=start
class Solution {
private:
    vector<int> nums;
    int n;
    int cur_res;
    int max_res;
    int count;
public:
    void dfs(int i){
        if(i == n){
            if(cur_res > max_res){
                max_res = cur_res;
                count = 1;
            }else if(cur_res == max_res){
                count++;
            }
            return;
        }
        dfs(i + 1);
        int temp = cur_res;
        cur_res |= nums[i];
        dfs(i + 1);
        cur_res = temp;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        cur_res = max_res = count = 0;
        dfs(0);
        return count;
    }
};
// @lc code=end

