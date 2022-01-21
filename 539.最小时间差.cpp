// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<algorithm>
#include "commoncppproblem539.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

// @lc code=start

bool comp(vector<int> a, vector<int> b){
        if(a[0] != b[0])
            return(a[0] < b[0]);
        else
            return(a[1] < b[1]);
    }

class Solution {
public:

    int findMinDifference(vector<string>& timePoints) {
        int c = timePoints.size();
        vector<vector<int>> times(c, vector<int>(2));
        for(int i = 0; i < c; i++){
            times[i][0] = stoi(timePoints[i].substr(0, 2));
            times[i][1] = stoi(timePoints[i].substr(3, 2));
        }
        sort(times.begin(), times.end(), comp);
        int min = 65536;
        for(int i = 1; i < times.size(); i++){
            int temp = (times[i][0] - times[i - 1][0]) * 60 + times[i][1] - times[i - 1][1];
            if(temp < min)
                min = temp;
        }
        int temp = (23 - times[times.size() - 1][0]) * 60 + 60 - times[times.size() - 1][1];
        temp += (times[0][0] - 0) * 60 + times[0][1];
        if(temp < min)
            min = temp;

        return min;
    }
};
// @lc code=end

