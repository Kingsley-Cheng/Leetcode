/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *temp = dummyhead;
        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            ListNode *node1 = temp->next;
            ListNode *node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        ListNode *ans = dummyhead->next;
        delete dummyhead;
        return ans;
    }
};
// @lc code=end