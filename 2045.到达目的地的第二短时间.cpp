#include<vector>
#include<unordered_map>
#include<queue>
#include<iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=2045 lang=cpp
 *
 * [2045] 到达目的地的第二短时间
 */

// @lc code=start
class Solution {
public:
    int time, change;
    int secondMinimum(int n, vector<vector<int>>& edges, int _time, int _change) {
        time = _time;
        change = _change;

        
        vector<vector<int>> e(n + 1);
        vector<int> visited(n + 1, 0);
        
        for(auto a : edges){
            e[a[0]].push_back(a[1]);
            e[a[1]].push_back(a[0]);
        }
        
        queue<int> q;
        q.push(1);

        int min_len = 0;

        int crrl = 1, len = 0;

        while(!q.empty()){
            vector<int> pushed(n + 1, 0);
            for(int i = 0; i < crrl; i++){
                int crr_node = q.front();
                visited[crr_node] += 1;
                q.pop();
                for(auto a : e[crr_node]){
                    if(visited[a] < 2 && !pushed[a]){
                        q.push(a);
                        pushed[a] = 1;
                    }
                    if(a == n){
                        if(min_len && len + 1 > min_len)
                            return get_time(len + 1);
                        else if(!min_len)
                            min_len = len + 1;
                    }
                }
            }
            crrl = q.size();
            len++;
        }
        return 0;
    }

    int get_time(int len){
        int res = 0;
        for(int i = 0; i < len; i++){
            if((res / change) % 2 == 0)
                res += time;
            else{
                res += (change - (res % change));
                res += time;
            }
        }
        return res;
    }

};

// int main(){
//     Solution s;
//     vector<vector<int>> edges{{1,2},{1,3},{1,4},{3,4},{4,5}};
    
//     int n = 5, time = 3, change = 5;

//     int res = s.secondMinimum(n, edges, time, change);
//     cout << res << endl;
//     return 0;
// }


// @lc code=end

