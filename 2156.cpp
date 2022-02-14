#include<bits/stdc++.h>

using namespace std;

class Solution {
    //超时 //正确解法为逆序遍历 递推
public:
    string s;
    int power, modulo;
    vector<int> val;
    vector<long long> pkm;
    long long hash(int i, int k){
        long long temp = 0;
        for(int j = 0; j < k; j++){
            temp += ((val[i + j] * pkm[j]) % modulo);
            temp %= modulo;
        }
        return temp;
    }

    string subStrHash(string _s, int _power, int _modulo, int k, int hashValue) {
        s = _s;
        power = _power;
        modulo = _modulo;
        val = vector<int> (s.length(), 0);
        for(int i = 0; i < s.length(); i++){
            val[i] = s[i] - 'a' + 1;
        }
        pkm = vector<long long> (k, 0);
        pkm[0] = 1;
        long long temp;
        for(int i = 1; i < k; i++){
            temp = pkm[i - 1] * power;
            pkm[i] = temp % modulo;
        }
        for(int i = 0; i + k - 1 < s.length(); i++){
            if(hash(i, k) == hashValue){
                return s.substr(i, k);
            }
        }
        return "";
    }
};