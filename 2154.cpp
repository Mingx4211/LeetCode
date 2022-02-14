#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> mp;
        int ratio = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % original == 0){
                if(i == 0){
                    mp[nums[i]] = -1;
                }else{
                    mp[nums[i]] = i;
                }
            }
        }
        while(true){
            if(mp[original * ratio] != 0){
                ratio *= 2;
            }else{
                break;
            }
        }
        return original * ratio;
    }
};