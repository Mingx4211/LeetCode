// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem589.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> res;
public:
    void dfs(Node* root){
        if(!root) return;
        res.push_back(root->val);
        for(auto node : root->children){
            dfs(node);
        }
    }
    vector<int> preorder(Node* root) {
        res = vector<int>();
        dfs(root);
        return res;
    }
};
// @lc code=end

