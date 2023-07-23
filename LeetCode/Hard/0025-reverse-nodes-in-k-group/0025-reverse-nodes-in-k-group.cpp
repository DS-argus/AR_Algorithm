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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1) return head;
        
        ListNode reversed(0, head);
        ListNode* p = &reversed;

        ListNode* check;
        ListNode* first;
        ListNode* last;

        ListNode* curr;
        ListNode* after1;
        ListNode* after2;
        
        ListNode* prevlast;

        while(p!=nullptr){
            
            prevlast = p;

            // 1. k개의 묶음이 만들어질 수 있는 지 확인 --> 만들어진다면 p가 last에서 멈춤
            for(int i = 0; i < k; i++){
                p = p->next;

                // k개의 묶음이 안만들어지면 바로 return
                if (p == nullptr) return reversed.next;

                if(i==0) first = p;
            }

            // 2. 묶음이 존재하니 k개를 reverse
            curr = first;             // 묶음의 첫번째
            after1 = curr->next;        // 묶음의 두번째
            after2 = curr->next->next;  // 묶음의 세번째

            for(int i = 0; i < k-1; i++){
                after1->next = curr;

                if(i==k-2) break;

                // 한칸씩 뒤로 이동
                curr = after1;
                after1 = after2;
                after2 = after1->next;
            }

            // 이전 묶음의 마지막을 reversed된 현재 묶음의 첫번째와 연결
            prevlast->next = p;

            // reversed 묶음과 다음 묶음을 연결
            first->next = after2;
            
            // p를 현재 묶음의 마지막으로
            p = first;
            
        }

        return reversed.next;

    }
};