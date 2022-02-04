#include<vector>
#include<queue>
using namespace std;

/*
 * @lc app=leetcode.cn id=1725 lang=cpp
 *
 * [1725] 可以形成最大正方形的矩形数目
 */

// @lc code=start
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max_w = 0;
        int res = 0;
        for(auto &a : rectangles){
            int temp = min(a[0], a[1]);
            if(temp > max_w){
                max_w = min(a[0], a[1]);
                res = 1;
            }else if(temp == max_w){
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

