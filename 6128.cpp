#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string bestHand(vector<int> &ranks, vector<char> &suits) {
        unordered_map<int, int> mpr;
        unordered_map<char, int> mps;
        for (int i = 0; i < 5; i++) {
            mpr[ranks[i]]++;
            mps[suits[i]]++;
        }
        if (mps.size() == 1) {
            return "Flush";
        }
        int cnt_max = 0;
        for (auto [r, c] : mpr) {
            cnt_max = max(cnt_max, c);
        }
        if (cnt_max >= 3) {
            return "Three of a Kind";
        } else if (cnt_max == 2) {
            return "Pair";
        } else {
            return "High Card";
        }
    }
};