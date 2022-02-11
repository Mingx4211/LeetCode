#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int main(){
    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    vector<pair<int, int>> mp = {{a, e}, {b, f}, {c, g}};
    sort(mp.begin(), mp.end(), cmp);
    int res;
    for(int i = 0; i < 3; i++){
        d -= min(d, mp[i].first);
        res += min(d, mp[i].first) * mp[i].second;
    }
    return res;
}