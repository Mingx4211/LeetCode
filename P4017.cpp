#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 80112002;

int n, m;
unordered_map<int, vector<int>> mp;
int cnt[50001] = {};

int dfs(int i){
    if(cnt[i] != 0){
        return cnt[i];
    }else{
        for(auto next : mp[i]){
            cnt[i] = (cnt[i] + dfs(next)) % mod;
        }
        cnt[i] = max(1, cnt[i]);
        return cnt[i];
    }
}

int main(){
    cin >> n >> m;
    int a, b;
    vector<int> eater(n + 1);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        mp[b].push_back(a);
        eater[a]++;
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(eater[i] == 0){
            sum = (sum + dfs(i)) % mod;
        }
    }
    cout << sum << endl;
    return 0;
}