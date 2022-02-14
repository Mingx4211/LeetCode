// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem11.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_vol = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            int min_h = min(height[i], height[j]);
            max_vol = max(max_vol, min_h * (j - i));
            if(min_h == height[i]){
                i++;
            }else{
                j--;
            }
        }
        return max_vol;
    }
};
// @lc code=end

