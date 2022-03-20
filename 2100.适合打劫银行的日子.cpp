#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */

// @lc code=start
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> vl(n), vr(n);
        int count = 0;
        for(int i = 1; i < n; i++){
            if(security[i] <= security[i - 1])
                count++;
            else
                count = 0;
            vl[i] = count;
        }
        count = 0;
        for(int i = n - 2; i >= 0; i--){
            if(security[i] <= security[i + 1])
                count++;
            else
                count = 0;
            vr[i] = count;
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(vl[i] >= time && vr[i] >= time)
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

