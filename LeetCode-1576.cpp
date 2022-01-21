#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '?'){
                if(i == 0)
                    for(int j = 0; j < 26; j++){
                        if(s[1] != 'a' + j){
                            s[i] = 'a' + j;
                            break;
                        }
                    }
                else if(i == s.length() - 1)
                    for(int j = 0; j < 26; j++){
                        if(s[s.length() - 2] != 'a' + j){
                            s[i] = 'a' + j;
                            break;
                        }
                    }
                else
                    for(int j = 0; j < 26; j++){
                        if(s[i - 1] != 'a' + j && s[i + 1] != 'a' + j){
                            s[i] = 'a' + j;
                            break;
                        }
                    }
            }
        }
        return s;
    }
};

int main(){
    string str = "??yw?ipkj?";
    Solution S;
    cout << S.modifyString(str) << endl;
    return 0;
}