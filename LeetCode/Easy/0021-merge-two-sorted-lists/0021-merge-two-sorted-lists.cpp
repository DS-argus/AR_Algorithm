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

        while(list1 != nullptr || list2 != nullptr){

            if(list1 == nullptr){
                m->next = list2;
                break;
            }

            if(list2 == nullptr){
                m->next = list1;
                break;
            }

            if(list1->val >= list2->val){
                m->next = list2;
                list2 = list2->next;
            }else{
                m->next = list1;;
                list1 = list1->next;
            }      
                  
            m = m->next;
        }

        return mergedList.next;

    }
};