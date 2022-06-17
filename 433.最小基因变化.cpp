// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem433.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */
//预处理广搜
// @lc code=start
class Solution {
public:
    bool check(string& a, string& b){
        int cnt = 0;
        for(int i = 0; i < 8; i++){
            if(a[i] != b[i])
                cnt++;
        }
        return cnt == 1;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        vector<vector<int>> edge(bank.size(), vector<int>(bank.size(), 0));
        for(int i = 0; i < bank.size(); i++){
            for(int j = 0; j < bank.size(); j++){
                if(check(bank[i], bank[j])){
                    edge[i][j] = 1;
                }
            }
        }
        vector<int> estart(bank.size());
        queue<int> q;
        for(int i = 0; i < bank.size(); i++){
            if(check(start, bank[i])){
                estart[i] = 1;
                q.push(i);
            }
        }
        vector<int> visited(bank.size());
        int step = 1;
        while(!q.empty()){
            int crrl = q.size();
            for(int i = 0; i < crrl; i++){
                int m = q.front();
                q.pop();
                visited[m] = 1;
                if(bank[m] == end){
                    return step;
                }
                for(int j = 0; j < bank.size(); j++){
                    if(edge[m][j] == 1 && visited[j] == 0){
                        q.push(j);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

