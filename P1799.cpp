#include <bits/stdc++.h>

using namespace std;


int solve(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>>
    dp(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            int d = i - arr[i];
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
            if(d == j){
                dp[i][j] = max(dp[i - 1][j] + 1, dp[i - 1][j - 1]);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, dp[n][i]);
    }
    return res;
}

int main(){
//   freopen("input", "r", stdin);
    int n;
    vector<int> arr;
    cin >> n;
    arr = vector<int>(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cout << solve(arr) << endl;
    return 0;
}