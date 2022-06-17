#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
    int dp[15][15];
    int num[15], len;


    int dfs(int pos, int pre, int limit, int st) {
        if (pos < 1) return 1;
        if (!limit && !st && dp[pos][pre] != -1)    return dp[pos][pre];
        int res = 0;
        int lim = limit ? num[pos] : 9;
        for (int i = 0; i <= lim; i++) {
            if (abs(pre - i) < 2)   continue;
            if (st && i == 0) {
                res += dfs(pos - 1, -2, 0, 1);
            }else {
                res += dfs(pos - 1, i, limit && i == lim, 0);
            }
        }
        if (!limit && !st)  dp[pos][pre] = res;
        return res;
    }

    int solve(int x){
        memset(dp, -1, sizeof(dp));
        len = 0;
        while (x != 0) {
            num[++len] = x % 10;
            x /= 10;
        }
        int res = dfs(len, -2, 1, 1);
        return res;
    }
};


int main() {
    int l, r;
    cin >> l >> r;
    Solution s;
    cout << s.solve(r) - s.solve(l - 1) << endl;
    return 0;
}






//Version 1
// #include<bits/stdc++.h>

// using namespace std;

// class Solution{
// public:
//     int dp[15][15] = {};
//     int num[15] = {};

//     void init(){
//         for(int i = 0; i < 10; i++)
//             dp[1][i] = 1;
//         for(int i = 2; i <= 10; i ++){
//             for(int j = 0; j < 10; j++){
//                 for(int k = 0; k < 10; k++){
//                     if(abs(j - k) > 1){
//                         dp[i][j] += dp[i - 1][k];
//                     }
//                 }
//             }
//         }
//     }

//     int work(int x){
//         int a[15];
//         int len = 0;
//         while (x != 0) {
//             a[++len] = x % 10;
//             x /= 10;
//         }
//         int ans = 1;
//         for (int i = 1; i < len; i++) {
//             for (int j = 1; j < 10; j++)
//                 ans += dp[i][j];
//         }

//         for(int i = 1; i < a[len]; i++){
//             ans += dp[len][i];
//         }

//         for(int i = len - 1; i > 0; i--){
//             for(int j = 0; j < a[i]; j++){
//                 if (abs(j - a[i + 1]) > 1) ans += dp[i][j];
//             }
//             if (abs(a[i] - a[i + 1]) <= 1) break;
//         }
//         return ans;
//     }
// };

// int main(){
//     int a, b;
//     cin >> a >> b;
//     Solution s;
//     s.init();
//     cout << s.work(b + 1) - s.work(a) << endl;
//     return 0;
// }