#include <bits/stdc++.h>

using namespace std;

class Solution {
    //栈模拟
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        st.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            while(st.size() > 0 && gcd(st[st.size() - 1], num) != 1){
                num *= st[st.size() - 1] / gcd(st[st.size() - 1], num);
                st.pop_back();
            }
            st.push_back(num);
        }
        return st;
    }
};