// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>


using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
//官解树状数组
class NumArray {
private:
    vector<int> tree;
    vector<int> &nums;

    int lowBit(int x) {
        return x & -x;
    }

    void add(int index, int val) {
        while (index < tree.size()) {
            tree[index] += val;
            index += lowBit(index);
        }
    }

    int prefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= lowBit(index);
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) : tree(nums.size() + 1), nums(nums) {
        for (int i = 0; i < nums.size(); i++) {
            add(i + 1, nums[i]);
        }
    }
    //初始化可以优化为O logn
    NumArray(vector<int>& nums): tree(nums.size() + 1), nums(nums){
        for(int i = 0; i < nums.size(); i++){
            tree[i + 1] += nums[i];
            int n = i + 1 + lowBit(i + 1);
            if(n <= nums.size()) tree[n] += tree[i + 1];
        }
    }

    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/range-sum-query-mutable/solution/qu-yu-he-jian-suo-shu-zu-ke-xiu-gai-by-l-76xj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



class NumArray {
private:
    vector<int>& nums;
    vector<int> tree;

    int lowbit(int x){
        return x & -x;
    }

    int prefixSum(int i){
        if(i == 0) return 0;
        int res = 0;
        res += nums[i - 1] * (i + 1);
        while(i > 0){
            res -= tree[i];
            i -= lowbit(i);
        }
        return res;
    }
public:
    NumArray(vector<int>& nums) : nums(nums), tree(nums.size() + 1){
        tree[1] = nums[0];
        if(2 <= nums.size())tree[2] += nums[0];
        for(int i = 1; i < nums.size(); i++){
            int index = i + 1;
            int delta = nums[i] - nums[i - 1];
            tree[index] += delta * index;
            if(index + lowbit(index) <= nums.size())
                tree[index + lowbit(index)] += tree[index];
        }
    }

    void update(int index, int val){
        int delta1 = (val - nums[index]) * (index + 1);
        int delta2 = (nums[index] - val) * (index + 2);
        nums[index] = val;
        int i = index + 1;
        while(i <= nums.size()){
            tree[i] += delta1;
            i += lowbit(i);
        }
        i = index + 2;
        while(i <= nums.size()){
            tree[i] += delta2;
            i += lowbit(i);
        }
    }

    int sumRange(int left, int right){
        return prefixSum(right + 1) - prefixSum(left);
    }
};

// class NumArray {
// private:
//     vector<int> segmentTree;
//     int n;

//     void build(vector<int>& nums, int s, int e, int node){
//         if(s == e){
//             segmentTree[node] = nums[s];
//             return;
//         }
//         int m = (s + e) / 2;
//         build(nums, s, m, node * 2 + 1);
//         build(nums, m + 1, e, node * 2 + 2);
//         segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
//     }

//     void change(int i, int v, int node, int s, int e){
//         if(s == e){
//             segmentTree[node] = v;
//             return;
//         }
//         int m = (s + e) / 2;
//         if(i <= m){
//             change(i, v, node * 2 + 1, s, m);
//         }else{
//             change(i, v, node * 2 + 2, m + 1, e);
//         }
//         segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
//     }

//     int sum(int left, int right, int node, int s, int e){
//         if(s == left && right == e){
//             return segmentTree[node];
//         }
//         int m = (s + e) / 2;
//         if(right <= m){
//             return sum(left, right, node * 2 + 1, s, m);
//         }else if(left > m){
//             return sum(left, right, node * 2 + 2, m + 1, e);
//         }else{
//             return sum(left, m, node * 2 + 1, s, m) + sum(m + 1, right, node * 2 + 2, m + 1, e);
//         }
//     }
    
// public:
//     NumArray(vector<int>& nums) {
//         n = nums.size();
//         segmentTree = vector<int> (4 * n);
//         build(nums, 0, n - 1, 0);
//     }
    
//     void update(int index, int val) {
//         change(index, val, 0, 0, n - 1);
//     }
    
//     int sumRange(int left, int right) {
//         return sum(left, right, 0, 0, n - 1);
//     }
// };

// int main(){
//     vector<int> nums{1, 3, 5};
//     NumArray a(nums);
//     cout << a.sumRange(0, 2) << endl;
//     a.update(1, 2);
//     cout << a.sumRange(0, 2) << endl;
//     return 0;
// }

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

