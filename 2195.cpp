#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        int count = 0;
        nums.insert(nums.begin(), 0);
        nums.push_back(INT_MAX);
        for(int i = 0; count < k; i++){
            int base = nums[i];
            long long add_count = min((nums[i+1] - nums[i] - 1 > 0 ? nums[i+1] - nums[i] - 1 : 0), k - count);
            res += base * add_count + add_count * (add_count + 1) / 2;
            count += add_count;
        }
        return res;
    }
};
