// @before-stub-for-debug-begin
#include <vector>
#include <string>
//#include "commoncppproblem10.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string &s, string &p) {
        vector<int> cur(s.length() + 1, 0);
        vector<int> temp(s.length() + 1, 0);
        cur[0] = 1;
        for (int i = 0; i < p.length(); i++){
            for(int i = 0; i <= s.length(); i++)
                temp[i] = 0;
            for(int j = 0; j <= s.length(); j++){
                if(i + 1 < p.length() && p[i + 1] == '*'){
                    if(cur[j]){
                        temp[j] = 1;
                        while(j < s.length() && (s[j] == p[i] or p[i] == '.') ){
                            temp[j + 1] = 1;
                            j++;
                        }
                    }
                }else  if( j > 0 && (s[j - 1] == p[i] or p[i] == '.') && cur[j - 1])
                    temp[j] = 1;
            }
            if(p[i + 1] == '*')
                i++;
            cur.swap(temp);
        }
        if(cur[s.length()])
            return true;
        else
            return false;
    }
};
// @lc code=end

