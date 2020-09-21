//https://leetcode.com/problems/copy-list-with-random-pointer/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = NULL;
        if (!head) return newHead;

        Node *temp = head;

        while (temp) {
            Node* curr = new Node(temp->val);
            Node* nxt = temp->next;
            temp->next = curr;
            curr->next = nxt;
            temp = nxt;
        }
        temp = head;

        while (temp and temp->next) {
            if (temp->random == NULL) {
                temp->next->random = NULL;
            }
            else {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        temp = head;
        newHead = head->next;
        Node* c = head->next;
        while (c and c->next) {
            temp -> next = temp->next->next;
            c->next = c->next->next;
            temp = temp->next;
            c = c->next;
        }
        temp->next = NULL;

        return newHead;
    }
};















