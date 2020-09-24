// Reverse Nodes in k - Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

//Iterative


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
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* newhead = NULL;
		ListNode* temp = head;
		ListNode* reverseHead = NULL;
		ListNode* kTail = NULL;
		while (temp) {
			temp = head;
			int n = 0;

			while (n < k and temp) {
				temp = temp->next;
				n++;
			}

			if (n == k) {
				ListNode* curr = head;
				ListNode* prev = NULL;
				ListNode* nxt;
				while (n--) {
					nxt = curr->next;
					curr->next = prev;
					prev = curr;
					curr = nxt;
				}
				if (newhead == NULL) {
					newhead = prev;
				}
				else {
					reverseHead = prev;
				}

				if (kTail) {
					kTail->next = reverseHead;
				}
				kTail = head;
				head = curr;
			}
			if (kTail) {
				kTail->next = head;
			}
		}
		return newhead;

	}
};





// Recursive


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
	ListNode* reverse(ListNode* head, int k) {

		ListNode* nxt;
		ListNode* prev = head;
		ListNode* curr = head;

		while (k--) {
			nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}
		return prev;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {

		ListNode* temp = head;
		int num = 0;
		while (num < k and temp != NULL) {
			num++;
			temp = temp->next;
		}

		if (num == k) {
			ListNode* reverseHead = reverse(head, k);
			// cout<<reverseHead->val<<endl;
			head -> next = reverseKGroup(temp, k);
			return reverseHead;
		}
		return head;
	}
};







