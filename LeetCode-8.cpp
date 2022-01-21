#include<iostream>
#include<vector>
#include<string>

using namespace std;

int myAtoi(string s){
    int index = 0, neg = 1;
    while(index < s.size() && s[index] == ' '){
        index++;
    }

    if(index >= s.size()) return 0; //只有空字符，直接返回0

    if(s[index] == '+' || s[index] == '-'){
        neg = (s[index] == '-') ? -1 : 1;
        index++;
    }
    
    int res = 0;
    int dig = 0;
    while(index < s.size()){
        dig = s[index] - '0';
        if(dig < 0 || dig > 9){
            break;
        }
        else{
            if(dig < -1 * (INT_MIN - res * 10) && dig < (INT_MAX - res * 10)){
                res = res * 10 + neg * dig;
            }
            else{
                res = (neg == -1) ? INT_MIN : INT_MAX;
                break;
            }
        }
    }

    return res;
}