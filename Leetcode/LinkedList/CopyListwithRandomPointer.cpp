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
        map<Node*, Node*> m;
        Node* temp = head;
        Node* result = new Node(0);
        Node* temp2 = result;
        while (temp) {
            Node* new_node = new Node(temp->val);
            m.insert(make_pair(temp, new_node));
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            temp2 ->next = m[temp];
            temp2->next->random = m[temp->random];
            temp2 = temp2->next;
            temp = temp->next;

        }
        return result->next;
    }
};