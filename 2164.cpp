#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> n1, n2;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                n2.push_back(nums[i]);
            }else{
                n1.push_back(nums[i]);
            }
        }
        sort(n2.begin(), n2.end());
        sort(n1.begin(), n1.end(), [](int i, int j){return i > j;});
        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                nums[i] = n2[a];
                a++;
            }else{
                nums[i] = n1[b];
                b++;
            }
        }
        return nums;
    }
};