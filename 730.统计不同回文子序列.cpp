typedef long long ll;

class Solution {
public:
    ll mod = 1e9 + 7;
    ll dp[4][1005][1005] = {};
    ll countPalindromicSubsequences(string s) {
        ll sl = s.length();
        for (ll i = 0; i < sl; i++) {
            dp[s[i] - 'a'][i][i] = 1;
        }

        for (ll i = 0; i < sl; i++) {
            for (ll j = 1; i - j >= 0; j++) {
                ll l = i - j, r = i;
                for (ll c = 0; c < 4; c++) {
                    if (s[l] - 'a' == c && s[r] - 'a' == c) {
                        for (ll k = 0; k < 4; k++) {
                            dp[c][l][r] += dp[k][l + 1][r - 1];
                            dp[c][l][r] %= mod;
                        }
                        dp[c][l][r] += 2;
                    } else if (s[l] - 'a' == c && s[r] - 'a' != c) {
                        dp[c][l][r] = dp[c][l][r - 1];
                    } else if (s[l] - 'a' != c && s[r] - 'a' == c) {
                        dp[c][l][r] = dp[c][l + 1][r];
                    } else {
                        dp[c][l][r] = dp[c][l + 1][r - 1];
                    }
                }
            }
        }

        ll res = 0;
        for (int c = 0; c < 4; c++) {
            res += dp[c][0][sl - 1];
        }
        return res % mod;
    }
};