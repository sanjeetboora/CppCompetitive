// https://leetcode.com/problems/merge-k-sorted-lists/


//using priority Queue O(NlogK)
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
class Compare {
public:
    bool operator()(pair<ListNode*, int> x, pair<ListNode*, int>y) {
        return x.first->val > y.first->val;
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* res = new ListNode();
        ListNode* temp = res;

        priority_queue<pair<ListNode*, int>, vector<pair<ListNode*, int> >, Compare> pq;

        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                pq.push({lists[i], i});
            }
        }

        while (!pq.empty()) {
            pair<ListNode*, int> t = pq.top();
            pq.pop();
            temp->next = t.first;
            temp = temp->next;
            t.first = t.first->next;
            if (t.first != NULL) {
                pq.push({t.first, t.second});
            }
        }

        return res->next;

    }
};





/* Space Optimized */

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
class Compare {
public:
    bool operator()(ListNode* x, ListNode*y) {
        return x->val > y->val;
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* res = new ListNode();
        ListNode* temp = res;

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        while (!pq.empty()) {
            ListNode* t = pq.top();
            pq.pop();
            temp->next = t;
            temp = temp->next;
            t = t->next;
            if (t != NULL) {
                pq.push(t);
            }
        }

        return res->next;

    }
};

