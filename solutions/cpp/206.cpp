// https://leetcode.cn/problems/reverse-linked-list/description/
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

 /*
  1 -> 2 -> 3 -> 4 -> 5
  ↓
  5 -> 4 -> 3 -> 2 -> 1
  Because it's a singly linked list, we want the current node to eventually point to its previous node.
  After that, since the direction of 'next' changes, we need to always keep track of the next node.
  Including the current node, we need three pointer variables.
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};