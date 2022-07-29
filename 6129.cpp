#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    long long zeroFilledSubarray(vector<int> &nums) {
        long long res = 0;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            long long cnt = 0;
            while (i < n && nums[i] == 0) {
                cnt++;
                i++;
            }
            res += (cnt * (cnt + 1)) / 2;
            i++;
        }
        return res;
    }
};