#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 *
 * [1345] 跳跃游戏 IV
 */

// @lc code=start
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int arrl = arr.size();
        vector<int> visited(arrl, 0);
        unordered_map<int, vector<int>> hash_pos;
        for(int i = 0; i < arrl; i++){
            if( i == 0 || i == arrl - 1 || arr[i - 1] != arr[i] || arr[i + 1] != arr[i])
                hash_pos[arr[i]].push_back(i);
            else
                visited[i] = 1;
        }

        queue<int> vqueue;
        vqueue.push(0);
        visited[0] = 1;
        int crrl = 1, res = 0;
        while(!vqueue.empty()){
            for(int i = 0; i < crrl; i++){
                int c = vqueue.front();
                vqueue.pop();
                if(c == arrl - 1) return res;
                if(c + 1 < arrl && !visited[c + 1]){
                    vqueue.push(c + 1);
                    visited[c + 1] = 1;
                }
                if(c - 1 >= 0 && !visited[c - 1]){
                    vqueue.push(c - 1);
                    visited[c - 1] = 1;
                }
                if(!hash_pos[arr[c]].empty()){
                    for(auto i : hash_pos[arr[c]]){
                        if(!visited[i]){
                            vqueue.push(i);
                            visited[i] = 1;
                        }
                    }
                    hash_pos.erase(arr[c]);
                }
            }
            crrl = vqueue.size();
            res += 1;
        }
        return res;
    }
};
// @lc code=end

