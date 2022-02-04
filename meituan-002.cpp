#include<iostream>
#include<vector>

using namespace std;

//112 ms
int main(){
    int n;
    cin >> n;
    vector<int> w(n + 2, 0);
    for(int i = 0; i < n; i++){
        cin >> w[i + 1];
    }
    long long max = 0;
    int max_s = 1, max_e = n;
    for(int i = 1; i <= n; i++)
        max += w[i];
    
    int s = -1, e = -1;
    long long temp_sum = 0;
    int a = 0;
    while(cin >> a){
        w[a] = 0;
        if(a < max_s || a > max_e){
            cout << max << endl;
        }else{
            max = 0;
            for(int i = 1; i <= n + 1; i++){
                if(s == -1 && w[i] != 0){
                    s = i;
                    temp_sum = w[i];
                }else if(s != -1 && w[i] != 0){
                    temp_sum += w[i];
                }else if(s != -1 && w[i] == 0){
                    e = i - 1;
                    if(temp_sum > max){
                        max = temp_sum;
                        max_s = s;
                        max_e = e;
                    }
                    temp_sum = 0;
                    s = e = -1;
                }   
            }
            cout << max << endl;
        }
    }
    return 0;
}



// int main(){    O(n ^ 2) 1744ms
//     int n = 0;
//     cin >> n;
//     vector<pair<int, long long>> w(n + 2);
//     long long sum = 0;
//     int temp = 0;
//     for(int i = 1; i < n + 1; i++){
//         cin >> temp;
//         sum += temp;
//         w[i] = pair<int, long long>(temp, 0);
//     }
//     w[n + 1] = pair<int, long long>(0, sum);
//     vector<int> history;
//     history.emplace_back(n + 1);

//     int a = 0;
//     while(cin >> a){
//         history.emplace_back(a);
//         int t = a;
//         long long temp_sum = 0;
//         w[a].first = 0;
//         while(w[--t].first != 0){
//             w[a].second += w[t].first;
//         }
//         t = a;
//         while(w[++t].first != 0){
//             temp_sum += w[t].first;
//         }
//         w[t].second = temp_sum;
//         long long max = 0;
//         for(auto a : history){
//             if(w[a].second > max)
//                 max = w[a].second;
//         }
//         cout << max << endl;
//     }

//     return 0;
// }













