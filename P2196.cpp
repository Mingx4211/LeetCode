#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> bombs(25);
vector<int> pre(25, -1);

void print(int i){
    if(pre[i] > -1){
        print(pre[i]);
    }
    cout << i << " ";
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> bombs[i];
    }
    vector<vector<int>> links(n);
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            cin >> temp;
            if(temp) links[i].push_back(j);
        }
    }

    vector<int> max_i = bombs;
    int max_res = 0;
    int max_index;
    for(int i = 0; i < n; i++){
        if(max_i[i] >  max_res){
            max_res = max_i[i];
            max_index = i;
        }
        for(auto next : links[i]){
            if(max_i[i] + bombs[next] > max_i[next]){
                max_i[next] = max_i[i] + bombs[next];
                pre[next] = i;
            }
        }
    }

    print(max_index);
    cout << endl << max_res << endl;

    return 0;

}