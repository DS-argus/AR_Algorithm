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
        
        // 0. Sentinel 이용
        ListNode S(0, head);

        // 1. Linked list 길이 구하기
        ListNode* temp = head;
        int l = 0;
        while(temp != nullptr){
            l++;
            temp = temp->next;
        }

        // 2. 제거할 노드 찾기
        ListNode* p = &S;

        // 제거해야할 노드의 바로 이전 노드를 p로 저장
        for (int i = 0; i < l-n ; i++){
            p = p -> next;
        }

        // 3. 노드 제거
        p->next = p->next->next;
        
        return S.next;

    }
};