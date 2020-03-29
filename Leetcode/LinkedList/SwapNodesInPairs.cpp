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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* prev = newHead;

        while (head != NULL && head->next != NULL) {
            ListNode* first = head;
            ListNode* sec = head->next;

            prev->next = sec;
            first->next = sec->next;
            sec->next = first;

            prev = first;
            head = first->next;

        }

        return newHead->next;
    }
};