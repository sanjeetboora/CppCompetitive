/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow == fast) {
            slow = head;
            fast = fast->next;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;

        }
        else {
            return NULL;
        }

    }
};