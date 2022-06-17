// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem954.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int> arr){
        int n = arr.size();
        if(n == 0) return true;
        vector<int> a1, a2;
        a1.push_back(arr[0]);
        int a = 0;
        for(int i = 1; i < n; i++){
            if(a < a1.size() && arr[i] == 2 * a1[a]){
                a2.push_back(arr[i]);
                a++;
            }else{
                a1.push_back(arr[i]);
            }
        }
        return a1.size() == a2.size();
    }

    bool canReorderDoubled(vector<int>& arr) {
        vector<int> posi, neg;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] >= 0){
                posi.push_back(arr[i]);
            }else{
                neg.push_back(-arr[i]);
            }
        }
        sort(posi.begin(), posi.end());
        sort(neg.begin(), neg.end());
        return check(posi) && check(neg);
    }
};
// @lc code=end

