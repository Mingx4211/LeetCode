// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem744.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char c1, c2;
        c1 = letters[0], c2 = 'z' + 1;
        for(int i = 0; i < letters.size(); i++){
            if(letters[i] < c1){
                c1 = letters[i];
            }
            if(letters[i] > target && letters[i] < c2){
                c2 = letters[i];
            }
        }
        if(c2 <= 'z'){
            return c2;
        }else{
            return c1;
        }
    }
};
// @lc code=end

