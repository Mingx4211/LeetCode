#include<string>
#include<vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=2047 lang=cpp
 *
 * [2047] 句子中的有效单词数
 */

// @lc code=start
class Solution {
public:
    string _s;
    int countValidWords(string &s) {
        _s = s;
       int sl = s.length();
       int start = -1;
       int res = 0;
       for(int i = 0; i < sl; i++){
            if(start == -1 && s[i] != ' ')
                start = i;
            if(start != -1 && s[i] == ' '){
                if(check(start, i))
                    res++;
                start = -1;
            }else if(start != -1 && i == sl - 1){
                if(check(start, i + 1))
                    res++;
                start = -1;
            }
        }
        return res;
    }
    bool check(int start, int end){
        int c = 0;
        for(int i = start; i < end; i++){
            if(_s[i] >= '0' && _s[i] <= '9')
                return false;
            else if(i != end - 1 && (_s[i] == '!' || _s[i] == '.' || _s[i] == ','))
                return false;
            else if(_s[i] == '-'){
                c++;
                if(i == start || i == end - 1)
                    return false;
                else if(_s[i + 1] == ',' || _s[i + 1] == '.' || _s[i + 1] == '!')
                    return false;
            }
        }
        if(c > 1)
            return false;
        else
            return true;
    }
};
// @lc code=end

