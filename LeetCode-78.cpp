#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //每一个元素都只有包含与不包含两种可能，故共有2^n种可能
        vector<vector<int>> res(1 << nums.size(), vector<int>());
        
        for(int i = 0; i < (1 << nums.size()); i++){
            for(int j = 0; j < nums.size(); j++){
                if(i & (1 << j)){ //对0-2^n, 其二进制表示中j位若为1,代表包含nums[j],反之则不包含
                    res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }
};