#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> &nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        res = res ^ (i + 1);
        res = res ^ nums[i];
    }

    return res;
}

int main() {
    vector<int> nums = {0, 1, 3, 4};
    cout << missingNumber(nums) << endl;
    return 0;
}