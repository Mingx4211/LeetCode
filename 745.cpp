#include <bits/stdc++.h>

using namespace std;

//维护两个字典树 //TLE

/* struct Node {
    char c;
    unordered_map<char, Node *> mp;
    vector<int> idx;
};

class WordFilter {
    Node *pre;
    Node *suf;

  public:
    WordFilter(vector<string> &words) {
        pre = new Node();
        suf = new Node();
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string &s = words[i];
            auto temp = pre;
            for (auto c : s) {
                if (temp->mp.count(c) == 0) {
                    temp->mp[c] = new Node();
                }
                temp = temp->mp[c];
                temp->idx.push_back(i);
            }
            int l = s.length();
            temp = suf;
            for (int j = l - 1; j >= 0; --j) {
                auto c = s[j];
                if (temp->mp.count(c) == 0) {
                    temp->mp[c] = new Node();
                }
                temp = temp->mp[c];
                temp->idx.push_back(i);
            }
        }
    }

    int f(string pref, string suff) {
        vector<int> p, s;
        auto temp = pre;
        for (auto c : pref) {
            if (!temp) {
                break;
            }
            temp = temp->mp[c];
        }
        if (temp) {
            p = temp->idx;
        }
        temp = suf;
        reverse(suff.begin(), suff.end());
        for (auto c : suff) {
            if (!temp) {
                break;
            }
            temp = temp->mp[c];
        }
        if (temp) {
            s = temp->idx;
        }

        int i = p.size() - 1, j = s.size() - 1;
        while (i >= 0 && j >= 0) {
            if (p[i] == s[j]) {
                return p[i];
            } else if (p[i] > s[j]) {
                i--;
            } else {
                j--;
            }
        }
        return -1;
    }
}; */

//讲vector的拷贝改为指针拷贝 / 省去拷贝vector的时间, 通过 77% t 41% m
// struct Node {
//     Node *mp[26];
//     vector<int> idx;
// };

// class WordFilter {
//     Node *pre;
//     Node *suf;

//   public:
//     WordFilter(vector<string> &words) {
//         pre = new Node();
//         suf = new Node();
//         int n = words.size();
//         for (int i = 0; i < n; i++) {
//             string &s = words[i];
//             auto temp = pre;
//             for (auto c : s) {
//                 if (!temp->mp[c - 'a']) {
//                     temp->mp[c - 'a'] = new Node();
//                 }
//                 temp = temp->mp[c - 'a'];
//                 temp->idx.push_back(i);
//             }
//             int l = s.length();
//             temp = suf;
//             for (int j = l - 1; j >= 0; --j) {
//                 auto c = s[j];
//                 if (!temp->mp[c - 'a']) {
//                     temp->mp[c - 'a'] = new Node();
//                 }
//                 temp = temp->mp[c - 'a'];
//                 temp->idx.push_back(i);
//             }
//         }
//     }

//     int f(string pref, string suff) {
//         vector<int> *pp, *ss;
//         auto temp = pre;
//         for (auto c : pref) {
//             if (!temp) {
//                 break;
//             }
//             temp = temp->mp[c - 'a'];
//         }
//         if (temp) {
//             pp = &(temp->idx);   //拷贝指针而不是vector 拷贝vector代价太大
//         }
//         temp = suf;
//         reverse(suff.begin(), suff.end());
//         for (auto c : suff) {
//             if (!temp) {
//                 break;
//             }
//             temp = temp->mp[c - 'a'];
//         }
//         if (temp) {
//             ss = &(temp->idx);
//         }
//         if (!pp || !ss)
//             return -1;
//         vector<int> &p = *pp, &s = *ss;
//         int i = p.size() - 1, j = s.size() - 1;
//         while (i >= 0 && j >= 0) {
//             if (p[i] == s[j]) {
//                 return p[i];
//             } else if (p[i] > s[j]) {
//                 i--;
//             } else {
//                 j--;
//             }
//         }
//         return -1;
//     }
// };

struct Trie {
    unordered_map<string, Trie *> children;
    int weight;
};

class WordFilter {
  private:
    Trie *trie;

  public:
    WordFilter(vector<string> &words) {
        trie = new Trie();
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            Trie *cur = trie;
            int m = word.size();
            for (int j = 0; j < m; j++) {
                Trie *tmp = cur;
                for (int k = j; k < m; k++) {
                    string key({word[k], '#'});
                    if (!tmp->children.count(key)) {
                        tmp->children[key] = new Trie();
                    }
                    tmp = tmp->children[key];
                    tmp->weight = i;
                }
                tmp = cur;
                for (int k = j; k < m; k++) {
                    string key({'#', word[m - k - 1]});
                    if (!tmp->children.count(key)) {
                        tmp->children[key] = new Trie();
                    }
                    tmp = tmp->children[key];
                    tmp->weight = i;
                }
                string key({word[j], word[m - j - 1]});
                if (!cur->children.count(key)) {
                    cur->children[key] = new Trie();
                }
                cur = cur->children[key];
                cur->weight = i;
            }
        }
    }

    int f(string pref, string suff) {
        Trie *cur = trie;
        int m = max(pref.size(), suff.size());
        for (int i = 0; i < m; i++) {
            char c1 = i < pref.size() ? pref[i] : '#';
            char c2 = i < suff.size() ? suff[suff.size() - 1 - i] : '#';
            string key({c1, c2});
            if (!cur->children.count(key)) {
                return -1;
            }
            cur = cur->children[key];
        }
        return cur->weight;
    }
};