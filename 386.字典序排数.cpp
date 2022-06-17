// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem386.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int num = 1;
        for(int i = 1; i <= n; i++){
            res[i] = num;
            if(num * 10 <= n){
                num *= 10;
            }else{
                if(num % 10 == 9 || num + 1 > n){
                    num /= 10;
                }
                num++;
            }
        }
        return res;
    }
};



// class Solution {         递归写法栈空间复杂度不为O(1)
// public:
//     int n;
//     vector<int> res;
//     int cur = 0;

//     void dfs(){
//         if(cur > n) return;
//         res.push_back(cur);
//         int temp_cur = cur;
//         for(int i = 0; i < 10; i++){
//             cur = temp_cur * 10 + i;
//             dfs();
//         }
//     }

//     vector<int> lexicalOrder(int n) {
//         this->n = n;
//         for(int i = 1; i < 10; i++){
//             cur = i;
//             dfs();
//         }
//         return res;
//     }
// };
// @lc code=end

