#include <bits/stdc++.h>

using namespace std;

int main(){
    int r = 0;
    cin >> r;
    vector<vector<int>> pyra(r + 1);
    for(int i = 1; i <= r; i++){
        for(int j = 0; j < i; j++){
            int temp;
            cin >> temp;
            pyra[i].push_back(temp);
        }
    }
    vector<vector<int>> dp = pyra;
    for(int i = 1; i < r; i++){
        for(int j = 0; j < i; j++){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + pyra[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + pyra[i + 1][j + 1]);
        }
    }
    int res = 0;
    for(auto a : dp[r]){
        res = max(res, a);
    }
    cout << res << endl;
    return 0;
}