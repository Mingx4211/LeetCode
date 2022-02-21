#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        int num_max = 0;
        vector<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
           mp[nums[i]].push_back(i);
           num_max = max(num_max, nums[i]); 
        }
    }
};