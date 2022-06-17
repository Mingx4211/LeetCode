#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> st;
        int pos = 0, il = input.length();
        int max_path = 0;
        while(pos < il){
            int level = 0;
            while(input[pos] == '\t' && pos < il){
                level++;
                pos++;
            }
            bool isFile = 0;
            int curlen = 0;
            while(input[pos] != '\n' && pos < il){
                if(input[pos] == '.'){
                    isFile = 1;
                }
                curlen++;
                pos++;
            }
            while(st.size() != level){
                st.pop();
            }
            int prepath = st.empty() ? 0 : st.top();
            if(isFile){
                max_path = max(max_path, prepath + curlen);
            }else{
                st.push(prepath + curlen + 1);
            }
            pos++;
        }
        return max_path;
    }
};
// @lc code=end

