#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        stack<ListNode *> stk;
        ListNode *tmp = new ListNode(0, head);
        ListNode *curr = tmp;
        while (curr)
        {
            stk.push(curr);
            curr = curr->next;
        }
        for (int i = 0; i < n; ++i)
            stk.pop();
        ListNode *prev = stk.top();
        ListNode *tmp2 = prev->next;
        prev->next = prev->next->next;
        delete tmp2;
        ListNode *ans = tmp->next;
        delete tmp;
        return ans;
    }
};
// @lc code=end
