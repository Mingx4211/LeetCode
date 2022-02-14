#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long smallestNumber(long long num) {
        int sym = 1;
        sym = num > 0 ? 1 : -1;
        num = num * sym;
        vector<int> nums;
        while(num != 0){
            nums.push_back(num % 10);
            num /= 10;
        }
        sort(nums.begin(), nums.end());
        if(sym == -1){
            for(int i = nums.size() - 1; i > -1; i--){
                num *= 10;
                num += nums[i];
            }
            
        }else{
            int cnt = 0;
            while(nums[cnt] == 0){
                cnt++;
            }
            num += nums[cnt];
            for(int i = 0; i < cnt; i++){
                num *= 10;
            }
            for(int i = cnt + 1; i < nums.size(); i++){
                num *= 10;
                num += nums[i];
            }
        }
        return sym * num;
    }
};