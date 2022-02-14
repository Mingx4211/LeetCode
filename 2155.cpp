#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
       vector<int> index(nums.size() + 1, 0);
       for(int i = 0; i < nums.size(); i++){
           if(nums[i] == 1){
               index[0]++;
           }
       }
       for(int i = 0; i < nums.size(); i++){
           if(nums[i] == 0){
               index[i + 1] = index[i] + 1;
           }else{
               index[i + 1] = index[i] - 1;
           }
       }
       int max = 0;
       for(int i = 0; i < index.size(); i++){
           if(index[i] > max){
               max = index[i];
           }
       }
       vector<int> res;
       for(int i = 0; i < index.size(); i++){
           if(index[i] == max){
               res.push_back(i);
           }
       }
       return res;
    }
};