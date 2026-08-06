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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *first = l1;
        ListNode *second = l2;
        // Find the longer linked list.
        while (first && second)
        {
            first = first->next;
            second = second->next;
        }
        ListNode *target = first ? l1 : l2;
        ListNode *dummy = first ? l1 : l2;
        ListNode *pre = nullptr;
        int carry = 0;
        while (l1 && l2)
        {
            int temp = l1->val + l2->val + carry;
            carry = temp / 10;
            target->val = temp % 10;
            pre = target;
            target = target->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (carry)
        {
            if (target)
            {
                int temp = target->val + carry;
                carry = temp / 10;
                target->val = temp % 10;
                pre = target;
                target = target->next;
            }
            else
            {
                target = pre;
                target->next = new ListNode(1);
                carry = false;
            }
        }
        return dummy;
    }
};