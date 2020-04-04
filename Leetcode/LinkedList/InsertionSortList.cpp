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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        ListNode* prev;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
            if (temp->val < prev->val) {
                if (temp->val < head->val) {
                    prev->next = temp->next;
                    temp->next = head;
                    head = temp;
                }
                else {
                    ListNode* temp2 = head;
                    ListNode* prev2;
                    while (temp2->val <= temp->val) {
                        prev2 = temp2;
                        temp2 = temp2->next;
                    }
                    prev->next = temp->next;
                    temp->next = temp2;
                    prev2 -> next = temp;
                }
            }
        }
        return head;
    }
};