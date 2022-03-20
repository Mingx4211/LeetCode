#include <bits/stdc++.h>

using namespace std;

int main(){
    int V, G, N;
    cin >> V >> G >> N;
    int items[501][3];
    int dp[501][501];
    for(int i = 0; i < N; i++){
        cin >> items[i][0] >> items[i][1] >> items[i][2];
    }
    for(int i = 0; i < N; i++){
        for(int j = items[i][1]; j <= V; j++){
            for(int k = items[i][2]; k <= G; k++){
                dp[j][k] = max(dp[j][k], dp[j - items[i][1]][k - items[i][2]]);
            }
        }
    }
    cout << dp[V][G] << endl;
    return 0;
}















// class Solution{
    //dfs 超时
// private:
//     int V, G, N;
//     int items[501][3];
//     int max_res = 0;
//     int cur_res = 0;
//     int vcur = 0, gcur = 0;
// public:
//     Solution(){
//         cin >> V >> G;
//         cin >> N;
//         for(int i = 0; i < N; i++){
//             cin >> items[i][0] >> items[i][1] >> items[i][2];
//         }
//     }

//     void dfs(int i){
//         if(i == N) return;
//         dfs(i + 1);
//         if(vcur + items[i][1] <= V && gcur + items[i][2] <= G){
//             cur_res += items[i][0];
//             vcur += items[i][1], gcur += items[i][2];
//             max_res = max(cur_res, max_res);
//             dfs(i + 1);
//             vcur -= items[i][1], gcur -= items[i][2];
//             cur_res -= items[i][0];
//         }
//     }

//     int solve(){
//         dfs(0);
//         return max_res;
//     }
// };

// int main(){
//     Solution S;
//     cout << S.solve() << endl;
//     return 0;
// }