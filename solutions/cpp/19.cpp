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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        n--;
        ListNode* right = head;
        while (n--) {
            right = right -> next;
        }
        if (right -> next) {
            ListNode* left = head;
            ListNode* pre = nullptr;
            while (right -> next) {
                pre = left;
                left = left -> next;
                right = right -> next;
            }
            pre -> next = left -> next;
        } else {
            head = head -> next;
        }
        return head;
    }
};