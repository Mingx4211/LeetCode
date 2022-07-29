#include <bits/stdc++.h>

using namespace std;

class NumberContainers {
  private:
    unordered_map<int, int> mp;
    unordered_map<int, set<int>> idx;

  public:
    NumberContainers() {
    }

    void change(int index, int number) {
        if (mp.count(index)) {
            int ori_number = mp[index];
            idx[ori_number].erase(index);
        }
        mp[index] = number;
        idx[number].insert(index);
    }

    int find(int number) {
        if (idx.count(number) == 0 || idx[number].size() == 0) {
            return -1;
        } else {
            return *idx[number].begin();
        }
    }
};
