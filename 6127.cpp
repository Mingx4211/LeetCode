#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    long long countExcellentPairs(vector<int> &nums, int k) {
        long long res = 0;
        set<int> s;
        for (auto i : nums) {
            s.insert(i);
        }
        vector<int> mp(32);
        for (auto i : s) {
            mp[__popcount(i)]++;
        }

        for (int i = 0; i < 32; i++) {
            for (int j = max(0, k - i); j < 32; j++) {
                res += mp[i] * mp[j];
            }
        }
        return res;
    }
};

//根据位数分类 , 时间复杂度化为32 * n
// class Solution {
//   public:
//     long long countExcellentPairs(vector<int> &nums, int k) {
//         long long res = 0;
//         set<int> s;
//         for (auto i : nums) {
//             s.insert(i);
//         }
//         unordered_map<int, int> mp;
//         for (auto i : s) {
//             mp[i] = __popcount(i);
//         }

//         for (auto a : s) {
//             for (auto b : s) {
//                 if (mp[a] + mp[b] >= k) {
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// };