/*
 * @lc app=leetcode.cn id=1716 lang=cpp
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start
class Solution {
public:
    int totalMoney(int n) {
        // int a = n / 7;
        // int b = 7 * (a * (a - 1) / 2);
        // int c = a * 28;
        // int d = n % 7;
        // int e = 0;
        // for(int i = 0; i < d; i++){
        //     e += a + 1 + i;
        // }
        // return b + c + e;
        int res = 0;
        int j = 0;
        for(int i = 1; i < n + 1; i++){
            int k = i - j * 7;
            res += j + k;
            if(k == 7)
                j++;
        }
        return res;
    }
};
// @lc code=end

