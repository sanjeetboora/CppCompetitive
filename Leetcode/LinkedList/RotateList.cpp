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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next ==NULL){
            return head;
        }
        ListNode* fast = head;
        ListNode* prev = head;
        ListNode* slow = head;
        int node = 0;
        
        while(fast){
            fast = fast->next;
            node++;
        }
        if(node <= k){
            k %=node;
        }

        node = 0;
        fast = head;
        while(fast && node<=k){
            prev=fast;
            fast = fast->next;
            node++;
        }
        if(fast){
            prev = fast;
        }
        
        while(fast){
            slow=slow->next;
            prev=fast;
            fast=fast->next;
        }
        prev->next = head;
        head = slow->next;
        slow->next = NULL;  
        
        return head;
    }
};