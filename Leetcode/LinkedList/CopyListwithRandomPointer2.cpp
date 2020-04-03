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
        if (head == NULL) {
            return head;
        }
        Node* temp = head;
        Node* result;
        Node* newHead;
        while (temp) {
            Node* new_node = new Node(temp->val);

            new_node->next = temp->next;
            temp->next = new_node;
            temp = temp->next->next;
        }

        temp = head;
        while (temp) {
            temp->next->random = (temp->random) ? temp->random->next : NULL;
            temp = temp->next->next;
        }
        temp = head;
        result = head->next;
        newHead = head->next;
        while (temp) {
            temp->next = temp->next->next;
            result->next = (result->next) ? result->next->next : NULL;
            temp = temp->next;
            result = result->next;

        }

        return newHead;
    }
};