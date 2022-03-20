#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=1601 lang=cpp
 *
 * [1601] 最多可达成的换楼请求数目
 */

// @lc code=start
class Solution {
private:
    vector<int> delta;
    vector<vector<int>> requests;
    int count = 0;
    int count_max = 0;

    void dfs(int i){
        if(i == requests.size()){
            for(int i = 0; i < delta.size(); i++){
                if(delta[i] != 0)
                    return;
            }
            count_max = max(count_max, count);
            return;
        }

        count++;
        delta[requests[i][0]] -= 1;
        delta[requests[i][1]] += 1;
        dfs(i + 1);
        count--;
        delta[requests[i][0]] += 1;
        delta[requests[i][1]] -= 1;
        dfs(i + 1);
    }



public:
    int maximumRequests(int n, vector<vector<int>>& _requests) {
        delta = vector<int> (n);
        requests = _requests;
        dfs(0);

        return count_max;
    }
};
// @lc code=end

