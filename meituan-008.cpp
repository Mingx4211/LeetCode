#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    unordered_map<int, vector<int>> mp;
    int a, b;
    while(cin >> a >> b){
        mp[a].emplace_back(b);
        mp[b].emplace_back(a);
    }
    vector<int> vix(n + 1, 0), viy(n + 1, 0);
    queue<int> qx, qy;
    qx.push(x), qy.push(y);
    vix[x] = 1;
    int depth = 0, max_depth = 0;
    while(!qx.empty()){
        int xl = qx.size(), yl = qy.size();
        for(int i = 0; i < xl; i++){
            int tempx = qx.front();
            qx.pop();
            if(viy[tempx] == 1){
                max_depth =depth;
            }
            for(auto a : mp[tempx]){
                if(vix[a] == 0){
                    vix[a] = 1;
                    qx.push(a);
                }
            }
        }
        for(int i = 0; i < yl; i++){
            int tempy = qy.front();
            qy.pop();
            viy[tempy] = 1;
            for(auto a : mp[tempy]){
                if(viy[a] == 0 && vix[a] == 0){
                    qy.push(a);
                }
            }
        }
        depth++;
    }
    cout << max_depth << endl;
    return 0;
}