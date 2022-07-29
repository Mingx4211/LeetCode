#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
const int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

class Solution {
  public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int x = 0, y = 0;
        int dir_x = 0, dir_y = 1;
        while (head) {
            res[x][y] = head->val;
            head = head->next;
            int nx = x + dir_x, ny = y + dir_y;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || res[nx][ny] != -1) {
                for (int i = 0; i < 4; i++) {
                    nx = x + dir[i][0];
                    ny = y + dir[i][1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && res[nx][ny] == -1) {
                        dir_x = dir[i][0];
                        dir_y = dir[i][1];
                        break;
                    }
                }
            }

            x = x + dir_x, y = y + dir_y;
        }
        return res;
    }
};