// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "commoncppproblem385.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s[0] != '['){
            return NestedInteger(stoi(s));
        }

        stack<NestedInteger> st;
        int temp = INT_MAX;
        int sign = 1;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c == '['){
                st.push(NestedInteger());
            }else if(c == ']' || c ==','){
                if(temp != INT_MAX){
                    st.push(NestedInteger(temp * sign));
                    temp = INT_MAX;
                    sign = 1;
                }
                if(c == ']' && s[i - 1] == '[') continue;
                auto ni = st.top();
                st.pop();
                st.top().add(ni);
            }else{
                if(c == '-'){
                    sign = -1;
                }else{
                    if(temp == INT_MAX){
                        temp = c - '0';
                    }else{
                        temp = temp * 10 + (c - '0');
                    }
                }
            }
        }
        return st.top();
    }
};
// @lc code=end

