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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode mergedList;
        ListNode* m = &mergedList;

        ListNode* p1 = list1;
        ListNode* p2 = list2;

        while(p1 != nullptr || p2 != nullptr){

            if(p1 == nullptr){
                m->next = p2;
                break;
            }

            if(p2 == nullptr){
                m->next = p1;
                break;
            }

            if(p1->val >= p2->val){
                m->next = p2;
                p2 = p2->next;
            }else{
                m->next = p1;
                p1 = p1->next;
            }            

            m = m->next;
        }

        return mergedList.next;
    }
};