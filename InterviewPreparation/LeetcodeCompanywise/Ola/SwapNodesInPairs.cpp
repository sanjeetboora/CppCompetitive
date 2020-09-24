//Swap Nodes in Pairs
//https://leetcode.com/problems/swap-nodes-in-pairs/


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
	ListNode* swapPairs(ListNode* head) {

		if (!head or !head->next) return head;

		ListNode* newHead = head->next;

		ListNode* temp = head;
		ListNode* last = NULL;
		while (temp and temp->next) {
			ListNode* f = temp;
			ListNode* s = temp->next;

			f->next = s->next;
			s->next = f;

			if (last) {
				last->next = s;
			}
			last = f;
			temp = last->next;
		}
		return newHead;
	}
};