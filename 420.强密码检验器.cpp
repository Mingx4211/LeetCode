// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem420.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=420 lang=cpp
 *
 * [420] 强密码检验器
 */

// @lc code=start
class Solution {
public:
    int check1(string &password){
        int n = password.length();
        if(n < 6)
            return 6 - n;
        else if(n > 20)
            return n - 20;
        else
            return 0;
    }

    int check2(string &password){
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(auto c : password){
            if(c >= 'a' && c <= 'z')
                cnt1 = 1;
            if(c >= 'A' && c <= 'Z')
                cnt2 = 1;
            if(c >= '0' && c <= '9')
                cnt3 = 1;
        }

        return 3 - cnt1 - cnt2 - cnt3;
    }

    int check3(string& p, int del){
        vector<int> temp;
        int c = 1;
        for(int i = 1; i < p.length(); i++){
            if(p[i] == p[i - 1]){
                c++;
            }else{
                if(c >= 3){
                    temp.push_back(c);
                }
                c = 1;
            }
        }
        if(c >= 3) temp.push_back(c);
        int cnt = temp.size();

        for(int i = 0; i < temp.size() && del > 0; i++){
            if(temp[i] >= 3 && temp[i] % 3 == 0){
                temp[i] -= 1;
                if(temp[i] / 3 == 0) cnt--;
                del -= 1;
            }
        }

        for(int i = 0; i < temp.size() && del > 1; i++){
            if(temp[i] >= 3 && temp[i] % 3 == 1){
                temp[i] -= 2;
                if(temp[i] / 3 == 0) cnt--;
                del -= 2;
            }
        }

        int i = 0;
        while(del > 2 && cnt > 0){
            if(temp[i % temp.size()] >= 3 && temp[i % temp.size()] % 3 == 2){
                temp[i % temp.size()] -= 3;
                if(temp[i % temp.size()] / 3 == 0) cnt--;
                del -= 3;
            }
            i++;
        }

        int res = 0;
        for(int i = 0; i < temp.size(); i++){
            res += temp[i] / 3;
        }
        return res;
    }

    int strongPasswordChecker(string password) {
        int n = password.length();
        int c1 = 0, c2 = 0, c3 = 0;   //C1, C2, C3 对应操作1, 操作2, 操作3的步数
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        if(n < 6){
            return max(check1(password), check2(password));
        }else if(n <= 20){
            return max(check2(password), check3(password, 0));
        }else{
            return password.length() - 20 + max(check2(password), check3(password, password.length() - 20));
        }
    }
};
// @lc code=end

