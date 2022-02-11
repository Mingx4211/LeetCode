#include<bits/stdc++.h>

using namespace std;

constexpr int mod = 998244353;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //DP[i][j] 表示第一个价格为i, 最贵不超过n, 购买j个的方案数
    //
    for(int i = 1; i <= n; i++){
        dp[i][1] = 1;
    }
    for(int i = 2; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int sum = 0;
            int ratio = 1;
            while(j * ratio <= n){
                sum += dp[j * ratio][i - 1];
                sum %= mod;
                ratio++;
            }
            dp[j][i] = sum;
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += dp[i][m];
        sum %= mod;
    }
    cout << sum << endl;
}