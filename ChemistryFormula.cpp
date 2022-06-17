#include <bits/stdc++.h>

using namespace std;

typedef map<string, int> Map;

int main(){
    //栈模拟题
    string s;
    cin >> s;
    stack<Map> st;
    st.push(Map());
    for(int i = 0; i < s.length();){
        if(isupper(s[i])){
            string el = "";
            el += s[i];
            i++;
            while(islower(s[i])){
                el += s[i];
                i++;
            }
            int cnt = 0;
            if(isdigit(s[i])){
                while(isdigit(s[i])){
                    cnt = cnt * 10 + s[i] - '0';
                    i++;
                }
            }else{
                cnt = 1;
            }
            st.top()[el] += cnt;
        }else if(s[i] == '(' || s[i] ==  '['){
            st.push(Map());
            i++;
        }else if(s[i] == ')' || s[i] == ']'){
            Map temp = st.top();
            st.pop();
            i++;
            int cnt = 0;
            if(isdigit(s[i])){
                while(isdigit(s[i])){
                    cnt = cnt * 10 + s[i] - '0';
                    i++;
                }
            }else{
                cnt = 1;
            }
            for(auto [el, c] : temp){
                st.top()[el] += c * cnt;
            }
        }
    }
    for(auto [el, cnt] : st.top()){
        cout << el << cnt;
    }
    return 0;
}