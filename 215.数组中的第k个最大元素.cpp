// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem215.h"

using namespace std;
// @before-stub-for-debug-end

#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start

class Solution {
public:
    vector<int> nums;
    int k;

    int partition(int left, int right) {
        if (left == right)  return left;
        int rpi = left + rand() % (right - left);
        swap(nums[left], nums[rpi]);
        int pivot = nums[left];
        int l = left + 1, r = left + 1;
        while (r <= right) {
            if (nums[r] >= pivot) {
                swap(nums[l], nums[r]);
                l++;
            }
            r++;
        }
        nums[left] = nums[l - 1];
        nums[l - 1] = pivot;
        return l - 1;
    }

    int quickSelect(int left, int right) {
        int mid = partition(left, right);
        if (mid == k - 1) {
            return nums[mid];
        } else if (mid >= k) {
            return quickSelect(left, mid - 1);
        } else {
            return quickSelect(mid + 1, right);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
        int res = quickSelect(0, nums.size() - 1);
        return res;
    }
};



// class Solution {
// public:
//     vector<int> nums;
//     int k;

//     int partition(int left, int right) {
//         if (left == right)  return left;
//         int pivot = nums[left];
//         int l = left + 1, r = left + 1;
//         while (r <= right) {
//             if (nums[r] >= pivot) {
//                 int temp = nums[l];
//                 nums[l] = nums[r];
//                 nums[r] = temp;
//                 l++;
//             }
//             r++;
//         }
//         nums[left] = nums[l - 1];
//         nums[l - 1] = pivot;
//         return l - 1;
//     }

//     int quickSelect(int left, int right) {
//         int mid = partition(left, right);
//         if (mid == k - 1) {
//             return nums[mid];
//         } else if (mid >= k) {
//             return quickSelect(left, mid - 1);
//         } else {
//             return quickSelect(mid + 1, right);
//         }
//     }
    
//     int findKthLargest(vector<int>& nums, int k) {
//         this->nums = nums;
//         this->k = k;
//         int res = quickSelect(0, nums.size() - 1);
//         return res;
//     }
// };
// @lc code=end

