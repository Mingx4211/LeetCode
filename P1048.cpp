#include <bits/stdc++.h>

using namespace std;

int main(){
    //一维DP 对时间倒过来遍历防止重复加入 实际就是二维DP的滚动数组优化
    int t, m;
    cin >> t >> m;
    int value[101];
    int time[101];
    int dp[1001] = {};
    for(int i = 1; i <= m; i++){
        cin >> time[i] >> value[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j = t; j >= time[i]; j--){
            dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
        }
    }
    cout << dp[t] << endl;
    return 0;
}


// int main(){
    //二维DP 标准背包问题
//     int t, m;
//     cin >> t >> m;
//     int value[101];
//     int time[101];
//     int dp[101][1001];
//     for(int i = 1; i <= m; i++){
//         cin >> time[i];
//         cin >> value[i];
//     }
//     int max_res = 0;
//     for(int i = 1; i <= m; i++){
//         for(int j = 1; j <= t; j++){
//             只用到dp[i-1]这一行的值,可以滚动数组优化,不过要倒序遍历防止重复加入
//             dp[i][j] = max((j - time[i] >= 0 ? dp[i - 1][j - time[i]] + value[i] : 0), dp[i - 1][j]);
//             max_res = max(dp[i][j], max_res);
//         }
//     }
//     cout << max_res << endl;
// }