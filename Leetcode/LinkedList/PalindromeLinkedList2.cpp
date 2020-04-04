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
    ListNode* ptr;
    bool checkPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        if (!checkPalindrome(head->next)) {
            return false;
        }
        if (head->val != ptr->val) {
            return false;
        }
        ptr = ptr->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ptr = head;
        return checkPalindrome(head);
    }
};