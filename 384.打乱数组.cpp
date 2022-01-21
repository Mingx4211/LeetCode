// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem384.h"
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& _nums) {
        nums = _nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> temp;
        temp = nums;
        for(int i = 0; i < temp.size(); i++){
            int j = i + (rand() % (temp.size() - i));
            swap(temp[i], temp[j]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

