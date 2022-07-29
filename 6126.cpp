#include <bits/stdc++.h>

using namespace std;

struct Food {
    string name;
    string cuisine;
    int rating;

    bool operator<(const Food &f) const { //自定义小于运算符要加尾const, set调用时是对常对象引用调用运算符
        return rating < f.rating || (rating == f.rating && name > f.name);
    }
};

class FoodRatings {
  public:
    unordered_map<string, Food> mp;
    unordered_map<string, set<Food>> ctof;
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            mp[foods[i]] = {foods[i], cuisines[i], ratings[i]};
            ctof[cuisines[i]].insert({foods[i], cuisines[i], ratings[i]});
        }
    }

    void changeRating(string food, int newRating) {
        ctof[mp[food].cuisine].erase(mp[food]);
        mp[food].rating = newRating;
        ctof[mp[food].cuisine].insert(mp[food]);
    }

    string highestRated(string cuisine) {
        return (*--ctof[cuisine].end()).name;
    }
};