#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> btree;
    string temp;
    while(cin >> temp){
        if(temp.length() < 3){
            btree.push_back(temp[0] - '0');
        }else if(temp == "null,"){
            btree.push_back(-1);
        }
    }

    int n = btree.size();
    queue<int> q;
    q.push(0);
    int res = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(2 * node + 1 < n){
            if(btree[2 * node + 1] >= btree[node]){
                res++;
            }else{
                btree[2 * node + 1] = btree[node];
            }
            q.push(2 * node + 1);
        }
        if(2 * node + 2 < n){
            if(btree[2 * node + 2] >= btree[node]){
                res++;
            }else{
                btree[2 * node + 2] = btree[node];
            }
            q.push(2 * node + 2);
        }
    }

    cout << res << endl;
    return 0;
}