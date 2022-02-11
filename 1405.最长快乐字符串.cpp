#include<bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=1405 lang=cpp
 *
 * [1405] 最长快乐字符串
 */

// @lc code=start
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        vector<pair<int, char>> mp;
        mp.emplace_back(pair<int, char>(a, 'a'));
        mp.emplace_back(pair<int, char>(b, 'b'));
        mp.emplace_back(pair<int, char>(c, 'c'));
        sort(mp.begin(), mp.end());
        if(((mp[2].first - 1) / 2) > (mp[1].first + mp[0].first)){
            mp[2].first = (mp[0].first + mp[1].first + 1) * 2;
        }
        vector<string> temp;
        while(mp[2].first > 0){
            if(mp[2].first == 1){
                temp.push_back(string(1, mp[2].second));
            }else{
                temp.push_back(string(2, mp[2].second));
            }
            mp[2].first -= 2;
        }
        int i = 0, mod = temp.size();
        while(mp[1].first > 0){
            temp[i % mod] += mp[1].second;
            mp[1].first--;
            i++;
        }
        while(mp[0].first > 0){
            temp[i % mod] += mp[0].second;
            mp[0].first--;
            i++;
        }
        for(int i = 0; i < temp.size(); i++){
            res += temp[i];
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution S;
    cout << S.longestDiverseString(2, 2, 1) << endl;
    return 0;
}