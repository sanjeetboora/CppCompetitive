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

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* nextNode;
        while (temp) {
            nextNode = temp->next;
            temp ->next = prev;
            prev = temp;
            temp = nextNode;
        }
        ListNode* list2 = prev;
        slow =  head;
        while (slow && list2) {
            ListNode* temp = slow->next;
            slow->next = list2;
            list2 = list2->next;
            slow->next->next = temp;
            slow =  slow->next->next;
        }

    }
};