#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=1675 lang=cpp
 *
 * [1675] 数组的最小偏移量
 */

// @lc code=start
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int max_odd = 0;
        for(auto &c : nums){
            while(c % 2 == 0){
                c /= 2;
            }
            max_odd = max(max_odd, c);
        }
        
    }
};
// @lc code=end

