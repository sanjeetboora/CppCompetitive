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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return head;
        }
        ListNode* temp =  head;
        ListNode* prev;
        while (temp && temp->val == val) {
            temp = temp->next;
        }
        head = temp;
        while (temp) {
            prev =  temp;
            temp =  temp->next;
            if (temp && temp->val == val) {
                prev->next = temp->next;
                temp = prev;
            }
        }
        return head;

    }
};