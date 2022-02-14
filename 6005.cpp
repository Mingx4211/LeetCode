#include <bits/stdc++.h>

using namespace std;

class Solution {
    typedef pair<int, int> pii;

public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        map<int, int> cnt1, cnt2;
        vector<pii> vec1, vec2;
        for (int i = 0; i < n; i++) {
            if (i & 1) cnt1[nums[i]]++;
            else cnt2[nums[i]]++;
        }
        for (auto it = cnt1.begin(); it != cnt1.end(); it++) vec1.push_back(pii(it->second, it->first));
        sort(vec1.begin(), vec1.end());
        for (auto it = cnt2.begin(); it != cnt2.end(); it++) vec2.push_back(pii(it->second, it->first));
        sort(vec2.begin(), vec2.end());

        auto it1 = vec1.rbegin(), it2 = vec2.rbegin();
        int ans = n;
        if (it1->second != it2->second) ans -= it1->first + it2->first;
        else {
            int x = (next(it1) == vec1.rend() ? 0 : next(it1)->first) + it2->first;
            int y = (next(it2) == vec2.rend() ? 0 : next(it2)->first) + it1->first;
            ans -= max(x, y);
        }
        return ans;
    }
};

int main(){
    vector<int> nums{4,4,4,4,3,4};
    Solution S;
    cout << S.minimumOperations(nums) << endl;
    return 0;
}