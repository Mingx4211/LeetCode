#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=1719 lang=cpp
 *
 * [1719] 重构一棵树的方案数
 */

// @lc code=start
class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> mp;
        for(int i = 0; i < pairs.size(); i++){
            mp[pairs[i][0]].emplace(pairs[i][1]);
            mp[pairs[i][1]].emplace(pairs[i][0]);
        }
        int root = -1;
        for(auto& [node, adj] : mp){
            if(adj.size() == mp.size() - 1){
                root = node;
            }
        }
        if(root == -1){
            return 0;
        }
        int res = 1;
        for(auto& [node, adj] : mp){
            if(node == root){
                continue;
            }
            int parent_node = -1;
            int parent_count = INT_MAX;
            int current_count = adj.size();
            for(auto pnode : adj){
                int psize = mp[pnode].size();
                if(psize < parent_count && psize >= current_count){
                    parent_node = pnode;
                    parent_count = psize;
                }
            }
            if(parent_node == -1){
                return 0;
            }else{
                for(auto anode : adj){
                    if(anode == parent_node){
                        continue;
                    }
                    if(mp[parent_node].count(anode) == 0){
                         return 0;
                     }
                }
            }
            if(parent_count == current_count){
                res = 2;
            }
        }
        return res;
    }
};
// @lc code=end

