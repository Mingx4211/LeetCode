#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

class Solution {
  public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long known_count[1005];
        known_count[1] = 1;
        for (int i = 2; i <= n; i++) {
            long long delta = 0;
            if (i - delay >= 1) {
                delta += known_count[i - delay];
            }
            if (i - forget >= 1) {
                delta -= known_count[i - forget];
            }
            known_count[i] = (known_count[i - 1] + delta) % mod;
        }
        int res = known_count[n] - (n - forget >= 1 ? known_count[n - forget] : 0);
        if (res < 0)
            return res % mod + mod;
        else
            return res % mod;
    }
};