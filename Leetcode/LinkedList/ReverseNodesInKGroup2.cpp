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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* kTail  = NULL;
        ListNode* newHead = NULL;
        ListNode* reverseHead = NULL;
        while (temp) {
            int nodes = 0;
            temp = head;
            while (temp && nodes < k) {
                temp = temp->next;
                nodes++;
            }

            if (nodes == k) {
                //reverse the k nodes
                ListNode* curr = head;
                ListNode* prev = NULL;
                ListNode* nextNode;

                while (nodes--) {
                    nextNode = curr ->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nextNode;
                }

                if (newHead == NULL) {
                    newHead = prev;
                }
                else {
                    reverseHead = prev;
                }
                if (kTail) {
                    kTail->next  = reverseHead;
                }

                kTail = head;
                head  = curr;
            }
            if (kTail) {
                kTail->next = head;
            }

        }
        return newHead;
    }
};