#include<vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=2029 lang=cpp
 *
 * [2029] 石子游戏 IX
 */

// @lc code=start
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        for(auto i = stones.begin(); i != stones.end(); i++)
            *i %= 3;
        
    }
};
// @lc code=end

