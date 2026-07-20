// https://leetcode.cn/problems/palindrome-linked-list/description/

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
 class Solution
 {
 public:
     bool isPalindrome(ListNode *head)
     {
          std::vector<int> linklist;
         ListNode *cur = head;
         while (cur)
         {
             linklist.push_back(cur->val);
             cur = cur->next;
         }
         int length = linklist.size();
         int left = 0, right = length - 1;
         while (left < right)
         {
             if (linklist[left] != linklist[right])
             {
                 return false;
             }
             left++;
             right--;
         }
         return true;
     }
 };
*/

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

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

    bool isPalindrome(ListNode *head)
    {
        ListNode *middle = middleNode(head);
        ListNode *endNode = reverseList(middle);
        ListNode *cur = head;
        while (endNode) // Since the first half is not disconnected, it suffices to judge the latter half of the chain.
        {
            if (cur->val != endNode->val)
            {
                return false;
            }
            cur = cur->next;
            endNode = endNode->next;
        }
        return true;
    }
};