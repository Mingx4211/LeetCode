#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1<<n);
        for(int i = 0; i < n; i++){
            for(int a = (1<<i) - 1, b = 1<<(i); a >= 0; a--, b++){
                res[b] = res[a] + (1<<i);
            } 
        }
        return res;
    }
};