#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int count[21] = {};
        for(int i = 0; i < nums.size(); i++){
            count[nums[i] + 10] += 1;
        }
        int length = 1;
        for(int i = 0; i <= 20; i++)
            length *= (count[i] + 1);
        vector<vector<int>> res(length, vector<int>());
        int a = 1;
        for(int i = 0; i <= 20; i++){
            for(int j = 0; j < length; j++){
                int b = (j / a) % (count[i] + 1);
                for(int k = 0; k < b; k++)
                    res[j].push_back(i - 10);
            }
            a *= (count[i] + 1);
        }
        return res;
    }
};