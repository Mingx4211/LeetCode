#include<bits/stdc++.h>

using namespace std;

int main(){
    int M, N, Q;
    cin >> M >> N >> Q;
    vector<int> shelf(N + 1, 0); //shelf[i] == 1 表示该行上锁
    vector<int> book(M + 1, 0); //book[i] == -1表示该书在小团手上, == k in (1 - N) 表示在书架第K行
    int op, x, y;
    while(cin >> op){
        if(op == 1){
            cin >> x >> y;
            if(book[x] != -1 && shelf[book[x]] == 0 && shelf[y] == 0){
                book[x] = y;
            }
        }else if(op == 2){
            cin >> y;
            shelf[y] = 1;
        }else if(op == 3){
            cin >> y;
            shelf[y] = 0;
        }else if(op == 4){
            cin >> x;
            if(book[x] > 0 &&  shelf[book[x]] == 0){
                cout << book[x] << endl;
                book[x] = -1;
            }else{
                cout << -1 << endl;
            }
        }else if(op == 5){
            cin >> x;
            if(book[x] == -1){
                book[x] = 0;
            }
        }
    }
    return 0;
}