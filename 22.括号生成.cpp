// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<iostream>
#include <set>
#include "commoncppproblem22.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
//DP的生成函数
//DP[n] 可以由 "(" + dp[p] + ")" + dp[q] 构建,其中 p + q = n - 1; p的取值范围为 [0 ~ n - 1]
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        dp[1] = {"()"};
        int q = 0;
        for(int i = 2; i <= n; i++){
            for(int p = 0; p <= i - 1; p++){
                q = i - 1 - p;
                for(int j = 0; j < dp[p].size(); j++){
                    for(int k = 0; k < dp[q].size(); k++){
                        dp[i].emplace_back("(" + dp[p][j] + ")" + dp[q][k]);
                    }
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end




//DFS 回溯 剪枝
// class Solution {
// public:
//     vector<string> res;
//     string temp;
//     int left, right;

//     void dfs(int i){
//         if(i == 0){
//             res.emplace_back(temp);
//         }else if(left == right){
//             temp[i - 1] = ')';
//             right--;
//             dfs(i - 1);
//             right++;
//         }else if(left > right){
//             if(right > 0){
//                 temp[i - 1] = ')';
//                 right--;
//                 dfs(i - 1);
//                 right++;
//             }
//             temp[i - 1] = '(';
//             left--;
//             dfs(i - 1);
//             left++;
//         }
//     }

//     vector<string> generateParenthesis(int n) {
//         temp = string(2 * n, ' ');
//         left = right = n;
//         dfs(2 * n);
//         return res;
//     }
// };


//DP Set去重
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         set<string> temp;
//         vector<string> res;
//         if(n == 1){
//             return {"()"};
//         }else{
//             for(auto a : generateParenthesis(n - 1)){
//                 for(int i = 0; i <= a.length(); i++){
//                     temp.emplace(a.substr(0, i) + "()" + a.substr(i, a.length() - i));
//                 }
//             }
//             for(auto a = temp.begin(); a != temp.end(); a++){
//                     res.emplace_back(*a);
//                 }
//             return res;
//         }
//     }
// };
