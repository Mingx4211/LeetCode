#include <bits/stdc++.h>
/*
 * @lc app=leetcode.cn id=1739 lang=cpp
 *
 * [1739] 放置盒子
 */

// @lc code=start
class Solution {
public:
    int minimumBoxes(int n) {
        int h = 0;
        int capcity = 0, next_capcity = 1;
        while(next_capcity <= n){
            capcity = next_capcity;
            h++;
            next_capcity += (h + 1) * (h + 2) / 2;
        }
        int i = 0;
        while(capcity < n){
            i++;
            capcity += i;
        }
        return (h * (h + 1)) / 2 + i;
    }
};

// class Solution {
// public:
//     int minimumBoxes(int n) {
//         int h = 1, s_base = 1, s_more = 0;
//         int capcity = 1;
//         while(capcity < n){
//             s_more++;
//             capcity += s_more;
//             if(s_more == h + 1){
//                 s_base += s_more;
//                 s_more = 0;
//                 h++;
//             }
//         }
//         return s_base + s_more;
//     }
// };
// @lc code=end

