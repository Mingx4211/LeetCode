#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input", "r", stdin);
    int n, m;
    cin >> n >> m;
    int xh, yh;
    cin >>  xh >> yh;
    vector<pair<int, int>> move = {{0, 0}, {-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}, {1, 2}, {2, 1}, {1, -2}, {2, -1}};
    vector<vector<long long>> dp(n + 1,vector<long long>(m+ 1));
    dp[0][0] = 1;
    for(auto [dx, dy] : move){
        if(xh + dx >= 0 && xh + dx <= n && yh + dy >= 0 && yh + dy <= m){
            dp[xh + dx][yh + dy] = -1;
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(dp[i][j] != -1){
                if(i + 1 <= n && dp[i + 1][j] != -1){
                    dp[i + 1][j] += dp[i][j];
                }
                if(j + 1 <= m && dp[i][j + 1] != -1){
                    dp[i][j + 1] += dp[i][j];
                }
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}