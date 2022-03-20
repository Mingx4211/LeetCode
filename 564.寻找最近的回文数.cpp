// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <cmath>
#include "commoncppproblem564.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=564 lang=cpp
 *
 * [564] 寻找最近的回文数
 */

// @lc code=start
class Solution {    //难在要考虑到各种情况(三种可能 + 99**99 和 10**01 特殊情况)
public:
    vector<long> getCandidates(const string& n) {
        int len = n.length();
        vector<long> candidates = {
            (long)pow(10, len - 1) - 1,
            (long)pow(10, len) + 1,
        };
        long selfPrefix = stol(n.substr(0, (len + 1) / 2));
        for (int i : {selfPrefix - 1, selfPrefix, selfPrefix + 1}) {
            string prefix = to_string(i);
            string candidate = prefix + string(prefix.rbegin() + (len & 1), prefix.rend());
            candidates.push_back(stol(candidate));
        }
        return candidates;
    }

    string nearestPalindromic(string n) {
        long selfNumber = stol(n), ans = -1;
        const vector<long>& candidates = getCandidates(n);
        for (auto& candidate : candidates) {
            if (candidate != selfNumber) {
                if (ans == -1 ||
                    abs(candidate - selfNumber) < abs(ans - selfNumber) ||
                    abs(candidate - selfNumber) == abs(ans - selfNumber) && candidate < ans) {
                    ans = candidate;
                }
            }
        }
        return to_string(ans);
    }
};

// @lc code=end

