#include <bits/stdc++.h>

using namespace std;

class Solution {
    //超时
public:
    int minimumTime(string s) {
        int sl = s.length();
        vector<int> v1(sl + 1), v2(sl + 1);
        vector<int> idx1;
        idx1.push_back(0);
        for(int i = 1; i <= sl; i++){
            if(s[i - 1] == '0'){
                v1[i] = v1[i - 1] + 1;
            }else{
                idx1.push_back(i);
                if(v1[i - 1] > 0)
                    v1[i] = v1[i - 1] - 1;
            }
        }
        idx1.push_back(sl + 1);
        for(int i = 1; i <= sl; i++){
            if(s[sl - i] == '0'){
                v2[i] = v2[i - 1] + 1;
            }else{
                if(v2[i - 1] > 0){
                    v2[i] = v2[i - 1] - 1;
                }
            }
        }
        int min_time = INT_MAX;
        for(int i = 0; i < idx1.size() - 1; i++){
            int left = idx1[i];
            if(v1[left] == 0){
                for(int j = i + 1; j < idx1.size(); j++){
                    int right = idx1[j];
                    if(v2[sl + 1 - right] == 0){
                        int temp_time = left + sl + 1 - right + 2 * (j - i - 1);
                        min_time = min(temp_time, min_time); 
                        break;
                    }
                }
            }
        }
        return min_time;

    }
};

int main(){
    string s = "010011";
    Solution S;
    cout << S.minimumTime(s) << endl;
    return 0;
}