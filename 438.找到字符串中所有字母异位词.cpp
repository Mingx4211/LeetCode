// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem438.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int> &a, vector<int> &b){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string &s, string &p) {
        int sl = s.length(), pl = p.length();
        vector<int> res;
        if(pl > sl) return res;
        vector<int> pc(26, 0);
        for(auto c : p){
            pc[c - 'a'] += 1;
        }
        vector<int> sc(26, 0);
        for(int i = 0; i < pl; i++){
            sc[s[i] - 'a'] += 1;
        }
        for(int i = 0; i < sl - pl + 1; i++){
            if(check(pc, sc))
                res.push_back(i);
            sc[s[i] - 'a'] -= 1;
            if(i < sl - pl){
                sc[s[i + pl] - 'a'] += 1;
            }
        }
        return res;
    }
};
// @lc code=end

