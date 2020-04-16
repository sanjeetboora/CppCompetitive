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
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        int k = lists.size();
        ListNode* llHead = new ListNode(0);
        ListNode* ll = llHead;
        for (int i = 0; i < k; i++) {
            if (lists[i]) {
                pq.push(make_pair(lists[i]->val, i));
            }

        }

        while (!pq.empty()) {

            pair<int, int> ele = pq.top();
            pq.pop();
            //cout<<ele->val<<", ";
            ll->next = lists[ele.second];
            lists[ele.second] = lists[ele.second]->next;
            ll = ll->next;
            if ( lists[ele.second] != NULL) {
                pq.push(make_pair(lists[ele.second]->val, ele.second));
            }
        }
        return llHead->next;
    }
};