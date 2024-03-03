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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        int len = 0;
        
        ListNode* temp = head;
        while (temp){
            temp = temp->next;
            len++;
        }
        
        int m = len - n;
        int i = 0;
        
        ListNode* temp2 = dummy;
        while (i < m){
            temp2 = temp2->next;
            i++;
        }

        ListNode* temp3 = temp2->next->next;
        temp2->next = temp3;

        return dummy->next;
        
    }
};