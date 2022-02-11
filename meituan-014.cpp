#include<bits/stdc++.h>

using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    vector<int> a(x + y);
    for(int i = 0; i < x + y; i++){
        cin >> a[i];
    }
    vector<int> b(a);
    sort(b.begin(), b.end());
    if(x == y){
        cout << string(x, 'A') << string(y, 'B') << endl;
    }else if(x > y){
        for(int i = 0; i < x + y; i++){
            if(a[i] < b[x]){
                cout << 'A';
            }else{
                cout << 'B';
            }
        }
    }else if(x < y){
        for(int i = 0; i < x + y; i++){
            if(a[i] >= b[y]){
                cout << 'A';
            }else{
                cout << 'B';
            }
        }
    }
    return 0;
}