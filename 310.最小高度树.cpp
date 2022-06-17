// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "commoncppproblem310.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for(auto& e : edges){
            degree[e[0]] += 1;
            degree[e[1]] += 1;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int reminder = n;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        while(reminder > 2){
            int crrl = q.size();
            for(int i = 0; i < crrl; i++){
                reminder--;
                int node = q.front();
                q.pop();
                degree[node]--;
                for(auto next : adj[node]){
                    if(--degree[next] == 1){
                        q.push(next);
                    }
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end

