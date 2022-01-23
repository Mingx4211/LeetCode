#include<string>

using namespace std;

/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 *
 * [1332] 删除回文子序列
 */

// @lc code=start
class Solution {
public:
    int removePalindromeSub(string &s) {
        int res = 1;
        for(int i = 0, j = s.length() - 1; i < j; i++, j--){
            if(s[i] != s[j])
                res = 2;
        }
        return res;
    }
};
// @lc code=end

