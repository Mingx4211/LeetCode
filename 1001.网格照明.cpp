// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include "commoncppproblem1001.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
 */

// @lc code=start
class Solution {
public:
    int n;
    unordered_set<long long> sources;
    unordered_map<int, int> mp1, mp2, mp3, mp4;
    vector<pair<int, int>> m1 = {{0, 0}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}, {1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    
    inline void turn_on(int i, int j){
        sources.insert((long long)i * n + j);
        mp1[i] += 1;
        mp2[j] += 1;
        mp3[i - j] += 1;
        mp4[i + j] += 1;
    }

    inline void turn_off(int i, int j){
        sources.erase((long long)i * n + j);
        mp1[i] -= 1;
        mp2[j] -= 1;
        mp3[i - j] -= 1;
        mp4[i + j] -= 1;
    }

    vector<int> gridIllumination(int _n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        n = _n;
        for(int i = 0; i < lamps.size(); i++){
            auto &a = lamps[i];
            if(!sources.count((long long)a[0] * n + a[1]))
                turn_on(a[0], a[1]);
        }
        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++){
            int x = queries[i][0], y = queries[i][1];
            if(mp1[x] + mp2[y] + mp3[x - y] + mp4[x + y] > 0){
                ans[i] = 1;
            }
            for(auto& [dx, dy] : m1){
                if(min(x + dx, y + dy) > -1 && max(x + dx, y + dy) < n && sources.count((long long)(x + dx) * n + y + dy)){
                    turn_off(x + dx, y + dy);
                }
            }
        }
        return ans;
    }
};
// @lc code=end







//每次插入 / 删除维护更新数组 超时 
// class Solution {
// public:
//     vector<vector<int>> sources, brightness;
//     vector<pair<int, int>> m1 = {{-1, 1}, {-1, -1}, {1, 1}, {1, -1}, {1, 0}, {0, 1}, {0, -1}, {-1, 0}};
//     void turn_on(int i, int j){
//         sources[i][j] = 1;
//         brightness[i][j] += 1;
//         int x = 0, y = 0;
//         for(auto& [dx, dy] : m1){
//             x = i + dx, y = j + dy;
//             while(min(x, y) > -1 && max(x, y) < sources.size()){
//                 brightness[x][y] += 1;
//                 x += dx;
//                 y += dy;
//             }
//         }
//     }

//     void turn_off(int i, int j){
//         sources[i][j] = 0;
//         brightness[i][j] -= 1;
//         int x = 0, y = 0;
//         for(auto& [dx, dy] : m1){
//             x = i + dx, y = j + dy;
//             while(min(x, y) > -1 && max(x, y) < sources.size()){
//                 brightness[x][y] -= 1;
//                 x += dx;
//                 y += dy;
//             }
//         }
//     }

//     vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
//         sources = vector<vector<int>> (n, vector<int>(n,0));
//         brightness = vector<vector<int>> (n, vector<int>(n,0));
//         for(auto a : lamps){
//             if(sources[a[0]][a[1]] == 0)
//                 turn_on(a[0], a[1]);
//         }
//         vector<int> ans(queries.size());
//         for(int i = 0; i < queries.size(); i++){
//             int x = queries[i][0], y = queries[i][1];
//             ans[i] = (brightness[x][y] > 0 ? 1 : 0);
//             if(sources[x][y] == 1){
//                 turn_off(x, y);
//             }
//             for(auto& [dx, dy] : m1){
//                 if(min(x + dx, y + dy) > -1 && max(x + dx, y + dy) < n && sources[x + dx][y + dy] == 1){
//                     turn_off(x + dx, y + dy);
//                 }
//             }
//         }
//         return ans;
//     }
// };