// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem42.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0], rightMax[n - 1] = height[n - 1];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res += min(leftMax[i], rightMax[i]) - height[i];
        }

        return res;
    }
};
// @lc code=end

