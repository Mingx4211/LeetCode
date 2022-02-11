#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, max_l = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'E'){
            l++;
            max_l = max(l, max_l);
        }else if(s[i] == 'F'){
            if(l > 0){
                l--;
            }
        }
    }
    cout << max_l << endl;
    return 0;
}