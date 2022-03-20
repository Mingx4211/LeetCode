#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(auto s : words){
            if(s.substr(0, pref.length()) == pref){
                res ++;
            }
        }
        return res;
    }
};