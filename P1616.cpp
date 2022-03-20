#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input", "r", stdin);
    int t, m;
    cin >> t >> m;
    int value[10001], time[10001];
    long long dp[10000001];
    for(int i = 1; i <= m; i++){
        cin >> time[i] >> value[i];
    }
    long long res = 0;
    for(int i = 0; i <= t; i++){
        for(int j = 1; j <= m; j++){
            if(i + time[j] <=  t){
                dp[i +  time[j]] = max(dp[i] + value[j], dp[i + time[j]]);
                res = max(res, dp[i + time[j]]);
            }
        }
    }
    cout << res << endl;
    return 0;
}