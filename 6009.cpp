#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cs(26), ct(26);
        for(auto c : s){
            cs[c - 'a']++;
        }
        for(auto c : t){
            ct[c - 'a']++;
        }
        int res = 0;
        for(int i = 0; i < 26; i++){
            res += abs(cs[i] - ct[i]);
        }
        return res;
    }
};