#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, xs, ys, xt, yt;
    cin >> n >> m >> xs >> ys >> xt >> yt;
    xs--, ys--, xt--, yt--;
    vector<vector<pair<int, int>>> cross(n, vector<pair<int, int>>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin  >> cross[i][j].first;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> cross[i][j].second;
        }
    }
    //广度优先搜索
    int time = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    q.push({xs, ys});
    int crrl = 1;
    while(!q.empty()){
        for(int i = 0; i < crrl; i++){
            auto& [x, y] = q.front();
            visited[x][y] = 1;
            if(x == xt && y == yt){
                break;
            }else{
                auto&[a, b] = cross[x][y];
                int t = time % (a + b);
                if(t < a){
                    if(x - 1 >= 0 && visited[x - 1][y] == 0){
                        q.push({x - 1, y});
                    }
                    if(x + 1 < n && visited[x + 1][y] == 0){
                        q.push({x + 1, y});
                    }
                }else{
                    if(y - 1 >= 0 && visited[x][y - 1] == 0){
                        q.push({x, y - 1});
                    }
                    if(y + 1 < m && visited[x][y + 1] == 0){
                        q.push({x, y + 1});
                    }
                }
            }
        }
        time++;
        crrl = q.size();
    }
    cout << time << endl;
    return 0;

}