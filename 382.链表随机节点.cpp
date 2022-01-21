// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem382.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 */

// @lc code=start
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
// class Solution {
// public:
//     Solution(ListNode* head) {
//         while(head){
//             arr.emplace_back(head->val);
//             head = head->next;
//         }
//     }
    
//     int getRandom() {
//         return arr[rand() % arr.size()];                              
//     }
// private:
//     vector<int> arr;
// };

class Solution {
private:
    ListNode * head;
public:
    Solution(ListNode* _head) {
        head = _head;
    }
    
    int getRandom() {
        ListNode * temp = head;
        int res = 0, id = 0;
        while(temp){
            id++;
            if(rand() % id == 0)
                res = temp->val;
            temp = temp->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

