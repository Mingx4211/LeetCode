#include <bits/stdc++.h>

using namespace std;

///////
///////
//////          千万不要在auto循环中对容器进行添加/删除操作 !!!!!!!!!!!
///////
///////
///////

class RangeModule {
  public:
    map<int, int> mp;
    RangeModule() {
    }

    void addRange(int left, int right) {
        auto it = mp.begin();
        while (it != mp.end()) {
            if (it->first > right) {
                break;
            } else if (it->second < left) {
                it++;
            } else if (it->first <= left && it->second >= right) {
                return;
            } else if (it->first < left && it->second <= right) {
                left = it->first;
                it = mp.erase(it);
            } else if (it->first >= left) {
                right = max(it->second, right);
                it = mp.erase(it);
            }
        }
        mp[left] = right;
    }

    bool
    queryRange(int left, int right) {
        for (auto [s, e] : mp) {
            if (s > right) {
                break;
            } else if (s <= left && right <= e) {
                return true;
            }
        }
        return false;
    }

    void removeRange(int left, int right) {
        auto it = mp.begin();
        while (it != mp.end()) {
            if (it->first >= right) {
                break;
            } else if (it->second <= left) {
                it++;
            } else if (left <= it->first && it->second <= right) {
                it = mp.erase(it);
            } else if (it->first < left && right < it->second) {
                auto its = it->second;
                it->second = left;
                mp[right] = its;
                break;
            } else if (it->first < left && it->second <= right) {
                it->second = left;
                it++;
            } else if (it->first >= left && it->second > right) {
                auto itr = it->second;
                it = mp.erase(it);
                mp[right] = itr;
            }
        }
    }
};
