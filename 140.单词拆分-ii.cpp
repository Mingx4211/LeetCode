#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
private:
    string s;
    set<string> words;
    vector<vector<int>> slices;
    vector<int> cur_slice;
    vector<string> res;
public:
    void dfs(int i){
        cur_slice.push_back(i);
        if(i == s.length() && i != 0){
            string temp;
            int start = 0;
            for(int i = 1; i < cur_slice.size(); i++){
                temp += s.substr(start, cur_slice[i] - start);
                if(i != cur_slice.size() - 1){
                    temp += " ";
                }
                start = cur_slice[i];
            }
            res.push_back(temp);
        }else{
            for(auto next : slices[i]){
                dfs(next);
            }
        }
        cur_slice.pop_back();
    }

    vector<string> wordBreak(string &_s, vector<string>& wordDict) {
        s = _s;
        int sl = s.length();
        for(auto word : wordDict){
            words.insert(word);
        }
        slices = vector<vector<int>> (sl);
        for(int i = 0; i < sl; i++){
            for(int j = i + 1; j <= sl; j++){
                string word = s.substr(i, j - i);
                if(words.count(word)){
                    slices[i].push_back(j);
                }
            }
        }
        dfs(0);
        return res;
    }
};
// @lc code=end

