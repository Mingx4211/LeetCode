#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start

class Solution {
public:
    vector<int> nums;
    int n;
    Solution(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        srand(time(nullptr));
    }
    
    int pick(int target) {
        int k = 1;
        int res = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                if(rand() % k == 0){
                    res = i;
                }
                k++;
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     unordered_map<int, vector<int>> mp;

//     Solution(vector<int>& nums) {
//         for(int i = 0; i < nums.size(); i++){
//             mp[nums[i]].push_back(i);
//         }
//         srand(time(NULL));
//     }
    
//     int pick(int target) {
//         return mp[target][rand() % mp[target].size()];
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

