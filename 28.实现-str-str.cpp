// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem28.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
private:
    vector<int> next;
    string needle;
public:
    int strStr(string haystack, string _needle) {
        needle = _needle;
        getNext(next, needle);
        int i, j , res;
        for(i = 0, j = 0; i < haystack.length() && j < needle.length(); ){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }else if(j > 0){
                j = next[j];
            }else{
                i++;
            }
        }
        if(j == needle.length())
            res = i - j;
        else
            res = -1;
        
        return res;
    }

    // void getNext(vector<int> &next, string pattern){
    //     int i = 0, j;
    //     next.emplace_back(-1);
    //     next.emplace_back(0);
    //     for(j = 2; j < pattern.length(); j++){
    //         if(pattern[j - 1] == pattern[i]){
    //             i++;
    //             next.emplace_back(i);
    //         }else if(i > 0){
    //             i = next[i];
    //             j--;
    //         }else{
    //             next.emplace_back(0);
    //         }
    //     }
    // }

    void getNext(vector<int> &next, string p){
        int j = 0, i = 2;
        next.emplace_back(-1);
        next.emplace_back(0);
        for(; i < p.length(); i++){
            while(j > 0 & p[j] != p[i - 1]){
                j = next[j];
            }
            if(p[j] == p[i - 1]){
                j++;
                next.emplace_back(j);
            }else{
                next.emplace_back(0);
            }
        }
    }
};
// @lc code=end

