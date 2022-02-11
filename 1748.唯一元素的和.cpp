#include<bits/stdc++.h>

using namespace std;

/*
 * @lc app=leetcode.cn id=1748 lang=cpp
 *
 * [1748] 唯一元素的和
 */

// @lc code=start
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0, i = 0;
        unordered_map<int, int> map;
        for(int a = 0; a < nums.size(); a++){
            i = nums[a];
            if(!map[i]){
                sum += i;
                map[i] = 1;
            }else if(map[i] == 1){
                sum -= i;
                map[i]++;
            }
        }
        return sum;
    }
};
// @lc code=end

