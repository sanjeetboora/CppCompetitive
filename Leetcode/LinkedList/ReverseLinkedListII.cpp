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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int x = 1;
        ListNode* slow = head;
        ListNode* temp = NULL;
        ListNode* prev =  NULL;
        while (x < m) {
            temp = slow;
            prev = slow;
            slow = slow->next;
            x++;
        }

        while (x <= n) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
            x++;
        }

        if (m == 1) {
            head->next = slow;
            return prev;
        }
        temp->next->next = slow;
        temp->next = prev;

        return head;

    }
};