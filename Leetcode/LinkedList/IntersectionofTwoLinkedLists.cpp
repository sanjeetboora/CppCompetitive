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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB ==  NULL) {
            return NULL;
        }

        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        ListNode *endA = NULL;
        ListNode *endB = NULL;

        while (temp1 && temp2 && temp1 != temp2) {
            if (temp1->next == NULL) {
                endA = temp1;
            }
            if (temp2->next == NULL) {
                endB = temp2;
            }
            if (endA != NULL && endB != NULL && endA != endB) {
                return NULL;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
            if (temp1 == NULL) {
                temp1 = headB;
            }
            if (temp2 == NULL) {
                temp2 = headA;
            }

        }
        return temp1;
    }
};