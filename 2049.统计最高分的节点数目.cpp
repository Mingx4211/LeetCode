#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 *
 * [2049] 统计最高分的节点数目
 */

// @lc code=start
class Solution {
private:
    vector<int> size;
    vector<vector<int>> tree;
public:
    int dfs(int i){
        if(tree[i].size() == 0){
            size[i] = 1;
            return 1;
        }
        int sz = 1;
        for(auto node : tree[i]){
            sz += dfs(node);
        }
        size[i] = sz;
        return sz;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        size = vector<int>(n);
        tree = vector<vector<int>>(n);
        for(int i = 1; i < n; i++){
            tree[parents[i]].push_back(i);
        }
        dfs(0);
        long long max_product = 0, count = 0;
        for(int i = 0; i < n; i++){
            long long product = max(n - size[i], 1);
            for(auto child : tree[i]){
                product *= size[child];
            }
            if(product > max_product){
                max_product = product;
                count = 1;
            }else if(product == max_product){
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

