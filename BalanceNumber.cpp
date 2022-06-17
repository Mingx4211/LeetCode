#include <bits/stdc++.h>

using namespace std;


int balanceCount(int i){
    if(i < 0) return 0;
    int dp[10][50][50] = {};
    vector<int> nums;
    while(i != 0){
        nums.push_back(i % 10);
        i /= 10;
    }
    
    dp[0][0][0] = 1;

    for(int pos = 1; pos <= nums.size(); pos++){
        for(int x = 0; x < 50; x++){
            for(int y = 0; y < 50; y++){
                if(pos % 2 == 1){
                    for(int k = 0; k <= x; k++){
                        dp[pos][x][y] += dp[pos - 1][x - k][y];
                    }
                }else{
                    for(int k = 0; k <= y; k++){
                        dp[pos][x][y] += dp[pos - 1][x][y - k];
                    }
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < 50; i++){
        res += dp[nums.size()][i][i];
    }
    return res;
}


int main(){
    int l, r;
    cin >> l >> r;
    cout << balanceCount(r) - balanceCount(l - 1) << endl;
    return 0;
}