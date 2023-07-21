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
        
        ListNode* prevlast;
        ListNode* check;
        ListNode* first;

        ListNode* curr;
        ListNode* after1;
        ListNode* after2;
        
        ListNode* p = head;
        
        int n = 0;
        
        while(p!=nullptr){
            
            // 1. k개의 묶음이 만들어질 수 있는 지 확인
            check = p;

            for(int i = 1; i <= k; i++){

                // k개의 묶음이 안만들어지면 바로 return
                if (check == nullptr){
                    return head;  
                }

                // 나중에 사용하려고 묶음의 첫번째 저장
                if(i==1) first = check;
                
                // k번만큼 이동. 마지막에는 다음묶음의 첫번째 node 혹은 nullptr이 됨
                check = check->next;
            }

            // 묶음 개수(뒤에서 1이면 head연결해주려고)
            n++;

            // 2. 묶음이 존재하니 k개를 reverse
            curr = p;
            after1 = curr->next;
            after2 = curr->next->next; 

            for(int i = 1; i <= k-1; i++){
                after1->next = curr;

                if(i==k-1) break;

                curr = after1;
                after1 = after2;
                after2 = after1->next;

            }

            // 현재 revered 묶음에서 다음 묶음 연결
            first->next = check;

            // head 혹은 이전 묶음 마지막 node랑 연결
            if (n == 1){
                // 첫번째 묶음이면 head 연결
                head = after1;
            }else{
                // 두번째 이상의 묶음이면 이전 revered 묶음 마지막 노드랑 
                // 이번 reversed 묶음 첫번째 노드랑 연결
                prevlast->next = after1;
            }
            
            // 이전 k개 묶음에서 마지막 노드 기록. 다음 묶음의 첫번째랑 연결해주려고
            prevlast = first;

            // 이제 다음묶음의 시작점으로 이동
            p = check;
        }

        return head;


    }
};