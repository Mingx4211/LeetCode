#include<vector>
#include<unordered_map>
#include<set>
#include<iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=2013 lang=cpp
 *
 * [2013] 检测正方形
 */

// @lc code=start
class DetectSquares {
public:
    unordered_map<int, set<int>> px;
    unordered_map<int, set<int>> py;
    int p[1001][1001];
    DetectSquares() {
        for(int i = 0; i < 1001; i++){
            for(int j = 0; j < 1001; j++){
                p[i][j] = 0;
            }
        }
    }
    
    void add(vector<int> point) {
        px[point[0]].insert(point[1]);
        py[point[1]].insert(point[0]);
        p[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;
        for(auto yy : px[x]){
            //cout << "YY : " << yy << endl;
            for(auto xx : py[y]){
                //cout << "XX : " << xx << endl;
                if(xx != x && yy != y && abs(xx - x) == abs(yy - y)){
                    for(auto i : px[xx]){
                        if(i == yy)
                            res += (p[x][yy] * p[xx][y] * p[xx][yy]);
                    }
                }
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end

int main(){
    DetectSquares test;
    test.add({3,10});
    test.add({11,2});
    test.add({3,2});
    test.add({11,10});
    test.add({14,8});
    test.add({11,2});
    test.add({11,10});
    test.count({11, 10});
    return 0;
}