#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=2039 lang=cpp
 *
 * [2039] 网络空闲的时刻
 */

// @lc code=start
class Solution {
private:
vector<vector<int>> edges;
vector<int> patience;
int n;
unordered_map<int, vector<int>> mp;
vector<int> height;

public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        n = patience.size();
        this->edges = edges;
        this->patience = patience;
        this->height = vector<int>(n, -1);
        for(auto e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(0);
        int h = 0, crrl = 1;
        while(!q.empty()){
            for(int i = 0; i < crrl; i++){
                int c = q.front();
                q.pop();
                if(height[c] == -1){
                    height[c] = h;
                    for(auto next : mp[c]){
                        if(height[next] == -1){
                            q.push(next);
                        }
                    }
                }
            }
            h++;
            crrl = q.size();
        }
        int max_res = 0;
        for(int i = 1; i < n; i++){
            int t = patience[i] * ((2 * height[i] - 1) / patience[i]) + 2 * height[i] + 1;
            max_res = max(max_res, t);
        }
        return max_res;
    }
};
// @lc code=end

