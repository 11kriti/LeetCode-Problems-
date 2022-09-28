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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* newhead = head;
	
    while (n--) newhead = newhead->next;
	
    if (!newhead)
    {
        head = head->next;
        return head;
    }
	
    ListNode* cur = head;
	
    while (newhead->next)
    {
        cur = cur->next;
        newhead = newhead->next;
    }
	
    ListNode* temp = cur;
    temp = temp->next->next;
    cur->next = temp;
	
    return head;   
        
    }
};