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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = head;

        while (temp->next) {
            prev = temp;
            while (temp->next && temp->val == temp->next->val) {
                temp = temp->next;
            }

            if (temp == NULL || temp->next == NULL) {
                prev->next = temp->next;
                return head;
            }

            prev->next = temp->next;
            temp = temp->next;
        }
        return head;
    }
};