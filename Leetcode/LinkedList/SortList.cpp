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
    ListNode* mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* l3;
        if (l1->val <= l2->val) {
            l3 = l1;
            l3->next = merge(l1->next, l2);
        }
        else {
            l3 = l2;
            l3->next = merge(l1, l2->next);
        }
        return l3;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* middle = mid(head);
        ListNode* temp = middle->next;
        middle->next = NULL;
        ListNode* a = sortList(head);
        ListNode* b = sortList(temp);
        a = merge(a, b);
        return a;
    }

};