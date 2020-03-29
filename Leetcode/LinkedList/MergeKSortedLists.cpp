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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                heap.push(make_pair(lists[i]->val, i));
            }
        }
        ListNode* result = new ListNode(0);
        ListNode* temp = result;

        while (!heap.empty()) {
            int topIdx = heap.top().second;
            temp->next = new ListNode(heap.top().first);
            lists[topIdx] = lists[topIdx]->next;
            temp = temp->next;

            heap.pop();
            if ( lists[topIdx]) {
                heap.push(make_pair(lists[topIdx]->val, topIdx));
            }
        }
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                temp = lists[i];
                temp = temp->next;
            }
        }
        return result->next;
    }
};