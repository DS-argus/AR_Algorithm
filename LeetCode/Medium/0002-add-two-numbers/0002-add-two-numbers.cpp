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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int up = 0;
        ListNode sum;
        ListNode* p = &sum;

        while(l1 != nullptr || l2 != nullptr){

            if (l1 == nullptr){
                ListNode* newNode = new ListNode((l2->val + up) % 10);
                p->next = newNode;
                up = (l2->val + up) / 10;

                p = p->next;    
                l2 = l2->next;

            }else if(l2 == nullptr){
                ListNode* newNode = new ListNode((l1->val + up) % 10);
                p->next = newNode;
                up = (l1->val + up) / 10;
                
                p = p->next;
                l1 = l1->next;

            }else{

                ListNode* newNode = new ListNode((l1->val + l2->val + up) % 10);
                p->next = newNode;
                up = (l1->val + l2->val + up) / 10;
                // cout << p->val << " " << up << endl;
                p = p->next;
                l1 = l1->next;
                l2 = l2->next;
            }
        }

        if (up != 0){
            ListNode* newNode = new ListNode(up);
            p->next = newNode;
        }

        return sum.next;

    }
};