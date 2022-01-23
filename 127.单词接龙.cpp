// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include "commoncppproblem127.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
    //Note: 先建图可以节省大量时间, 每一步循环都要调用diff 浪费时间
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        queue<string> q;
        for(auto s : wordList){
            mp[s] = -1;
        }
        if(!mp[endWord]) return 0;
        
        string crr_word = beginWord;
        q.push(crr_word);
        int crrl = 1;
        int res = 1;
        while(!q.empty()){
            for(int i = 0; i < crrl; i++){
                crr_word = q.front();
                q.pop();
                for(auto it = wordList.begin(); it != wordList.end(); ){
                    if(diff(*it, crr_word) == 1){
                        if(*it == endWord)
                            return res + 1;
                        q.push(*it);
                        mp[*it] = res + 1;
                        wordList.erase(it);
                    }else
                        it++;
                }
            }
            crrl = q.size();
            res += 1;
        }
        return 0;
    }

    int diff(string &a, string &b){
        int cnt = 0;
        if(a.length() != b.length())    return -1;
        else{
            for(int i = 0; i < a.length(); i++){
                if(a[i] != b[i])
                    cnt += 1;
            }
        }
        return cnt;
    }
};
// @lc code=end

