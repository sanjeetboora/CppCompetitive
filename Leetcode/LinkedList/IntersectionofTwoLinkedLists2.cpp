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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB ==  NULL) {
      return NULL;
    }

    ListNode *temp = headA;
    ListNode *temp2;
    ListNode *endA = headA;
    int len1 = 1, len2 = 1;

    while (temp->next != NULL) {
      temp = temp->next;
      len1++;
    }
    endA = temp;
    temp = headB;
    while (temp->next != NULL) {
      temp = temp->next;
      len2++;
    }
    if (endA != temp) {
      return NULL;
    }
    int diff = abs(len1 - len2);

    if (len1 > len2) {
      temp = headA;
      temp2 = headB;
    } else {
      temp2 = headA;
      temp = headB;
    }

    while (diff--) {
      temp = temp->next;
    }
    while (temp != temp2) {
      temp = temp->next;
      temp2 = temp2->next;
    }
    return temp;


  }
};