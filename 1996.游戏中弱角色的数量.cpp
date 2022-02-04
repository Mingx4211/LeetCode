#include<vector>
#include<algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=1996 lang=cpp
 *
 * [1996] 游戏中弱角色的数量
 */

// @lc code=start
bool cmp(const vector<int> &a, const vector<int> &b){
        return a[0] == b[0] ? (a[1] > b[1]) : (b[0] > a[0]);
    }

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(begin(properties), end(properties), [](const vector<int> & a, const vector<int> & b) {
            return a[0] == b[0] ? (a[1] > b[1]) : (a[0] < b[0]);
        });
        int max = 0, res = 0;
        for(int i = properties.size() - 1; i >= 0; i--){
            if(max > properties[i][1]){
                res++;
            }

            max = (max > properties[i][1] ? max : properties[i][1]);
        }
        return res;
    }

};
// @lc code=end

