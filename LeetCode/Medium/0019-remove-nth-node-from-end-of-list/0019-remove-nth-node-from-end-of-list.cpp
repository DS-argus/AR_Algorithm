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

        ListNode S;
        S.next = head;


        ListNode* q = S.next;
        // get length of linked list
        int l = 0;
        while(q != nullptr){
            l++;
            q = q->next;
        }

        ListNode* p = &S;

        for (int i = 0; i< l-n ; i++){
            p = p -> next;
        }

        ListNode* removedNode = p->next;

        if(removedNode == nullptr){
            return nullptr;
        }else{
            p->next = removedNode->next;
            return S.next;
        }
    }
};