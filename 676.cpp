#include <bits/stdc++.h>

using namespace std;

struct Node {
    unordered_map<char, Node *> children;
};

class MagicDictionary {
  public:
    Node *root;
    MagicDictionary() {
        root = new Node();
    }

    void buildDict(vector<string> dictionary) {
        for (auto s : dictionary) {
            Node *temp = root;
            for (auto c : s) {
                if (temp->children.count(c) == 0) {
                    temp->children[c] = new Node();
                }
                temp = temp->children[c];
            }
            temp->children['#'] = nullptr;
        }
    }

    bool find(string s, int i, Node *root, int time) {
        if (i == s.length()) {
            if (time == 0 && root->children.count('#') != 0) {
                return true;
            } else {
                return false;
            }
        }
        if (time == 1) {
            for (auto [c, node] : root->children) {
                if (c != s[i] && c != '#') {
                    if (find(s, i + 1, node, 0)) {
                        return true;
                    }
                }
            }
        }

        if (root->children.count(s[i]) != 0) {
            if (find(s, i + 1, root->children[s[i]], time)) {
                return true;
            }
        }

        return false;
    }

    bool search(string searchWord) {
        return find(searchWord, 0, root, 1);
    }
};

int main() {
    MagicDictionary *m = new MagicDictionary;
    m->buildDict({"hello", "leetcode"});
    m->search("hello");
    m->search("hhllo");
    m->search("hell");
    m->search("leetcoded");
    return 0;
}