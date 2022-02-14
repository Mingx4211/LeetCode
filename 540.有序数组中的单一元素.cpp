// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem540.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n / 2;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums[2 * mid] != nums[2 * mid + 1]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return nums[2 * l + 1];

    }
};
// @lc code=end

