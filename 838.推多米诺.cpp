// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem838.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */

// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        stack<int> st;
        for(int i = 0; i < dominoes.length(); i++){
            if(dominoes[i] == 'R'){
                if(st.empty()){
                    st.push(i);
                }else{
                    int l = st.top() + 1;
                    st.pop();
                    st.push(i);
                    for(; l < i; l++){
                        dominoes[l] = 'R';
                    }
                }
            }else if(dominoes[i] == 'L'){
                if(st.empty()){
                    for(int j = i - 1; j >= 0 && dominoes[j] == '.'; j--){
                        dominoes[j] = 'L';
                    }
                }else{
                    int l = st.top() + 1, r = i - 1;
                    st.pop();
                    for(; l < r; l++, r--){
                        dominoes[l] = 'R';
                        dominoes[r] = 'L';
                    }
                }
            }
        }
        while(!st.empty()){
            int l = st.top() + 1;
            st.pop();
            for(; l < dominoes.length() && dominoes[l] == '.'; l++){
                dominoes[l] = 'R';
            }
        }
        return dominoes;
    }
};
// @lc code=end

