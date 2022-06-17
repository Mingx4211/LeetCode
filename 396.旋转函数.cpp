#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

// @lc code=start
//优化 不用求前缀和
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, n = nums.size();
        int numSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
        }
        int res = f;
        for (int i = n - 1; i > 0; i--) {
            f += numSum - n * nums[i];
            res = max(res, f);
        }
        return res;
    }
};

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int presum = 0;
        int res = 0;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            presum += nums[i];
        }

        for(int i = 0; i < n; i++){
            sum += i * nums[i];
        }
        res = sum;
        for(int i = 1; i < n; i++){
            sum -= (n - 1) * nums[n - i];
            sum += presum;
            res = max(res, sum);
            presum += nums[n - i];
            presum -= nums[n - 1 - i];
        }
        return res;
    }
};
// @lc code=end

