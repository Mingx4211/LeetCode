// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem105.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int p, int i, int l){
        if(l == 0) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[p]);
        int pl = p + 1;
        int il = i;
        int ll = 0;
        for(int j = i; j < i + l; j++){
            if(inorder[j] == preorder[p]){
                ll = j - i;
                break;
            }
        }
        int pr = pl + ll;
        int ir = il + 1 + ll;
        int lr = l - 1 - ll;

        root->left = build(preorder, inorder, pl, il, ll);
        root->right = build(preorder, inorder, pr, ir, lr);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, preorder.size());
    }
};
// @lc code=end

