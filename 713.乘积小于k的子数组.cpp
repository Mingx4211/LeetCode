// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem713.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

// @lc code=start
// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         int res = 0;
//         int l = 0, r = 0;
//         int mulres = 1;
//         while(l < nums.size()){
//             while(r < nums.size() && mulres * nums[r] < k){
//                 mulres *= nums[r];
//                 r++;
//             }
//             res += r - l;
//             if(mulres > 1){
//                 mulres /= nums[l];
//             }
//             l++;
//             if(l > r){
//                 r++;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int mulres = 1;
        int r = 0;
        for(int l = 0; l < nums.size(); l++){
            r = max(r, l);
            while(r < nums.size() && mulres * nums[r] < k){
                mulres *= nums[r];
                r++;
            }
            res += r - l;
            mulres = max(mulres / nums[l], 1);
        }
        return res;
    }
};

// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& nums, int k) {
//         if(k <= 1) return 0;
//         int res = 0;
//         int mulres = 1;
//         int r = 0;
//         for(int l = 0; l < nums.size(); l++){
//             while(r < nums.size() && mulres < k){
//                 mulres *= nums[r];
//                 r++;
//             }
//             res += mulres >= k ? r - l - 1 : r - l;
//             mulres /= nums[l];
//         }
//         return res;
//     }
// };
// @lc code=end

