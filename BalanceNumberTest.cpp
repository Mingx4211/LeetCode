#include <bits/stdc++.h>

using namespace std;

int main(){
    int l, r;
    cin >> l >> r;
    int res = 0;
    for(int i = l; i <= r; i++){
        int sumx = 0, sumy = 0;
        int flag = 1;
        int temp = i;
        while(temp != 0){
            if(flag % 2 == 1){
                sumx += temp % 10;
                temp /= 10;
                flag = 0;
            }else{
                sumy += temp % 10;
                temp /= 10;
                flag = 1;
            }
        }
        if(sumx == sumy)
            res++;
    }
    cout << res << endl;
    return 0;
}