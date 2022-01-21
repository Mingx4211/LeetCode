#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string num;
    int n;
    vector<long long> list;
    bool isAdditiveNumber(string _num) {
        num = _num;
        n = _num.size();
        return dfs(0);
    }
    bool dfs(int u){
        int m = list.size();
        if(u == n) return m >= 3; //至少包含3个数
        int max = num[u] == '0' ? u + 1 : (u + 18 > n ? n : u + 18); //处理前导0
        long long cur;
        for(int i = u; i < max; i++){ //枚举[u,n - 1]
            cur = stoll(num.substr(u, i - u + 1));
            if(m < 2 or check(list[m - 2], list[m - 1],cur)){
                list.push_back(cur);
                if(dfs(i + 1)) return true;
                list.pop_back();
            }
        }
        return false;
    }
    bool check(long long &a, long long &b, long long &c){
        return c == a + b;
    }
};