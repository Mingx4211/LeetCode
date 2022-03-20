#include <bits/stdc++.h>

using namespace std;

class Solution{
private:
    int m, n;
    int height[100][100] = {};
    int memo[100][100] = {};
    int max_res = 0;
public:
    Solution(){
        cin >> m >> n;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> height[i][j];
            }
        }
    }

    int dfs(int i, int j){
        if(memo[i][j] != 0){
            return memo[i][j];
        }else{
            memo[i][j] = 1;
            if(i - 1 > -1 && height[i - 1][j] <  height[i][j]) memo[i][j] = max(memo[i][j], 1 + dfs(i - 1, j));
            if(j - 1 > -1 && height[i][j - 1] <  height[i][j]) memo[i][j] = max(memo[i][j], 1 + dfs(i, j - 1));
            if(i + 1 < m && height[i + 1][j] <  height[i][j]) memo[i][j] = max(memo[i][j], 1 + dfs(i + 1, j));
            if(j + 1 < n && height[i][j + 1] <  height[i][j]) memo[i][j] = max(memo[i][j], 1 + dfs(i, j + 1));
            max_res = max(max_res, memo[i][j]);
            return memo[i][j];
        }
    }

    int solve(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(i, j);
            }
        }
        return max_res;
    }
};

int main(){
    Solution  S;
    cout <<  S.solve() << endl;
    return 0;
}