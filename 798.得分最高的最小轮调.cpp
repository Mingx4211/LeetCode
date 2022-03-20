// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem798.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=798 lang=cpp
 *
 * [798] 得分最高的最小轮调
 */

// @lc code=start
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n, 0);
        for(int i = 0; i < n; i++){
            int low = (i + 1) % n;
            int high = (i - nums[i] + 1 + n) % n;
            diff[low]++;
            diff[high]--;
            if(low >= high)
                diff[0]++;
        }
        int res = 0, max_score = 0, cur_score = 0;
        for(int i = 0; i < n; i++){
            cur_score += diff[i];
            if(cur_score > max_score){
                res = i;
                max_score = cur_score;
            }
        }
        return res;
    }
};
// @lc code=end

