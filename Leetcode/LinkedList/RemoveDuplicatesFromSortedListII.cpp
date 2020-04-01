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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if( head == NULL || head->next == NULL){
            return head;
        }
        bool req = false;
        if(head->val == head->next->val){
            req = true;
        }
        ListNode* newHead = head;
        ListNode* prev = head;
        ListNode* curr = head;

        while(curr->next){
           
            if(curr->val == curr->next->val){
               ListNode* temp = curr->next;
                while(temp && curr->val == temp->val){
                    temp = temp->next;
                }
                if(req && newHead==curr){
                    newHead = temp;
                }
                if(temp){
                    prev ->next = temp;
                    curr = temp;
                }
                else{
                    prev ->next = temp;
                    return newHead;
                }
                
            }else{
                prev=curr;
                curr = curr->next;
            }
        }
        return newHead;
    }
};