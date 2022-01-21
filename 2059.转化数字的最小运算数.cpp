#include<vector>
#include<queue>

using namespace std;

/*
 * @lc app=leetcode.cn id=2059 lang=cpp
 *
 * [2059] 转化数字的最小运算数
 */

// @lc code=start
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> vqueue;
        vector<int> visited(1001, 0);
        vqueue.push(start);
        visited[start] = 1;
        int crrl = 1, res = 0;
        while(!vqueue.empty()){
            for(int i = 0; i < crrl; i++){
                auto crr = vqueue.front();
                if(crr == goal) return res;
                vqueue.pop();
                if(crr >= 0 && crr <= 1000){
                    for(auto a : nums){
                        if(crr - a < 0 || crr - a > 1000){
                            vqueue.push(crr - a);
                        }else if(!visited[crr - a]){
                            vqueue.push(crr - a);
                            visited[crr - a] = 1;
                        }
                        if(crr + a > 1000 || crr + a < 0){
                            vqueue.push(crr + a);
                        }else if(!visited[crr + a]){
                            vqueue.push(crr + a);
                            visited[crr + a] = 1;
                        }
                        int temp = (crr ^ a);
                        if(temp < 0 || temp > 1000){
                            vqueue.push(temp);
                        }else if(!visited[temp]){
                            vqueue.push(temp);
                            visited[temp] = 1;
                        }
                    }
                }
            }
            crrl = vqueue.size();
            res += 1;
        }
        return -1;
    }
};
// @lc code=end

