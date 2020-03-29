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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode((l1->val + l2->val) % 10) ;
        ListNode* temp = result;
        int carry = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 && l2 ) {
            int num = l1->val + l2->val + carry;
            carry = 0;
            temp->next = new ListNode(num % 10);
            carry += num / 10;
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }

        while (l1 != NULL) {
            int num = l1->val + carry;
            carry = 0;
            temp->next = new ListNode(num % 10);
            carry += num / 10;
            l1 = l1->next;
            temp = temp->next;
        }
        while (l2 != NULL) {
            int num = l2->val + carry;
            carry = 0;
            temp->next = new ListNode(num % 10);
            carry += num / 10;
            l2 = l2->next;
            temp = temp->next;
        }
        while (carry > 0) {
            temp->next = new ListNode(carry % 10);
            carry /= 10;
            temp = temp->next;
        }
        temp = NULL;
        return result;
    }
};