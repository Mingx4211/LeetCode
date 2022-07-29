#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        char v = 'a';
        for (auto k : key) {
            if (k == ' ')
                continue;
            else if (mp.count(k) == 0) {
                mp[k] = v;
                v++;
            }
        }

        for (auto &c : message) {
            if (c == ' ')
                continue;
            else
                c = mp[c];
        }
        return message;
    }
};