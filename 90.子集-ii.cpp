// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <iostream>
#include "commoncppproblem90.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nums;
    int n;      //nums的长度
    int used[10];    // 会被默认初始化, 只有定义于 函数体 内的 内置类型 变量不会被初始化
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int> > subsetsWithDup(vector<int>& _nums) {
        sort(_nums.begin(), _nums.end());
        nums = _nums;
        n = nums.size();
        dfs(0);
        return res;
    }

    int dfs(int i){
        if(i >= n){
            for(int j = 0; j < n; j++){
                if(used[j])
                    temp.push_back(nums[j]);
            }
            res.push_back(temp);
            temp.clear();
            return 0;
        }
        if(i == 0 || nums[i] != nums[i - 1] || used[i - 1] == 1){
            used[i] = 1;
            dfs(i + 1);
        }
        used[i] = 0;
        dfs(i + 1);
        return 0;
    }


};
// @lc code=end

