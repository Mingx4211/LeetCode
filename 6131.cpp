#include <bits/stdc++.h>

using namespace std;

//正确做法

//我们考虑 “最难出现的 mm 长度序列” ，那么其最后的一个数字一定是相比于其他序列最晚出现的。那么如果要出现 m+1m+1 长度的，一定至少得在 mm 长度前序列的后面再出现一遍 1,2,...,k1,2,...,k 。想到这点我们的答案就呼之欲出了。要有对应长度的序列，我们必须一遍遍地出现 1,2,...,k1,2,...,k，而其出现的次数加一恰好就是我们的结果。

class Solution {
  public:
    int shortestSequence(vector<int> &rolls, int k) {
        int res = 0;
        set<int> s;
        for (auto i : rolls) {
            s.insert(i);
            if (s.size() == k) {
                res++;
                s.clear();
            }
        }
        return res + 1;
    }
};

// bfs dfs 都超时

class Solution {
  public:
    vector<int> rolls;
    int k, n;
    unordered_map<int, vector<int>> idx;
    int shortestSequence(vector<int> &rolls, int k) {
        this->rolls = rolls;
        this->k = k;
        this->n = rolls.size();
        for (int i = 0; i < n; i++) {
            idx[rolls[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        long long height = 0;
        while (true) {
            long long crrl = q.size();

            for (int i = 0; i < crrl; i++) {
                int s = q.front();
                q.pop();
                for (int r = 1; r <= k; r++) {
                    auto &idv = idx[r];
                    auto iter = lower_bound(idv.begin(), idv.end(), s);
                    if (iter != idv.end()) {
                        q.push(*iter + 1);
                    } else {
                        return height + 1;
                    }
                }
            }
            height++;
        }
    }
};

// class Solution {
//   public:
//     vector<int> rolls;
//     unordered_map<int, vector<int>> idx;
//     int k, n;
//     int dfs(int i) {
//         int min_height = INT_MAX;
//         for (int r = 1; r <= k; r++) {
//             auto &idv = idx[r];
//             auto iter = lower_bound(idv.begin(), idv.end(), i);
//             if (iter == idv.end()) {
//                 min_height = 0;
//                 return 0;
//             } else {
//                 min_height = min(min_height, dfs(*iter + 1) + 1);
//             }
//         }
//         return min_height;
//     }

//     int shortestSequence(vector<int> &rolls, int k) {
//         this->rolls = rolls;
//         this->k = k;
//         this->n = rolls.size();
//         for (int i = 0; i < n; i++) {
//             idx[rolls[i]].push_back(i);
//         }
//         return dfs(0) + 1;
//     }
// };