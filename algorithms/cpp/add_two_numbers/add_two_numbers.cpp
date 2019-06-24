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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result;
    ListNode** current = &result;
    int passdown{0};
    while(l1 != NULL || l2 != NULL || passdown != 0){
      int val1{0}, val2{0};
      if(l1 != NULL){
	val1 = l1->val;
	l1 = l1->next;
      };
      if(l2 != NULL){
	val2 = l2->val;
	l2 = l2->next;
      };
      int tmp = val1 + val2 + passdown;
      ListNode * ntmp = new ListNode(tmp%10);
      *current = ntmp;
      passdown = tmp/10;
      *current = ntmp;
      current = (&ntmp->next);
    }
    return result;
  }
};
