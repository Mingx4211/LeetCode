// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem32.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
};

// @lc code=end


//栈模拟
// class Solution {
// public:
//     int longestValidParentheses(string &s) {
//         stack<int> st;
//         vector<bool> mark(s.length(), 0);
//         for(int i = 0; i < s.length(); i++){
//             if(s[i] == '('){
//                 st.push(i);
//             }else{
//                 if(st.empty()){
//                     mark[i] = 1;
//                 }else{
//                     st.pop();
//                 }
//             }
//         }
//         while(!st.empty()){
//             mark[st.top()] = 1;
//             st.pop();
//         }

//         int len = 0, max_len = 0;
//         for(int i = 0; i < s.length(); i++){
//             if(mark[i]){
//                 if(len > max_len){
//                     max_len = len;
//                 }
//                 len = 0;
//             }else{
//                 len++;
//             }
//         }

//         return max(len, max_len);
//     }
// };