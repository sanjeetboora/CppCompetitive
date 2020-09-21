//https://leetcode.com/problems/merge-two-sorted-lists/

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        while (l1 != NULL and l2 != NULL) {
            if (l1->val <= l2->val) {
                temp-> next = l1;
                l1 = l1->next;

            }
            else {
                temp-> next = l2;
                l2 = l2->next;

            }
            temp = temp->next;
        }

        if (l1 != NULL) {
            temp->next = l1;
        }
        if (l2 != NULL) {
            temp->next = l2;
        }
        return res->next;

    }
};