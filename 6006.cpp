#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long total = 0;
        map<int, int> mp;
        int bags = beans.size();
        long long min_move = LONG_LONG_MAX;
        for(int i = 0; i < beans.size(); i++){
            total += beans[i];
            mp[beans[i]]++;
        }
        for(auto m : mp){
            auto [c, b] = m;  // c 目标均值, b目标均值对应袋子数
            long long temp = total - (long long)c * bags;
            min_move = min(temp, min_move);
            bags -= b;
        }
        return min_move;
    }
};