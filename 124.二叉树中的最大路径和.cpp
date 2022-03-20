// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem124.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int max_sum = INT_MIN;
public:
    void dfs(TreeNode* root){
        if(!root) return;
        
        dfs(root->left);
        dfs(root->right);
        int l_val = root->left ? root->left->val : 0;
        int r_val = root->right ? root->right->val : 0;
        int max_l = l_val + root->val;
        int max_r = r_val + root->val;
        int new_val = max(max_l, max_r);
        max_sum = max(max_sum, l_val + root->val + r_val);
        root->val = new_val > 0 ? new_val : 0;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};
// @lc code=end

