#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]] += 1;
        }
        for(int i = 0; i < 26; i++){
            char cur_char = 'z' - i;
            int rep = 0;
            while(mp[cur_char] > 0 && rep < repeatLimit){
                res += cur_char;
                mp[cur_char]--;
                rep++;
                if(rep == repeatLimit && mp[cur_char] > 0){
                    for(int j = i + 1; j < 26; j++){
                        char next_char = 'z' - j;
                        if(mp[next_char] > 0){
                            res += next_char;
                            mp[next_char]--;
                            rep = 0;
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};


int main(){
    Solution S;
    string s("dfjlajlkfaafjklsafdsjl");
    cout << S.repeatLimitedString(s, 2) << endl;
    return 0;
}


//超时
// class Solution {
// public:
//     string repeatLimitedString(string s, int repeatLimit) {
//         string res;
//         unordered_map<int, int> mp;
//         for(int i = 0; i < s.length(); i++){
//             mp['z' - s[i]] += 1;
//         }
//         for(int i = 0; i < 26; i++){
//             res += string(mp[i], (char)('z' - i));
//         }
//         int rep = 1;
//         int end = res.length();
//         for(int i = 1; i < res.length(); i++){
//             if(res[i] == res[i - 1]){
//                 rep++;
//             }else{
//                 rep = 1;
//             }
//             if(rep > repeatLimit){
//                 int j;
//                 for(j = i + 1; j < res.length(); j++){
//                     if(res[j] != res[i]){
//                         res[i] = res[j];
//                         res[j] = res[i - 1];
//                         break;
//                     }
//                 }
//                 if(j == res.length()){
//                     end = i;
//                     break;
//                 }else{
//                     rep = 1;
//                 }
//             }
//         }
//         return res.substr(0, end);
//     }
// };