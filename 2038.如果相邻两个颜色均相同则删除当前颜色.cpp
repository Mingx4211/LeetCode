#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=2038 lang=cpp
 *
 * [2038] 如果相邻两个颜色均相同则删除当前颜色
 */

// @lc code=start
class Solution {
public:
    bool winnerOfGame(string colors) {
        int sl = colors.length();
        int a = 0, b = 0;
        for(int i = 1; i < sl - 1; i++){
            if(colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
                a++;
            if(colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
                b++;
        }
        return a > b;
    }
};
// @lc code=end

