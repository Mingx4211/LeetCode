#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int lose[1001] = {}, win[1001] = {}, use[1001] = {};
    for(int i = 1; i <= n; i++){
        cin >> lose[i] >> win[i] >> use[i];
    }
    long long dp[1001][1001] = {};
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i - 1][j] + lose[i];
            if(j >= use[i]){
                dp[i][j] = max(dp[i - 1][j- use[i]] + win[i], dp[i][j]);
            }
        }
    }
    cout << 5 * dp[n][x] << endl;
    return 0;
}