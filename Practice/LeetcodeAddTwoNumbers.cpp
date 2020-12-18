//https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* x = new ListNode(0);
        ListNode* y=x;
        int carry = 0;
        while(l1 and l2){
            int sum = l1->val + l2->val + carry;
            y->next = new ListNode(sum%10);
            carry = sum/10;
            y = y->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + carry;
            y->next  = new ListNode(sum%10);
            carry = sum/10;
            y = y->next;
            l1 = l1->next;
        }
        
         while(l2){
            int sum = l2->val + carry;
             y->next  = new ListNode(sum%10);
            carry = sum/10;
            y = y->next;
            l2 = l2->next;
        }
        while(carry){
            y->next  = new ListNode(carry%10);
            carry = carry/10;
            y = y->next;
        }
        return x->next;
        
    }
};
