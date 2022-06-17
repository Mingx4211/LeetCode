#include <bits/stdc++.h>

using namespace std;

int main(){
    string temp;
    vector<int> arr;
    int e;
    while(cin >> temp){
        if(temp[temp.length() - 1] == ','){
            arr.push_back(stoi(temp.substr(0, temp.length() - 1)));
        }else{
            e = stoi(temp);
        }
    }
    int n = arr.size();
    vector<unordered_map<int, int>> dp(n);
    dp[0][arr[0]] = 1;
    dp[0][-arr[0]] = 1;
    for(int i = 0; i < n - 1; i++){
        for(auto& m: dp[i]){
            dp[i + 1][m.first + arr[i + 1]] += m.second;
            dp[i + 1][m.first - arr[i + 1]] += m.second;
        }
    }
    cout << dp[n - 1][e] << endl;
    return 0;
}