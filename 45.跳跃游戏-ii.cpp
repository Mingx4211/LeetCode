// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem45.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};
// @lc code=end


//BFS 低效率
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, INT_MAX);
//         dp[0] = 0;
//         queue<int> q;
//         q.push(0);
//         while(!q.empty()){
//             int cur = q.front();
//             q.pop();
//             if(cur == n - 1){
//                 return dp[n - 1];
//             }
//             for(int i = 1; i <= nums[cur]; i++){
//                 if(cur - i >= 0 && dp[cur] + 1 < dp[cur - i]){
//                     dp[cur - i] = dp[cur] + 1;
//                     q.push(cur - i);
//                 }
//                 if(cur + i < n && dp[cur] + 1 < dp[cur + i]){
//                     dp[cur + i] = dp[cur] + 1;
//                     q.push(cur + i);
//                 }
//             }
//         }
//         return dp[n - 1];

//     }
// };