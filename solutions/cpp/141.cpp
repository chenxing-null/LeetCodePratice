// https://leetcode.cn/problems/linked-list-cycle/description/
/*
 User two pointers, slow and fast
 Both start at the head.
 In each step, slow moves one node forward, fast moves two node forword.
 If there is no cycle, fast will eventually reach null -> return false.
 IF there is a cycle, the fase pointer will evevtually "lap" the slow pointer inside the cycle -> they meet at the same node -> return true.
*/

/*
 Once both pointers enter the cycle, treat the cycle as a circular track.
 Relative speed: fast moves 1 step per unit time faster than slow.
 From slow's frame of reference, fast is simply closing in on it at 1 step per time.
 Snce the track is closed and the gap (in nodes) is finite, each step redoces that gap by 1.
 Therefore, after a finite number of steps, the gap becomes 0 -> they must meet.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};