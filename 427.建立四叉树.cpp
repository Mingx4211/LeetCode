// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem427.h"

using namespace std;
// @before-stub-for-debug-end

#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> pre;
    int n;

    Node* dfs(int xl, int xr, int yl, int yr){
        auto ret = new Node();
        if(xl == xr){
            ret->val = grid[xl][yl];
            ret->isLeaf = true;
            return ret;
        }
        if(pre[xr + 1][yr + 1] - pre[xr + 1][yl] - pre[xl][yr + 1] + pre[xl][yl] == 0){
            ret->val = 0;
            ret->isLeaf = true;
            return ret;
        }
        if(pre[xr + 1][yr + 1] - pre[xr + 1][yl] - pre[xl][yr + 1] + pre[xl][yl] == (xr - xl + 1) * (xr - xl + 1)){
            ret->val = 1;
            ret->isLeaf = true;
            return ret;
        }
        ret->isLeaf = false;
        ret->topLeft = dfs(xl, (xl + xr) / 2, yl, (yl + yr) / 2);
        ret->topRight = dfs(xl, (xl + xr) / 2, (yl + yr) / 2 + 1, yr);
        ret->bottomLeft = dfs((xl + xr) / 2 + 1, xr, yl, (yl + yr) / 2);
        ret->bottomRight = dfs((xl + xr) / 2 + 1, xr, (yl + yr) / 2 + 1, yr);
        return ret;
    }

    Node* construct(vector<vector<int>>& grid) {
        this->grid = grid;
        this->n = grid.size();
        this->pre = vector<vector<int>> (n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        return dfs(0, n - 1, 0, n - 1);
    }
};
// @lc code=end

